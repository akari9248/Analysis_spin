#pragma once
#include "TLorentzVector.h"
#include <TChain.h>
#include <TFile.h>
#include <TLorentzVector.h>
#include <algorithm>
#include <cassert>
#include <fstream>
#include <iostream>
#include <random>
#include <tuple>
#include <unordered_map>
#include <vector>
#include "Matching.cc"
#include "ParticleInfo.h"
#include <fastjet/ClusterSequence.hh>
#include <fastjet/PseudoJet.hh>
#include "fastjet/contrib/IFNPlugin.hh"
#include "TDatabasePDG.h"
#include "TParticlePDG.h"
class Matching;
using namespace fastjet;
using namespace fastjet::contrib;
using namespace std;
class JetBranch {
public:
  struct PlaneVariables {
    PseudoJet harder;
    PseudoJet softer;
    TLorentzVector harder_vect;
    TLorentzVector softer_vect;
    double theta;
    double deltaR;
    double z;
    double kt;
    TVector3 n;
    vector<PseudoJet> harder_constituents;
    vector<PseudoJet> softer_constituents;
    int harder_ntracks;
    int softer_ntracks;
    int harder_nparticles;
    int softer_nparticles;
    vector<ParticleInfo> harder_constituents_info;
    vector<ParticleInfo> softer_constituents_info;
    int softer_flav;
    int harder_flav;
    void GetVector(vector<ParticleInfo> particlesinfo) {
      harder_vect = JetBranch::PseudoJetToTLorentzVector(harder);
      softer_vect = JetBranch::PseudoJetToTLorentzVector(softer);
      GetPlaneVector();
      harder_ntracks = GetNtracks(harder_constituents,particlesinfo);
      softer_ntracks = GetNtracks(softer_constituents,particlesinfo);
      harder_nparticles = harder_constituents.size();
      softer_nparticles = softer_constituents.size();
      for(int i=0;i<harder_constituents.size();i++){
        auto particle = harder_constituents.at(i);
        harder_constituents_info.push_back(ParticleInfo(
            particlesinfo.at(particle.user_index()).pdgid,
            particlesinfo.at(particle.user_index()).charge, particle.pt(),
            particle.eta(), particle.phi(), particle.e()));
      }
      for(int i=0;i<softer_constituents.size();i++){
        auto particle = softer_constituents.at(i);
        softer_constituents_info.push_back(ParticleInfo(
            particlesinfo.at(particle.user_index()).pdgid,
            particlesinfo.at(particle.user_index()).charge, particle.pt(),
            particle.eta(), particle.phi(), particle.e()));
      }
    }
    void GetPlaneVector() {
      n = harder_vect.Vect().Cross(softer_vect.Vect());
    }
    
    bool isqq = false;
    bool isgg = false;
    TLorentzVector initJet;
  };
  struct twoplanes {
    JetBranch::PlaneVariables first;
    JetBranch::PlaneVariables second;
    double deltaPhi;
    double Q=0;
  };
  struct pseudothreeplanes {
    JetBranch::PlaneVariables first;
    JetBranch::PlaneVariables second;
    JetBranch::PlaneVariables third;
    double deltaPhi=-10;
    double deltaPhi2=-10;
    double Q = 0;
    bool ismatched = false;
    pseudothreeplanes() = default;
    pseudothreeplanes(const JetBranch::PlaneVariables& f, const JetBranch::PlaneVariables& s, const JetBranch::PlaneVariables& t,
                      double dPhi, double dPhi2, double q,bool _ismatched )
        : first(f), second(s), third(t), deltaPhi(dPhi), deltaPhi2(dPhi2), Q(q) ,ismatched(_ismatched){}
};

struct threeplanes {
    JetBranch::PlaneVariables first;
    JetBranch::PlaneVariables second;
    JetBranch::PlaneVariables third;
    double deltaPhi;
    double deltaPhi2;
    double Q = 0;
    pseudothreeplanes matchedthreeplanes;
    bool ismatched = false;
    threeplanes() = default;
    pseudothreeplanes Getpseudothreeplanes() const {
      double t_deltaPhi = deltaPhi ;
      double t_deltaPhi2 = deltaPhi2 ;
      if (second.softer_nparticles == 0 || second.harder_nparticles == 0)
        t_deltaPhi = -10;
      if (third.softer_nparticles == 0 || third.harder_nparticles == 0)
        t_deltaPhi2 = -10;
      return pseudothreeplanes(first, second, third, t_deltaPhi, t_deltaPhi2, Q,ismatched);
    }
};
  static double DeltaPhi(PlaneVariables plane1, PlaneVariables plane2) {
    if(plane1.harder_nparticles==0||plane1.softer_nparticles==0||
       plane2.harder_nparticles==0||plane2.softer_nparticles==0) return -10;
    TVector3 n1 = plane1.n;
    TVector3 n2 = plane2.n;
    n1 = n1.Unit();
    n2 = n2.Unit();
    double cos_angle = abs(n1.Dot(n2));
    if ((n1.Cross(n2)).Dot(plane2.harder_vect.Vect()) < 0) {
      cos_angle = -1.0 * cos_angle;
    }
    double angle_radians = TMath::ACos(cos_angle);
    return angle_radians;
  }
  
  static TLorentzVector PseudoJetToTLorentzVector(fastjet::PseudoJet &pj) {
    return TLorentzVector(pj.px(), pj.py(), pj.pz(), pj.e());
  }

  static twoplanes findPrimaryAndSecondaryJets(PseudoJet &j0,double z1cut,double z2cut,double kt1cut,double kt2cut,std::vector<ParticleInfo> particlesinfo,bool issecondsoft=true) {
    PseudoJet j1, j2, j3, j4,jinit;
    PlaneVariables maxPrimary = {
        PseudoJet(), PseudoJet(), TLorentzVector(), TLorentzVector(), 0.0, 0.0,
        0.0,         0.0,         TVector3()};
    PlaneVariables maxSecondary = {
        PseudoJet(), PseudoJet(), TLorentzVector(), TLorentzVector(), 0.0, 0.0,
        0.0,         0.0,         TVector3()};
    jinit = j0;    
    
    while (j0.has_parents(j1, j2)) {
      
      PseudoJet primaryHarder = (j1.modp() > j2.modp()) ? j1 : j2;
      PseudoJet primarySofter = (j1.modp() > j2.modp()) ? j2 : j1;
      double primaryTheta = primaryHarder.delta_phi_to(primarySofter);
      double primaryDeltaR = primaryHarder.delta_R(primarySofter);
      double primaryZ =
          primarySofter.modp() / (primarySofter.modp() + primaryHarder.modp());
      double primaryKt = primarySofter.modp() * primaryDeltaR;
      // double primaryKt = primarySofter.modp() * sin(primaryTheta);
      // Update maxPrimary if this kt is larger
      if (primaryKt > maxPrimary.kt && primaryZ>z1cut && primaryKt<kt1cut) {
        maxPrimary = {primaryHarder,
                      primarySofter,
                      PseudoJetToTLorentzVector(primaryHarder),
                      PseudoJetToTLorentzVector(primarySofter),
                      primaryTheta,
                      primaryDeltaR,
                      primaryZ,
                      primaryKt,
                      TVector3(),
                      primaryHarder.constituents(),
                      primarySofter.constituents()};
        maxSecondary = {
                        PseudoJet(), PseudoJet(), TLorentzVector(), TLorentzVector(), 0.0, 0.0,
                        0.0,         0.0,         TVector3()};
        PseudoJet secondplanejet = primaryHarder;        
        if (issecondsoft) secondplanejet = primarySofter; 
        while (secondplanejet.has_parents(j3, j4)) {
          PseudoJet secondaryHarder = (j3.modp() > j4.modp()) ? j3 : j4;
          PseudoJet secondarySofter = (j3.modp() > j4.modp()) ? j4 : j3;
          double secondaryTheta = secondaryHarder.delta_phi_to(secondarySofter);
          double secondaryDeltaR =
              secondaryHarder.delta_R(secondarySofter);
          double secondaryZ = secondarySofter.modp() /
                              (secondarySofter.modp() + secondaryHarder.modp());
          double secondaryKt = secondarySofter.modp() * secondaryDeltaR;
          if (secondaryKt > maxSecondary.kt && secondaryZ>z2cut && secondaryKt>kt2cut) {
            maxSecondary = {secondaryHarder,
                            secondarySofter,
                            PseudoJetToTLorentzVector(secondaryHarder),
                            PseudoJetToTLorentzVector(secondarySofter),
                            secondaryTheta,
                            secondaryDeltaR,
                            secondaryZ,
                            secondaryKt,
                            TVector3(),
                            secondaryHarder.constituents(),
                            secondarySofter.constituents()};
          }
          secondplanejet = secondaryHarder;
        }
      }
      
      j0 = primaryHarder; // Move to the next iteration with the harder subjet
    }
    
    /// Add plane vector
    maxPrimary.GetVector(particlesinfo);
    maxSecondary.GetVector(particlesinfo);
    twoplanes twoplanes_out;
    maxPrimary.initJet.SetPtEtaPhiE(jinit.pt(),jinit.eta(),jinit.phi(),jinit.e());
    maxSecondary.initJet.SetPtEtaPhiE(jinit.pt(),jinit.eta(),jinit.phi(),jinit.e());
    twoplanes_out.first = maxPrimary;
    twoplanes_out.second = maxSecondary;
    twoplanes_out.deltaPhi = JetBranch::DeltaPhi(maxPrimary, maxSecondary);
    return twoplanes_out;
  }
  static threeplanes findPrimarySecondaryAndThirdaryJets(PseudoJet &j0,double z1cut,double z2cut,double kt1cut,double kt2cut,std::vector<ParticleInfo> particlesinfo,bool issecondsoft=true) {
    PseudoJet j1, j2, j3, j4,jinit;
    PlaneVariables maxPrimary = {
        PseudoJet(), PseudoJet(), TLorentzVector(), TLorentzVector(), 0.0, 0.0,
        0.0,         0.0,         TVector3()};
    PlaneVariables maxSecondary = {
        PseudoJet(), PseudoJet(), TLorentzVector(), TLorentzVector(), 0.0, 0.0,
        0.0,         0.0,         TVector3()};
    PlaneVariables maxThirdary = {
        PseudoJet(), PseudoJet(), TLorentzVector(), TLorentzVector(), 0.0, 0.0,
        0.0,         0.0,         TVector3()};
    jinit = j0;    
    
    while (j0.has_parents(j1, j2)) {
      PseudoJet primaryHarder = (j1.modp() > j2.modp()) ? j1 : j2;
      PseudoJet primarySofter = (j1.modp() > j2.modp()) ? j2 : j1;
      double primaryTheta = primaryHarder.delta_phi_to(primarySofter);
      double primaryDeltaR = primaryHarder.delta_R(primarySofter);
      double primaryZ =
          primarySofter.modp() / (primarySofter.modp() + primaryHarder.modp());
      double primaryKt = primarySofter.modp() * primaryDeltaR;
      // double primaryKt = primarySofter.modp() * sin(primaryTheta);
      // Update maxPrimary if this kt is larger

      if (primaryKt > maxPrimary.kt && primaryZ>z1cut && primaryKt<kt1cut) {
        maxPrimary = {primaryHarder,
                      primarySofter,
                      PseudoJetToTLorentzVector(primaryHarder),
                      PseudoJetToTLorentzVector(primarySofter),
                      primaryTheta,
                      primaryDeltaR,
                      primaryZ,
                      primaryKt,
                      TVector3(),
                      primaryHarder.constituents(),
                      primarySofter.constituents()};
        maxSecondary = {
                        PseudoJet(), PseudoJet(), TLorentzVector(), TLorentzVector(), 0.0, 0.0,
                        0.0,         0.0,         TVector3()};
        maxThirdary = {
                        PseudoJet(), PseudoJet(), TLorentzVector(), TLorentzVector(), 0.0, 0.0,
                        0.0,         0.0,         TVector3()};
        PseudoJet secondplanejet = primaryHarder;    
        PseudoJet thirdplanejet = primaryHarder;      
        if (issecondsoft) secondplanejet = primarySofter; 
        while (secondplanejet.has_parents(j3, j4)) {
          PseudoJet secondaryHarder = (j3.modp() > j4.modp()) ? j3 : j4;
          PseudoJet secondarySofter = (j3.modp() > j4.modp()) ? j4 : j3;
          double secondaryTheta = secondaryHarder.delta_phi_to(secondarySofter);
          double secondaryDeltaR =
              secondaryHarder.delta_R(secondarySofter);
          double secondaryZ = secondarySofter.modp() /
                              (secondarySofter.modp() + secondaryHarder.modp());
          double secondaryKt = secondarySofter.modp() * secondaryDeltaR;
          if (secondaryKt > maxSecondary.kt && secondaryZ>z2cut && secondaryKt>kt2cut) {
            maxSecondary = {secondaryHarder,
                            secondarySofter,
                            PseudoJetToTLorentzVector(secondaryHarder),
                            PseudoJetToTLorentzVector(secondarySofter),
                            secondaryTheta,
                            secondaryDeltaR,
                            secondaryZ,
                            secondaryKt,
                            TVector3(),
                            secondaryHarder.constituents(),
                            secondarySofter.constituents()};
          }
          secondplanejet = secondaryHarder;
        }
        while (thirdplanejet.has_parents(j3, j4)) {
          PseudoJet thirdaryHarder = (j3.modp() > j4.modp()) ? j3 : j4;
          PseudoJet thirdarySofter = (j3.modp() > j4.modp()) ? j4 : j3;
          double thirdaryTheta = thirdaryHarder.delta_phi_to(thirdarySofter);
          double thirdaryDeltaR =
              thirdaryHarder.delta_R(thirdarySofter);
          double thirdaryZ = thirdarySofter.modp() /
                              (thirdarySofter.modp() + thirdaryHarder.modp());
          double thirdaryKt = thirdarySofter.modp() * thirdaryDeltaR;
          if (thirdaryKt > maxThirdary.kt && thirdaryZ>z2cut && thirdaryKt>kt2cut) {
            maxThirdary = {thirdaryHarder,
                            thirdarySofter,
                            PseudoJetToTLorentzVector(thirdaryHarder),
                            PseudoJetToTLorentzVector(thirdarySofter),
                            thirdaryTheta,
                            thirdaryDeltaR,
                            thirdaryZ,
                            thirdaryKt,
                            TVector3(),
                            thirdaryHarder.constituents(),
                            thirdarySofter.constituents()};
          }
          thirdplanejet = thirdaryHarder;
        }
      }
      
      
      j0 = primaryHarder; // Move to the next iteration with the harder subjet
    }
    
    /// Add plane vector
    maxPrimary.GetVector(particlesinfo);
    maxSecondary.GetVector(particlesinfo);
    maxThirdary.GetVector(particlesinfo);
    threeplanes threeplanes_out;
    maxPrimary.initJet.SetPtEtaPhiE(jinit.pt(),jinit.eta(),jinit.phi(),jinit.e());
    maxSecondary.initJet.SetPtEtaPhiE(jinit.pt(),jinit.eta(),jinit.phi(),jinit.e());
    maxThirdary.initJet.SetPtEtaPhiE(jinit.pt(),jinit.eta(),jinit.phi(),jinit.e());
    threeplanes_out.first = maxPrimary;
    threeplanes_out.second = maxSecondary;
    threeplanes_out.third = maxThirdary;
    threeplanes_out.deltaPhi = JetBranch::DeltaPhi(maxPrimary, maxSecondary);
    threeplanes_out.deltaPhi2 = JetBranch::DeltaPhi(maxPrimary, maxThirdary);
    return threeplanes_out;
  }
  static int netflavour(PseudoJet j,vector<ParticleInfo> particlesinfo,double minflavourpt=0) {
    vector<int> pdgids;
    if(j==0) return -1;
    auto particles = j.constituents();
    for (int i = 0; i < particles.size(); i++) {
      PseudoJet particle = particles.at(i);
      if(particle.pt()<minflavourpt) continue;
      pdgids.push_back(particlesinfo.at(particle.user_index()).pdgid);
    }
    pdgids.erase(std::remove(pdgids.begin(), pdgids.end(), 21), pdgids.end());
    std::unordered_map<int, int> count_map;
    for (int num : pdgids) {
      count_map[num]++;
    }

    pdgids.clear();
    for (auto &element : count_map) {
      int num = element.first;
      int count = element.second;
      if (count > 0) {
        int opposite = -num;
        if (count_map.count(opposite) && count_map[opposite] > 0) {
          int minCount = std::min(count, count_map[opposite]);
          count_map[num] -= minCount;
          count_map[opposite] -= minCount;
        }

        // 将剩余的未抵消的元素添加回vec中
        while (count_map[num] > 0) {
          pdgids.push_back(num);
          count_map[num]--;
        }
      }
    }

    if (pdgids.size() == 0)
      return 21;
    if (pdgids.size() == 1)
      return pdgids.at(0);
    if (pdgids.size() > 1)
      return 0;
    return 0;
  }
  static bool isqq(int pdgid1, int pdgid2,int pdgid3=-1) {
    if (pdgid1 != 0 && pdgid1 + pdgid2 == 0 && pdgid3==-1)
      return true;
    if (pdgid1 != 0 && pdgid1 + pdgid2 == 0 && pdgid3==21)
      return true;
    return false;
  }
  static bool isgg(int pdgid1, int pdgid2,int pdgid3=-1) {
    if (pdgid1 == 21 && pdgid2 == 21 && pdgid3==-1)
      return true;
    if (pdgid1 == 21 && pdgid2 == 21 && pdgid3==21)
      return true;
    return false;
  }
  static bool matchPlanes(JetBranch::PlaneVariables &src_plane,
                          JetBranch::PlaneVariables &dst_plane,double drcutweight=1) {

    std::vector<TLorentzVector> src = {src_plane.harder_vect,
                                       src_plane.softer_vect};
    std::vector<TLorentzVector> dst = {dst_plane.harder_vect,
                                       dst_plane.softer_vect};
  
    double drcut = src[0].DeltaR(src[1])*drcutweight;
    // match_result[src] = dst
    auto match_result = Matching::matchJet(src, dst, drcut);
    bool allmatch = std::all_of(match_result.begin(), match_result.end(),
                                [](int i) { return i > -1; });
    
    if (allmatch) {
      src_plane.isqq = dst_plane.isqq;
      src_plane.isgg = dst_plane.isgg;
      src_plane.softer_flav = dst_plane.softer_flav;
      src_plane.harder_flav = dst_plane.harder_flav;
    }
    return allmatch;
  }

  static vector<std::vector<int>>
  matchPlanes(vector<std::vector<JetBranch::twoplanes>> &src_twoplanes,
              vector<std::vector<JetBranch::twoplanes>> &dst_twoplanes,
              TString opt = "second",double drcutweight=1) {
    std::vector<JetBranch::PlaneVariables> src_plane, dst_plane;
    vector<std::vector<int>> match_results;
    if (opt.EqualTo("second")) {
      for (size_t i = 0; i < src_twoplanes.size(); i++) {
        std::vector<int> match_results0;
        for(size_t j = 0; j < src_twoplanes.at(i).size(); j++){
          match_results0.push_back(-1);
          src_twoplanes[i][j].second.isgg=false;
          src_twoplanes[i][j].second.isqq=false;
          src_twoplanes[i][j].first.isgg=false;
          src_twoplanes[i][j].first.isqq=false;
          for(size_t k = 0; k < dst_twoplanes.at(i).size(); k++){ 
            if(matchPlanes(src_twoplanes[i][j].second,dst_twoplanes[i][k].second,drcutweight)){
              match_results0[j]=k;
            }
          }
        }
        match_results.push_back(match_results0);
      }
    }
    if (opt.EqualTo("full")) {
      for (size_t i = 0; i < src_twoplanes.size(); i++) {
        std::vector<int> match_results0;
        for(size_t j = 0; j < src_twoplanes.at(i).size(); j++){
          match_results0.push_back(-1);
          for(size_t k = 0; k < dst_twoplanes.at(i).size(); k++){
            if(matchPlanes(src_twoplanes[i][j].first,dst_twoplanes[i][k].first,drcutweight)&&matchPlanes(src_twoplanes[i][j].second,dst_twoplanes[i][k].second,drcutweight)){
              match_results0[j]=k;
            }
          }
        }
        match_results.push_back(match_results0);
      }
    }
    return match_results;
  }
  static std::pair<std::vector<std::vector<int>>, std::vector<std::vector<int>>>
  matchPlanes(vector<std::vector<JetBranch::threeplanes>> &src_threeplanes,
              vector<std::vector<JetBranch::threeplanes>> &dst_threeplanes,
              TString opt = "second",double drcutweight=1) {
    std::vector<JetBranch::PlaneVariables> src_plane, dst_plane;
    vector<std::vector<int>> match_results2;
    vector<std::vector<int>> match_results3;
    if (opt.EqualTo("second")) {
      for (size_t i = 0; i < src_threeplanes.size(); i++) {
        std::vector<int> match_results02;
        std::vector<int> match_results03;
        for(size_t j = 0; j < src_threeplanes.at(i).size(); j++){
          match_results02.push_back(-1);
          match_results03.push_back(-1);
          src_threeplanes[i][j].first.isgg=false;
          src_threeplanes[i][j].first.isqq=false;
          src_threeplanes[i][j].second.isgg=false;
          src_threeplanes[i][j].second.isqq=false;
          src_threeplanes[i][j].third.isgg=false;
          src_threeplanes[i][j].third.isqq=false;

           src_threeplanes[i][j].first.harder_flav=0;
          src_threeplanes[i][j].first.softer_flav=0;
          src_threeplanes[i][j].second.harder_flav=0;
          src_threeplanes[i][j].second.softer_flav=0;
          src_threeplanes[i][j].third.harder_flav=0;
          src_threeplanes[i][j].third.softer_flav=0;

          for(size_t k = 0; k < dst_threeplanes.at(i).size(); k++){
            matchPlanes(src_threeplanes[i][j].first, dst_threeplanes[i][k].first, drcutweight);
            if (matchPlanes(src_threeplanes[i][j].second, dst_threeplanes[i][k].second, drcutweight) ||
                matchPlanes(src_threeplanes[i][j].second, dst_threeplanes[i][k].third, drcutweight))
            {
              match_results02[j] = k;
            }
            if (matchPlanes(src_threeplanes[i][j].third, dst_threeplanes[i][k].third, drcutweight) ||
                matchPlanes(src_threeplanes[i][j].third, dst_threeplanes[i][k].second, drcutweight))
            {
              match_results03[j] = k;
            }
          }
        }
        match_results2.push_back(match_results02);
        match_results3.push_back(match_results03);
      }
    }
    return std::make_pair(match_results2, match_results3);
  }
  static std::pair<std::vector<std::vector<int>>, std::vector<std::vector<int>>>
  matchPlanesLeadingJet(vector<std::vector<JetBranch::threeplanes>> &src_threeplanes,
              vector<std::vector<JetBranch::threeplanes>> &dst_threeplanes,
              TString opt = "second",double drcutweight=1) {
    std::vector<JetBranch::PlaneVariables> src_plane, dst_plane;
    vector<std::vector<int>> match_results2;
    vector<std::vector<int>> match_results3;
    if (opt.EqualTo("second")) {
      for (size_t i = 0; i < src_threeplanes.size(); i++) {
        std::vector<int> match_results02;
        std::vector<int> match_results03;
        for(size_t j = 0; j < src_threeplanes.at(i).size(); j++){
          match_results02.push_back(-1);
          match_results03.push_back(-1);
          src_threeplanes[i][j].first.isgg=false;
          src_threeplanes[i][j].first.isqq=false;
          src_threeplanes[i][j].second.isgg=false;
          src_threeplanes[i][j].second.isqq=false;
          src_threeplanes[i][j].third.isgg=false;
          src_threeplanes[i][j].third.isqq=false;

           src_threeplanes[i][j].first.harder_flav=0;
          src_threeplanes[i][j].first.softer_flav=0;
          src_threeplanes[i][j].second.harder_flav=0;
          src_threeplanes[i][j].second.softer_flav=0;
          src_threeplanes[i][j].third.harder_flav=0;
          src_threeplanes[i][j].third.softer_flav=0;

          for(size_t k = 0; k < dst_threeplanes.at(i).size(); k++){
            matchPlanes(src_threeplanes[i][j].first, dst_threeplanes[i][k].first, drcutweight);
            if (matchPlanes(src_threeplanes[i][j].second, dst_threeplanes[i][k].second, drcutweight) ||
                matchPlanes(src_threeplanes[i][j].second, dst_threeplanes[i][k].third, drcutweight))
            {
              match_results02[j] = k;
            }
            if (matchPlanes(src_threeplanes[i][j].third, dst_threeplanes[i][k].third, drcutweight) ||
                matchPlanes(src_threeplanes[i][j].third, dst_threeplanes[i][k].second, drcutweight))
            {
              match_results03[j] = k;
            }
          }
        }
        match_results2.push_back(match_results02);
        match_results3.push_back(match_results03);
      }
    }
    return std::make_pair(match_results2, match_results3);
  }
  static void SetUserIndex(PseudoJet &jet, int &index) {
    if (jet.user_index() != -1) {
      // 如果已经设置了index，就不再处理
      return;
    }
    jet.set_user_index(index++); // 设置当前jet的index，并增加index

    PseudoJet parent1, parent2;
    if (jet.has_parents(parent1, parent2)) {
      SetUserIndex(parent1, index); // 递归标记第一个parent
      SetUserIndex(parent2, index); // 递归标记第二个parent
    }
  }

  static void SetPseudoCAJetsIndex(vector<PseudoJet> &jets) {
    int k = 0;
    for (PseudoJet &jet : jets) {
      SetUserIndex(jet, k);
    }
  }
  static int GetIFNFlavour(PseudoJet &jet)
  {
    if (jet.pt() == 0)
      return 0;
    int pdgid = FlavHistory::current_flavour_of(jet).pdg_code();

    if (pdgid == 0)
    {
      TString flav = FlavHistory::current_flavour_of(jet).description();
      if (flav.EqualTo("[g]"))
      {
        pdgid = 21;
      }
    }
    return pdgid;
  }

  static int GetNtracks(vector<PseudoJet> constituents,vector<ParticleInfo> particlesinfo){
    int ncharge = 0;
    int x=0;
    int y=0;
    for (auto &particle : constituents) {
      int particle_index = particle.user_index();

      double charge = particlesinfo.at(particle_index).charge;
      if(abs(charge)>=0.1) ncharge++;
    }
    return ncharge;
  }
};