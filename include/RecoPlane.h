#include "JetBranch.h"
#include "Matching.cc"
#include "ParticleInfo.h"
#include "Process_bar.h"
#include "TLorentzVector.h"
#include "TreeEvents.h"
#include "common_tool.h"
#include "fastjet/contrib/IFNPlugin.hh"
#include "fastjet/contrib/GHSAlgo.hh"
#include <TChain.h>
#include <TFile.h>
#include <TLorentzVector.h>
#include <algorithm>
#include <cassert>
#include <fastjet/ClusterSequence.hh>
#include <fastjet/PseudoJet.hh>
#include <fstream>
#include <iostream>
#include <map>
#include <random>
#include <set>
#include <string>
#include <tuple>
#include <variant>
#include <vector>
using namespace fastjet;
using namespace std;
using namespace fastjet::contrib;

class RecoPlane {
public:
  static JetBranch::twoplanes
  JetConstituents(vector<ParticleInfo> constituents) {
    double z1cut = 0;
    double z2cut = 0;
    double kt1cut = 1;
    double kt2cut = 0;
    double issecondsoft = true;
    vector<JetBranch::twoplanes> twoplanes;
    std::vector<PseudoJet> particles;
    std::vector<ParticleInfo> particlesinfo;
    for (size_t i = 0; i < constituents.size(); ++i) {
      TLorentzVector p;
      p.SetPtEtaPhiE(constituents.at(i).pt, constituents.at(i).eta,
                     constituents.at(i).phi, constituents.at(i).e);
      PseudoJet particle = PseudoJet(p.Px(), p.Py(), p.Pz(), p.Energy());
      int pdgid = constituents.at(i).pdgid;
      ParticleInfo particleInfo(pdgid, constituents.at(i).chargeInt);
      particlesinfo.push_back(particleInfo);
      particle.set_user_index(i);
      particle.set_user_info(new FlavHistory(pdgid));
      particles.push_back(particle);
    }
    JetDefinition jet_def_CA(cambridge_algorithm,
                             JetDefinition::max_allowable_R);
    fastjet::contrib::FlavRecombiner flav_recombiner;
    jet_def_CA.set_recombiner(&flav_recombiner);
    double alpha = 1.0;
    double omega = 3.0 - alpha;
    fastjet::contrib::FlavRecombiner::FlavSummation flav_summation =
        fastjet::contrib::FlavRecombiner::net;
    auto ifn_plugin = new IFNPlugin(jet_def_CA, alpha, omega, flav_summation);
    JetDefinition IFN_jet_def(ifn_plugin);
    IFN_jet_def.delete_plugin_when_unused();
    ClusterSequence cs_IFN(particles, IFN_jet_def);
    vector<PseudoJet> jets_IFN = sorted_by_pt(cs_IFN.inclusive_jets());
    PseudoJet j0, j1, j2, j3, j4;
    j0 = jets_IFN[0];
    
    double Q = j0.e();
    auto twoplane = JetBranch::findPrimaryAndSecondaryJets(
        j0, z1cut, z2cut, kt1cut * 2 * Q, kt2cut * 2 * Q, particlesinfo,
        issecondsoft);

    return twoplane;
  }
  static JetBranch::threeplanes
  JetConstituents_threeplanes(vector<ParticleInfo> constituents) {
    double z1cut = 0;
    double z2cut = 0;
    double kt1cut = 1;
    double kt2cut = 0;
    double issecondsoft = true;
    vector<JetBranch::twoplanes> twoplanes;
    std::vector<PseudoJet> particles;
    std::vector<ParticleInfo> particlesinfo;
    for (size_t i = 0; i < constituents.size(); ++i) {
      TLorentzVector p;
      p.SetPtEtaPhiE(constituents.at(i).pt, constituents.at(i).eta,
                     constituents.at(i).phi, constituents.at(i).e);
      PseudoJet particle = PseudoJet(p.Px(), p.Py(), p.Pz(), p.Energy());
      int pdgid = constituents.at(i).pdgid;
      ParticleInfo particleInfo(pdgid, constituents.at(i).chargeInt);
      particlesinfo.push_back(particleInfo);
      particle.set_user_index(i);
      particle.set_user_info(new FlavHistory(pdgid));
      particles.push_back(particle);
    }
    JetDefinition jet_def_CA(cambridge_algorithm,
                             JetDefinition::max_allowable_R);
    fastjet::contrib::FlavRecombiner flav_recombiner;
    jet_def_CA.set_recombiner(&flav_recombiner);

    double alpha = 1.0;
    double omega = 3.0 - alpha;
    fastjet::contrib::FlavRecombiner::FlavSummation flav_summation =
        fastjet::contrib::FlavRecombiner::net;
    auto ifn_plugin = new IFNPlugin(jet_def_CA, alpha, omega, flav_summation);
    JetDefinition IFN_jet_def(ifn_plugin);
    IFN_jet_def.delete_plugin_when_unused();
    ClusterSequence cs_IFN(particles, IFN_jet_def);

    vector<PseudoJet> jets_IFN = sorted_by_pt(cs_IFN.inclusive_jets());

    PseudoJet j0, j1, j2, j3, j4;
    j0 = jets_IFN[0];
    
    double Q = j0.e();
    auto threeplanes = JetBranch::findPrimarySecondaryAndThirdaryJets(
        j0, z1cut, z2cut, kt1cut * 2 * Q, kt2cut * 2 * Q, particlesinfo,
        issecondsoft);

    return threeplanes;
  }
  static JetBranch::threeplanes
  JetConstituents_threeplanesGHS(vector<ParticleInfo> constituents) {
    double z1cut = 0;
    double z2cut = 0;
    double kt1cut = 1;
    double kt2cut = 0;
    double issecondsoft = true;
    vector<JetBranch::twoplanes> twoplanes;
    std::vector<PseudoJet> particles;
    std::vector<ParticleInfo> particlesinfo;
    for (size_t i = 0; i < constituents.size(); ++i) {
      TLorentzVector p;
      p.SetPtEtaPhiE(constituents.at(i).pt, constituents.at(i).eta,
                     constituents.at(i).phi, constituents.at(i).e);
      PseudoJet particle = PseudoJet(p.Px(), p.Py(), p.Pz(), p.Energy());
      int pdgid = constituents.at(i).pdgid;
      ParticleInfo particleInfo(pdgid, constituents.at(i).chargeInt);
      particlesinfo.push_back(particleInfo);
      particle.set_user_index(i);
      particle.set_user_info(new FlavHistory(pdgid));
      particles.push_back(particle);
    }
    JetDefinition jet_def_CA(cambridge_algorithm,
                             JetDefinition::max_allowable_R);
    fastjet::contrib::FlavRecombiner flav_recombiner;
    jet_def_CA.set_recombiner(&flav_recombiner);
    
    double GHS_alpha = 1.0; // < flav-kt distance parameter alpha
    double GHS_omega = 2.0;
    ClusterSequence cs_CA(particles, jet_def_CA);
    vector<PseudoJet> jets_CA = sorted_by_pt(cs_CA.inclusive_jets());
    vector<PseudoJet> GHS_jets  = run_GHS(jets_CA, 0, GHS_alpha, GHS_omega, flav_recombiner);

    PseudoJet j0, j1, j2, j3, j4;
    j0 = GHS_jets[0];
    
    double Q = j0.e();
    auto threeplanes = JetBranch::findPrimarySecondaryAndThirdaryJets(
        j0, z1cut, z2cut, kt1cut * 2 * Q, kt2cut * 2 * Q, particlesinfo,
        issecondsoft);

    return threeplanes;
  }
  static void SavePlanes(JetBranch::twoplanes twoplanes, TreeEvents &treeEvents,
                         int jetindex, string prefix = "", string suffix = "") {
    treeEvents.push_back(prefix + "pt1" + suffix, twoplanes.first.harder.pt());
    treeEvents.push_back(prefix + "eta1" + suffix,
                         twoplanes.first.harder.eta());
    treeEvents.push_back(prefix + "phi1" + suffix,
                         twoplanes.first.harder.phi());
    treeEvents.push_back(prefix + "e1" + suffix, twoplanes.first.harder.e());
    treeEvents.push_back(prefix + "ntracks1" + suffix,
                         twoplanes.first.harder_ntracks);
    treeEvents.push_back(prefix + "nparticles1" + suffix,
                         twoplanes.first.harder_nparticles);

    treeEvents.push_back(prefix + "pt2" + suffix, twoplanes.first.softer.pt());
    treeEvents.push_back(prefix + "eta2" + suffix,
                         twoplanes.first.softer.eta());
    treeEvents.push_back(prefix + "phi2" + suffix,
                         twoplanes.first.softer.phi());
    treeEvents.push_back(prefix + "e2" + suffix, twoplanes.first.softer.e());
    treeEvents.push_back(prefix + "ntracks2" + suffix,
                         twoplanes.first.softer_ntracks);
    treeEvents.push_back(prefix + "nparticles2" + suffix,
                         twoplanes.first.softer_nparticles);

    treeEvents.push_back(prefix + "pt3" + suffix, twoplanes.second.harder.pt());
    treeEvents.push_back(prefix + "eta3" + suffix,
                         twoplanes.second.harder.eta());
    treeEvents.push_back(prefix + "phi3" + suffix,
                         twoplanes.second.harder.phi());
    treeEvents.push_back(prefix + "e3" + suffix, twoplanes.second.harder.e());
    treeEvents.push_back(prefix + "ntracks3" + suffix,
                         twoplanes.second.harder_ntracks);
    treeEvents.push_back(prefix + "nparticles3" + suffix,
                         twoplanes.second.harder_nparticles);

    treeEvents.push_back(prefix + "pt4" + suffix, twoplanes.second.softer.pt());
    treeEvents.push_back(prefix + "eta4" + suffix,
                         twoplanes.second.softer.eta());
    treeEvents.push_back(prefix + "phi4" + suffix,
                         twoplanes.second.softer.phi());
    treeEvents.push_back(prefix + "e4" + suffix, twoplanes.second.softer.e());
    treeEvents.push_back(prefix + "ntracks4" + suffix,
                         twoplanes.second.softer_ntracks);
    treeEvents.push_back(prefix + "nparticles4" + suffix,
                         twoplanes.second.softer_nparticles);

    treeEvents.push_back(prefix + "z1" + suffix, twoplanes.first.z);
    treeEvents.push_back(prefix + "kt1" + suffix, twoplanes.first.kt);
    treeEvents.push_back(prefix + "theta1" + suffix, twoplanes.first.theta);
    treeEvents.push_back(prefix + "deltaR1" + suffix, twoplanes.first.deltaR);
    treeEvents.push_back(
        prefix + "eec1" + suffix,
        (twoplanes.first.harder.e() * twoplanes.first.softer.e()) * 1.0 /
            twoplanes.Q / twoplanes.Q);
    treeEvents.push_back(prefix + "z2" + suffix, twoplanes.second.z);
    treeEvents.push_back(prefix + "kt2" + suffix, twoplanes.second.kt);
    treeEvents.push_back(prefix + "theta2" + suffix, twoplanes.second.theta);
    treeEvents.push_back(prefix + "deltaR2" + suffix, twoplanes.second.deltaR);
    treeEvents.push_back(
        prefix + "eec2" + suffix,
        (twoplanes.second.harder.e() * twoplanes.second.softer.e()) * 1.0 /
            twoplanes.Q / twoplanes.Q);
    treeEvents.push_back(prefix + "n1x" + suffix, twoplanes.first.n.x());
    treeEvents.push_back(prefix + "n1y" + suffix, twoplanes.first.n.y());
    treeEvents.push_back(prefix + "n1z" + suffix, twoplanes.first.n.z());
    treeEvents.push_back(prefix + "n2x" + suffix, twoplanes.second.n.x());
    treeEvents.push_back(prefix + "n2y" + suffix, twoplanes.second.n.y());
    treeEvents.push_back(prefix + "n2z" + suffix, twoplanes.second.n.z());
    treeEvents.push_back(prefix + "isqq" + suffix,
                         static_cast<int>(twoplanes.second.isqq));
    treeEvents.push_back(prefix + "isgg" + suffix,
                         static_cast<int>(twoplanes.second.isgg));
    treeEvents.push_back(prefix + "phi" + suffix, twoplanes.deltaPhi);

    treeEvents.push_back(prefix + "jpt" + suffix, twoplanes.first.initJet.Pt());
    treeEvents.push_back(prefix + "jeta" + suffix,
                         twoplanes.first.initJet.Eta());
    treeEvents.push_back(prefix + "jphi" + suffix,
                         twoplanes.first.initJet.Phi());
    treeEvents.push_back(prefix + "je" + suffix, twoplanes.first.initJet.E());

    for (int ii = 0; ii < twoplanes.first.harder_constituents_info.size();
         ii++) {
      auto particle = twoplanes.first.harder_constituents_info.at(ii);
      treeEvents.push_back(prefix + "particle1_pt" + suffix, particle.pt);
      treeEvents.push_back(prefix + "particle1_eta" + suffix, particle.eta);
      treeEvents.push_back(prefix + "particle1_phi" + suffix, particle.phi);
      treeEvents.push_back(prefix + "particle1_e" + suffix, particle.e);
      treeEvents.push_back(prefix + "particle1_charge" + suffix,
                           particle.charge);
      treeEvents.push_back(prefix + "particle1_pid" + suffix, particle.pdgid);
      treeEvents.push_back(prefix + "particle1_jetid" + suffix, jetindex);
    }
    for (int ii = 0; ii < twoplanes.first.softer_constituents_info.size();
         ii++) {
      auto particle = twoplanes.first.softer_constituents_info.at(ii);
      treeEvents.push_back(prefix + "particle2_pt" + suffix, particle.pt);
      treeEvents.push_back(prefix + "particle2_eta" + suffix, particle.eta);
      treeEvents.push_back(prefix + "particle2_phi" + suffix, particle.phi);
      treeEvents.push_back(prefix + "particle2_e" + suffix, particle.e);
      treeEvents.push_back(prefix + "particle2_charge" + suffix,
                           particle.charge);
      treeEvents.push_back(prefix + "particle2_pid" + suffix, particle.pdgid);
      treeEvents.push_back(prefix + "particle2_jetid" + suffix, jetindex);
    }

    for (int ii = 0; ii < twoplanes.second.harder_constituents_info.size();
         ii++) {
      auto particle = twoplanes.second.harder_constituents_info.at(ii);
      treeEvents.push_back(prefix + "particle3_pt" + suffix, particle.pt);
      treeEvents.push_back(prefix + "particle3_eta" + suffix, particle.eta);
      treeEvents.push_back(prefix + "particle3_phi" + suffix, particle.phi);
      treeEvents.push_back(prefix + "particle3_e" + suffix, particle.e);
      treeEvents.push_back(prefix + "particle3_charge" + suffix,
                           particle.charge);
      treeEvents.push_back(prefix + "particle3_pid" + suffix, particle.pdgid);
      treeEvents.push_back(prefix + "particle3_jetid" + suffix, jetindex);
    }
    for (int ii = 0; ii < twoplanes.second.softer_constituents_info.size();
         ii++) {
      auto particle = twoplanes.second.softer_constituents_info.at(ii);
      treeEvents.push_back(prefix + "particle4_pt" + suffix, particle.pt);
      treeEvents.push_back(prefix + "particle4_eta" + suffix, particle.eta);
      treeEvents.push_back(prefix + "particle4_phi" + suffix, particle.phi);
      treeEvents.push_back(prefix + "particle4_e" + suffix, particle.e);
      treeEvents.push_back(prefix + "particle4_charge" + suffix,
                           particle.charge);
      treeEvents.push_back(prefix + "particle4_pid" + suffix, particle.pdgid);
      treeEvents.push_back(prefix + "particle4_jetid" + suffix, jetindex);
    }
  }
  static void SavePlanes(JetBranch::threeplanes threeplanes, TreeEvents &treeEvents,
                         int jetindex, string prefix = "", string suffix = "") {
    treeEvents.push_back(prefix + "pt1" + suffix, threeplanes.first.harder.pt());
    treeEvents.push_back(prefix + "eta1" + suffix,
                         threeplanes.first.harder.eta());
    treeEvents.push_back(prefix + "phi1" + suffix,
                         threeplanes.first.harder.phi());
    treeEvents.push_back(prefix + "e1" + suffix, threeplanes.first.harder.e());
    treeEvents.push_back(prefix + "ntracks1" + suffix,
                         threeplanes.first.harder_ntracks);
    treeEvents.push_back(prefix + "nparticles1" + suffix,
                         threeplanes.first.harder_nparticles);
    treeEvents.push_back(prefix + "flavour1" + suffix,
                         threeplanes.first.harder_flav);                     
    treeEvents.push_back(prefix + "pt2" + suffix, threeplanes.first.softer.pt());
    treeEvents.push_back(prefix + "eta2" + suffix,
                         threeplanes.first.softer.eta());
    treeEvents.push_back(prefix + "phi2" + suffix,
                         threeplanes.first.softer.phi());
    treeEvents.push_back(prefix + "e2" + suffix, threeplanes.first.softer.e());
    treeEvents.push_back(prefix + "ntracks2" + suffix,
                         threeplanes.first.softer_ntracks);
    treeEvents.push_back(prefix + "nparticles2" + suffix,
                         threeplanes.first.softer_nparticles);
    treeEvents.push_back(prefix + "flavour2" + suffix,
                         threeplanes.first.softer_flav);  

    treeEvents.push_back(prefix + "pt3" + suffix, threeplanes.second.harder.pt());
    treeEvents.push_back(prefix + "eta3" + suffix,
                         threeplanes.second.harder.eta());
    treeEvents.push_back(prefix + "phi3" + suffix,
                         threeplanes.second.harder.phi());
    treeEvents.push_back(prefix + "e3" + suffix, threeplanes.second.harder.e());
    treeEvents.push_back(prefix + "ntracks3" + suffix,
                         threeplanes.second.harder_ntracks);
    treeEvents.push_back(prefix + "nparticles3" + suffix,
                         threeplanes.second.harder_nparticles);
    treeEvents.push_back(prefix + "flavour3" + suffix,
                         threeplanes.second.harder_flav);

    treeEvents.push_back(prefix + "pt4" + suffix, threeplanes.second.softer.pt());
    treeEvents.push_back(prefix + "eta4" + suffix,
                         threeplanes.second.softer.eta());
    treeEvents.push_back(prefix + "phi4" + suffix,
                         threeplanes.second.softer.phi());
    treeEvents.push_back(prefix + "e4" + suffix, threeplanes.second.softer.e());
    treeEvents.push_back(prefix + "ntracks4" + suffix,
                         threeplanes.second.softer_ntracks);
    treeEvents.push_back(prefix + "nparticles4" + suffix,
                         threeplanes.second.softer_nparticles);
    treeEvents.push_back(prefix + "flavour4" + suffix,
                         threeplanes.second.softer_flav);  

    treeEvents.push_back(prefix + "pt5" + suffix, threeplanes.third.harder.pt());
    treeEvents.push_back(prefix + "eta5" + suffix,
                         threeplanes.third.harder.eta());
    treeEvents.push_back(prefix + "phi5" + suffix,
                         threeplanes.third.harder.phi());
    treeEvents.push_back(prefix + "e5" + suffix, threeplanes.third.harder.e());
    treeEvents.push_back(prefix + "ntracks5" + suffix,
                         threeplanes.third.harder_ntracks);
    treeEvents.push_back(prefix + "nparticles5" + suffix,
                         threeplanes.third.harder_nparticles);
    treeEvents.push_back(prefix + "flavour5" + suffix,
                         threeplanes.third.harder_flav);


    treeEvents.push_back(prefix + "pt6" + suffix, threeplanes.third.softer.pt());
    treeEvents.push_back(prefix + "eta6" + suffix,
                         threeplanes.third.softer.eta());
    treeEvents.push_back(prefix + "phi6" + suffix,
                         threeplanes.third.softer.phi());
    treeEvents.push_back(prefix + "e6" + suffix, threeplanes.third.softer.e());
    treeEvents.push_back(prefix + "ntracks6" + suffix,
                         threeplanes.third.softer_ntracks);
    treeEvents.push_back(prefix + "nparticles6" + suffix,
                         threeplanes.third.softer_nparticles);
    treeEvents.push_back(prefix + "flavour6" + suffix,
                         threeplanes.third.softer_flav); 


    treeEvents.push_back(prefix + "z1" + suffix, threeplanes.first.z);
    treeEvents.push_back(prefix + "kt1" + suffix, threeplanes.first.kt);
    treeEvents.push_back(prefix + "theta1" + suffix, threeplanes.first.theta);
    treeEvents.push_back(prefix + "deltaR1" + suffix, threeplanes.first.deltaR);
    treeEvents.push_back(
        prefix + "eec1" + suffix,
        (threeplanes.first.harder.e() * threeplanes.first.softer.e()) * 1.0 /
            threeplanes.Q / threeplanes.Q);

    treeEvents.push_back(prefix + "z2" + suffix, threeplanes.second.z);
    treeEvents.push_back(prefix + "kt2" + suffix, threeplanes.second.kt);
    treeEvents.push_back(prefix + "theta2" + suffix, threeplanes.second.theta);
    treeEvents.push_back(prefix + "deltaR2" + suffix, threeplanes.second.deltaR);
    treeEvents.push_back(
        prefix + "eec2" + suffix,
        (threeplanes.second.harder.e() * threeplanes.second.softer.e()) * 1.0 /
            threeplanes.Q / threeplanes.Q);

    treeEvents.push_back(prefix + "z3" + suffix, threeplanes.third.z);
    treeEvents.push_back(prefix + "kt3" + suffix, threeplanes.third.kt);
    treeEvents.push_back(prefix + "theta3" + suffix, threeplanes.third.theta);
    treeEvents.push_back(prefix + "deltaR3" + suffix, threeplanes.third.deltaR);
    treeEvents.push_back(
        prefix + "eec3" + suffix,
        (threeplanes.third.harder.e() * threeplanes.third.softer.e()) * 1.0 /
            threeplanes.Q / threeplanes.Q);

    treeEvents.push_back(prefix + "n1x" + suffix, threeplanes.first.n.x());
    treeEvents.push_back(prefix + "n1y" + suffix, threeplanes.first.n.y());
    treeEvents.push_back(prefix + "n1z" + suffix, threeplanes.first.n.z());
    treeEvents.push_back(prefix + "n2x" + suffix, threeplanes.second.n.x());
    treeEvents.push_back(prefix + "n2y" + suffix, threeplanes.second.n.y());
    treeEvents.push_back(prefix + "n2z" + suffix, threeplanes.second.n.z());
    treeEvents.push_back(prefix + "n3x" + suffix, threeplanes.third.n.x());
    treeEvents.push_back(prefix + "n3y" + suffix, threeplanes.third.n.y());
    treeEvents.push_back(prefix + "n3z" + suffix, threeplanes.third.n.z());

    treeEvents.push_back(prefix + "isqq" + suffix,
                         static_cast<int>(threeplanes.second.isqq));
    treeEvents.push_back(prefix + "isgg" + suffix,
                         static_cast<int>(threeplanes.second.isgg));
    treeEvents.push_back(prefix + "phi" + suffix, threeplanes.deltaPhi);
    treeEvents.push_back(prefix + "isqq2" + suffix,
                         static_cast<int>(threeplanes.third.isqq));
    treeEvents.push_back(prefix + "isgg2" + suffix,
                         static_cast<int>(threeplanes.third.isgg));
    treeEvents.push_back(prefix + "thirdphi" + suffix, threeplanes.deltaPhi2);

    treeEvents.push_back(prefix + "jpt" + suffix, threeplanes.first.initJet.Pt());
    treeEvents.push_back(prefix + "jeta" + suffix,
                         threeplanes.first.initJet.Eta());
    treeEvents.push_back(prefix + "jphi" + suffix,
                         threeplanes.first.initJet.Phi());
    treeEvents.push_back(prefix + "je" + suffix, threeplanes.first.initJet.E());

    for (int ii = 0; ii < threeplanes.first.harder_constituents_info.size();
         ii++) {
      auto particle = threeplanes.first.harder_constituents_info.at(ii);
      treeEvents.push_back(prefix + "particle1_pt" + suffix, particle.pt);
      treeEvents.push_back(prefix + "particle1_eta" + suffix, particle.eta);
      treeEvents.push_back(prefix + "particle1_phi" + suffix, particle.phi);
      treeEvents.push_back(prefix + "particle1_e" + suffix, particle.e);
      treeEvents.push_back(prefix + "particle1_charge" + suffix,
                           particle.charge);
      treeEvents.push_back(prefix + "particle1_pid" + suffix, particle.pdgid);
      treeEvents.push_back(prefix + "particle1_jetid" + suffix, jetindex);
    }
    for (int ii = 0; ii < threeplanes.first.softer_constituents_info.size();
         ii++) {
      auto particle = threeplanes.first.softer_constituents_info.at(ii);
      treeEvents.push_back(prefix + "particle2_pt" + suffix, particle.pt);
      treeEvents.push_back(prefix + "particle2_eta" + suffix, particle.eta);
      treeEvents.push_back(prefix + "particle2_phi" + suffix, particle.phi);
      treeEvents.push_back(prefix + "particle2_e" + suffix, particle.e);
      treeEvents.push_back(prefix + "particle2_charge" + suffix,
                           particle.charge);
      treeEvents.push_back(prefix + "particle2_pid" + suffix, particle.pdgid);
      treeEvents.push_back(prefix + "particle2_jetid" + suffix, jetindex);
    }

    for (int ii = 0; ii < threeplanes.second.harder_constituents_info.size();
         ii++) {
      auto particle = threeplanes.second.harder_constituents_info.at(ii);
      treeEvents.push_back(prefix + "particle3_pt" + suffix, particle.pt);
      treeEvents.push_back(prefix + "particle3_eta" + suffix, particle.eta);
      treeEvents.push_back(prefix + "particle3_phi" + suffix, particle.phi);
      treeEvents.push_back(prefix + "particle3_e" + suffix, particle.e);
      treeEvents.push_back(prefix + "particle3_charge" + suffix,
                           particle.charge);
      treeEvents.push_back(prefix + "particle3_pid" + suffix, particle.pdgid);
      treeEvents.push_back(prefix + "particle3_jetid" + suffix, jetindex);
    }
    for (int ii = 0; ii < threeplanes.second.softer_constituents_info.size();
         ii++) {
      auto particle = threeplanes.second.softer_constituents_info.at(ii);
      treeEvents.push_back(prefix + "particle4_pt" + suffix, particle.pt);
      treeEvents.push_back(prefix + "particle4_eta" + suffix, particle.eta);
      treeEvents.push_back(prefix + "particle4_phi" + suffix, particle.phi);
      treeEvents.push_back(prefix + "particle4_e" + suffix, particle.e);
      treeEvents.push_back(prefix + "particle4_charge" + suffix,
                           particle.charge);
      treeEvents.push_back(prefix + "particle4_pid" + suffix, particle.pdgid);
      treeEvents.push_back(prefix + "particle4_jetid" + suffix, jetindex);
    }

    for (int ii = 0; ii < threeplanes.third.harder_constituents_info.size();
         ii++) {
      auto particle = threeplanes.third.harder_constituents_info.at(ii);
      treeEvents.push_back(prefix + "particle5_pt" + suffix, particle.pt);
      treeEvents.push_back(prefix + "particle5_eta" + suffix, particle.eta);
      treeEvents.push_back(prefix + "particle5_phi" + suffix, particle.phi);
      treeEvents.push_back(prefix + "particle5_e" + suffix, particle.e);
      treeEvents.push_back(prefix + "particle5_charge" + suffix,
                           particle.charge);
      treeEvents.push_back(prefix + "particle5_pid" + suffix, particle.pdgid);
      treeEvents.push_back(prefix + "particle5_jetid" + suffix, jetindex);
    }
    for (int ii = 0; ii < threeplanes.third.softer_constituents_info.size();
         ii++) {
      auto particle = threeplanes.third.softer_constituents_info.at(ii);
      treeEvents.push_back(prefix + "particle6_pt" + suffix, particle.pt);
      treeEvents.push_back(prefix + "particle6_eta" + suffix, particle.eta);
      treeEvents.push_back(prefix + "particle6_phi" + suffix, particle.phi);
      treeEvents.push_back(prefix + "particle6_e" + suffix, particle.e);
      treeEvents.push_back(prefix + "particle6_charge" + suffix,
                           particle.charge);
      treeEvents.push_back(prefix + "particle6_pid" + suffix, particle.pdgid);
      treeEvents.push_back(prefix + "particle6_jetid" + suffix, jetindex);
    }
  }
};
