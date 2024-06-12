#include "JetBranch.h"
#include "Matching.cc"
#include "ParticleInfo.h"
#include "Process_bar.h"
#include "TLorentzVector.h"
#include "TreeEvents.h"
#include "common_tool.h"
#include "fastjet/contrib/IFNPlugin.hh"
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


class LoadData {
public:
  TChain &chain;
  vector<string> suffix_arr;
  double z1cut;
  double z2cut;
  double kt1cut;
  double kt2cut;
  bool issecondsoft;
  double ptcut;
  double minflavourpt;
  TString FlavourAlgorithm;
  struct BranchVectors {
    std::vector<double> *Pt = new std::vector<double>;
    std::vector<double> *Eta = new std::vector<double>;
    std::vector<double> *Phi = new std::vector<double>;
    std::vector<double> *Energy = new std::vector<double>;
    std::vector<int> *PdgId = new std::vector<int>;
    std::vector<double> *Charge = new std::vector<double>;
  };

  std::vector<BranchVectors> branchVectors;
  struct DataFormat {
    TreeEvents treeEvents;
    vector<TString> label;
    vector<vector<JetBranch::twoplanes>> twoplanes;
  };
  LoadData(TChain &_inputChain) : chain(_inputChain) {
    z1cut = 0;
    z2cut = 0;
    kt1cut = 0;
    kt2cut = 0;
    issecondsoft = true;
    ptcut = 450;
    minflavourpt = 0;
    FlavourAlgorithm = "";
  }
  void setzkcut(double _z1cut, double _z2cut, double _kt1cut, double _kt2cut) {
    z1cut = _z1cut;
    z2cut = _z2cut;
    kt1cut = _kt1cut;
    kt2cut = _kt2cut;
  }
  void setsecondhard() { issecondsoft = false; }
  void setptcut(double _ptcut) { ptcut = _ptcut; }
  void setminflavourpt(double _minflavourpt) { minflavourpt = _minflavourpt; }
  void setFlavourAlgorithm(TString _FlavourAlgorithm) {
    FlavourAlgorithm = _FlavourAlgorithm;
  }
  void AddProcessor(string suffix) {
    suffix_arr.push_back(suffix);
    BranchVectors bv;
    branchVectors.push_back(bv);
  }
  void AsignBranchAddress(TString suffix, BranchVectors &lastBV) {
    chain.SetBranchAddress("Pt" + suffix, &(lastBV.Pt));
    chain.SetBranchAddress("Eta" + suffix, &(lastBV.Eta));
    chain.SetBranchAddress("Phi" + suffix, &(lastBV.Phi));
    chain.SetBranchAddress("Energy" + suffix, &(lastBV.Energy));
    chain.SetBranchAddress("PdgId" + suffix, &(lastBV.PdgId));
    chain.SetBranchAddress("Charge" + suffix, &(lastBV.Charge));
  }
  vector<DataFormat> processData(int entries, TString opt = "opt1",
                                 int entry_begin = 0) {
    int processentries = chain.GetEntries() - entry_begin;
    if (entries != -1)
      processentries = std::min(entries, (int)chain.GetEntries() - entry_begin);
    vector<TreeEvents> treeEvent_templates;
    vector<DataFormat> processedData;
    for (int i = 0; i < suffix_arr.size(); i++) {
      TreeEvents treeEvents_template;
      treeEvent_templates.push_back(treeEvents_template);
      init_output_branches(treeEvent_templates.at(i), suffix_arr.at(i));
      DataFormat initDataFormat;
      processedData.push_back(initDataFormat);
      AsignBranchAddress(suffix_arr.at(i), branchVectors.at(i));
    }

    ProcessBar ProcessBar(processentries);
    for (int k = 0 + entry_begin; k < processentries + entry_begin; k++) {
      ProcessBar.show2(k - entry_begin);
      chain.GetEntry(k);
      if (opt.EqualTo("opt1")) {
        for (int i = 0; i < branchVectors.size(); i++) {
          auto event = opt1(branchVectors.at(i));
          concatenateDataRow(processedData.at(i), event, true);
        }
      }
    }
    for (int i = 0; i < branchVectors.size(); i++) {
      processedData.at(i).treeEvents = FormatFeature(
          processedData.at(i).twoplanes,
          treeEvent_templates.at(i).treeEvent_backup, suffix_arr.at(i));
    }
    return processedData;
  }
  void init_output_branches(TreeEvents &treeEvents, string suffix) {
    std::vector<string> branch_names = {
        "pt1", "eta1",   "phi1",    "e1",      "ntracks1", "nparticles1",
        "pt2", "eta2",   "phi2",    "e2",      "ntracks2", "nparticles2",
        "pt3", "eta3",   "phi3",    "e3",      "ntracks3", "nparticles3",
        "pt4", "eta4",   "phi4",    "e4",      "ntracks4", "nparticles4",
        "z1",  "kt1",    "theta1",  "deltaR1", "eec1",     "z2",
        "kt2", "theta2", "deltaR2", "eec2",    "n1x",      "n1y",
        "n1z", "n2x",    "n2y",     "n2z",     "isqq",     "isgg",
        "phi", "jpt",    "jeta",    "jphi",    "je" ,
        "particle1_pt","particle1_eta","particle1_phi","particle1_e","particle1_charge","particle1_pid","particle1_jetid",
        "particle2_pt","particle2_eta","particle2_phi","particle2_e","particle2_charge","particle2_pid","particle2_jetid",
        "particle3_pt","particle3_eta","particle3_phi","particle3_e","particle3_charge","particle3_pid","particle3_jetid",
        "particle4_pt","particle4_eta","particle4_phi","particle4_e","particle4_charge","particle4_pid","particle4_jetid"};
    for (auto &branch_name : branch_names) {
      if (branch_name == "isqq" || branch_name == "isgg" ||
          branch_name == "ntracks1" || branch_name == "ntracks2" ||
          branch_name == "ntracks3" || branch_name == "ntracks4" ||
          branch_name == "nparticles1" || branch_name == "nparticles2" ||
          branch_name == "nparticles3" || branch_name == "nparticles4" || 
           branch_name == "particle1_pid"|| branch_name == "particle1_jetid"||
           branch_name == "particle2_pid"|| branch_name == "particle2_jetid"||
           branch_name == "particle3_pid"|| branch_name == "particle3_jetid"||
           branch_name == "particle4_pid"|| branch_name == "particle4_jetid") {
        treeEvents.addBranches(branch_name + suffix + "/vI");
      } else {
        treeEvents.addBranches(branch_name + suffix + "/vD");
      }
    }
  }
  DataFormat opt1(BranchVectors branchvector) {
    int qqnum = 0;
    int ggnum = 0;
    vector<JetBranch::twoplanes> twoplanes;
    std::vector<PseudoJet> particles;
    std::vector<ParticleInfo> particlesinfo;
    for (size_t i = 0; i < branchvector.Pt->size(); ++i) {
      TLorentzVector p;
      p.SetPtEtaPhiE(branchvector.Pt->at(i), branchvector.Eta->at(i),
                     branchvector.Phi->at(i), branchvector.Energy->at(i));
      PseudoJet particle = PseudoJet(p.Px(), p.Py(), p.Pz(), p.Energy());
      // particle.set_user_info(new ParticleInfo(
      //     branchvector.PdgId->at(i), i, p.Px(), p.Py(), p.Pz(), p.Energy()));
      int pdgid = branchvector.PdgId->at(i);
      ParticleInfo particleInfo(pdgid, branchvector.Charge->at(i));
      particlesinfo.push_back(particleInfo);
      particle.set_user_index(i);
      particle.set_user_info(new FlavHistory(branchvector.PdgId->at(i)));
      particles.push_back(particle);
    }

    JetDefinition jet_def(antikt_algorithm, 0.4); 
    ClusterSequence cs(particles, jet_def);
    std::vector<PseudoJet> jets = cs.inclusive_jets(ptcut); // ptmin

    auto new_end =
        std::remove_if(jets.begin(), jets.end(), [](const PseudoJet &jet) {
          return std::abs(jet.eta()) > 2.5;
        });
    jets.erase(new_end, jets.end());
    for (auto &jet : jets) {
      std::vector<PseudoJet> constituents = jet.constituents();
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
      ClusterSequence cs_CA(constituents, jet_def_CA);
      vector<PseudoJet> jets_CA = sorted_by_pt(cs_CA.inclusive_jets());
      // JetBranch::SetPseudoCAJetsIndex(jets_CA);

      ClusterSequence cs_IFN(constituents, IFN_jet_def);
      vector<PseudoJet> jets_IFN = sorted_by_pt(cs_IFN.inclusive_jets());
      // JetBranch::SetPseudoCAJetsIndex(jets_IFN);

      PseudoJet jet_CA = jets_IFN[0];
      if(FlavourAlgorithm.EqualTo("Net")){
        jet_CA = jets_CA[0];
      }
      PseudoJet j0, j1, j2, j3, j4;
      j0 = jet_CA;
      double Q = j0.e();

      auto twoplane = JetBranch::findPrimaryAndSecondaryJets(
          j0, z1cut, z2cut, kt1cut * 2 * Q, kt2cut * 2 * Q, particlesinfo,
          issecondsoft);
      if (twoplane.first.harder.pt() == 0 || twoplane.first.softer.pt() == 0)
        continue;
      if (twoplane.second.harder.pt() == 0 || twoplane.second.softer.pt() == 0)
        continue;
      twoplane.Q = Q;

      int pdgid11 = JetBranch::netflavour(twoplane.first.harder,particlesinfo, minflavourpt);
      int pdgid12 = JetBranch::netflavour(twoplane.first.softer,particlesinfo, minflavourpt);
      int pdgid21 = JetBranch::netflavour(twoplane.second.harder,particlesinfo, minflavourpt);
      int pdgid22 = JetBranch::netflavour(twoplane.second.softer,particlesinfo, minflavourpt);
      // if(JetBranch::netflavour(twoplane.first.harder,particlesinfo,0)!=JetBranch::GetIFNFlavour(twoplane.first.harder)){
      //   for(auto &constituent : twoplane.first.harder.constituents()){
      //     cout<<particlesinfo.at(constituent.user_index()).pdgid<<" ";
      //   }
      //   cout<<endl;
      //   for(auto &constituent : twoplane.first.harder.constituents()){
      //     cout<<FlavHistory::initial_flavor_of(constituent).pdg_code()<<" ";
      //   }
      //   cout<<endl;
      //   for(auto &constituent : twoplane.first.harder.constituents()){
      //     cout<<FlavHistory::current_flavour_of(constituent).pdg_code()<<" ";
      //   }
      //   cout<<endl;
      // }
      // cout<<JetBranch::netflavour(twoplane.first.harder,particlesinfo,0)<<" "<<JetBranch::GetIFNFlavour(twoplane.first.harder)<<endl;
      if (FlavourAlgorithm.EqualTo("IFN")||FlavourAlgorithm.EqualTo("Net")) {
        pdgid11 = JetBranch::GetIFNFlavour(twoplane.first.harder);
        pdgid12 = JetBranch::GetIFNFlavour(twoplane.first.softer);
        pdgid21 = JetBranch::GetIFNFlavour(twoplane.second.harder);
        pdgid22 = JetBranch::GetIFNFlavour(twoplane.second.softer);
      }
      bool isqq = JetBranch::isqq(pdgid21, pdgid22, pdgid12);
      bool isgg = JetBranch::isgg(pdgid21, pdgid22, pdgid12);

      twoplane.first.isqq = JetBranch::isqq(pdgid11, pdgid12);
      twoplane.first.isgg = JetBranch::isgg(pdgid11, pdgid12);
      twoplane.second.isqq = JetBranch::isqq(pdgid21, pdgid22);
      twoplane.second.isgg = JetBranch::isgg(pdgid21, pdgid22);
      twoplanes.push_back(twoplane);
    }
    DataFormat output;
    output.twoplanes = {twoplanes};
    return output;
  }
  static TreeEvents
  FormatFeature(vector<vector<JetBranch::twoplanes>> twoplanes_tree,
                TreeEvents::TreeEvent treeEvent_template, string suffix = "") {
    ProcessBar ProcessBar(twoplanes_tree.size());
    TreeEvents treeEvents;
    for (int k = 0; k < twoplanes_tree.size(); k++) {
      ProcessBar.show2(k, "Extracting Features");
      auto twoplanesarr = twoplanes_tree.at(k);
      auto treeEvent = treeEvent_template;
      for (int i = 0; i < twoplanesarr.size(); i++) {
        auto twoplanes = twoplanesarr.at(i);
        treeEvent.push_back("pt1" + suffix, twoplanes.first.harder.pt());
        treeEvent.push_back("eta1" + suffix, twoplanes.first.harder.eta());
        treeEvent.push_back("phi1" + suffix, twoplanes.first.harder.phi());
        treeEvent.push_back("e1" + suffix, twoplanes.first.harder.e());
        treeEvent.push_back("ntracks1" + suffix,
                            twoplanes.first.harder_ntracks);
        treeEvent.push_back("nparticles1" + suffix,
                            twoplanes.first.harder_nparticles);

        treeEvent.push_back("pt2" + suffix, twoplanes.first.softer.pt());
        treeEvent.push_back("eta2" + suffix, twoplanes.first.softer.eta());
        treeEvent.push_back("phi2" + suffix, twoplanes.first.softer.phi());
        treeEvent.push_back("e2" + suffix, twoplanes.first.softer.e());
        treeEvent.push_back("ntracks2" + suffix,
                            twoplanes.first.softer_ntracks);
        treeEvent.push_back("nparticles2" + suffix,
                            twoplanes.first.softer_nparticles);

        treeEvent.push_back("pt3" + suffix, twoplanes.second.harder.pt());
        treeEvent.push_back("eta3" + suffix, twoplanes.second.harder.eta());
        treeEvent.push_back("phi3" + suffix, twoplanes.second.harder.phi());
        treeEvent.push_back("e3" + suffix, twoplanes.second.harder.e());
        treeEvent.push_back("ntracks3" + suffix,
                            twoplanes.second.harder_ntracks);
        treeEvent.push_back("nparticles3" + suffix,
                            twoplanes.second.harder_nparticles);

        treeEvent.push_back("pt4" + suffix, twoplanes.second.softer.pt());
        treeEvent.push_back("eta4" + suffix, twoplanes.second.softer.eta());
        treeEvent.push_back("phi4" + suffix, twoplanes.second.softer.phi());
        treeEvent.push_back("e4" + suffix, twoplanes.second.softer.e());
        treeEvent.push_back("ntracks4" + suffix,
                            twoplanes.second.softer_ntracks);
        treeEvent.push_back("nparticles4" + suffix,
                            twoplanes.second.softer_nparticles);

        treeEvent.push_back("z1" + suffix, twoplanes.first.z);
        treeEvent.push_back("kt1" + suffix, twoplanes.first.kt);
        treeEvent.push_back("theta1" + suffix, twoplanes.first.theta);
        treeEvent.push_back("deltaR1" + suffix, twoplanes.first.deltaR);
        treeEvent.push_back(
            "eec1" + suffix,
            (twoplanes.first.harder.e() * twoplanes.first.softer.e()) * 1.0 /
                twoplanes.Q / twoplanes.Q);
        treeEvent.push_back("z2" + suffix, twoplanes.second.z);
        treeEvent.push_back("kt2" + suffix, twoplanes.second.kt);
        treeEvent.push_back("theta2" + suffix, twoplanes.second.theta);
        treeEvent.push_back("deltaR2" + suffix, twoplanes.second.deltaR);
        treeEvent.push_back(
            "eec2" + suffix,
            (twoplanes.second.harder.e() * twoplanes.second.softer.e()) * 1.0 /
                twoplanes.Q / twoplanes.Q);
        treeEvent.push_back("n1x" + suffix, twoplanes.first.n.x());
        treeEvent.push_back("n1y" + suffix, twoplanes.first.n.y());
        treeEvent.push_back("n1z" + suffix, twoplanes.first.n.z());
        treeEvent.push_back("n2x" + suffix, twoplanes.second.n.x());
        treeEvent.push_back("n2y" + suffix, twoplanes.second.n.y());
        treeEvent.push_back("n2z" + suffix, twoplanes.second.n.z());
        treeEvent.push_back("isqq" + suffix,
                            static_cast<int>(twoplanes.second.isqq));
        treeEvent.push_back("isgg" + suffix,
                            static_cast<int>(twoplanes.second.isgg));
        treeEvent.push_back("phi" + suffix, twoplanes.deltaPhi);

        treeEvent.push_back("jpt" + suffix, twoplanes.first.initJet.Pt());
        treeEvent.push_back("jeta" + suffix, twoplanes.first.initJet.Eta());
        treeEvent.push_back("jphi" + suffix, twoplanes.first.initJet.Phi());
        treeEvent.push_back("je" + suffix, twoplanes.first.initJet.E());

        for(int ii=0;ii<twoplanes.first.harder_constituents_info.size();ii++){
          auto particle = twoplanes.first.harder_constituents_info.at(ii);
          treeEvent.push_back("particle1_pt" + suffix, particle.pt);
          treeEvent.push_back("particle1_eta" + suffix, particle.eta);
          treeEvent.push_back("particle1_phi" + suffix,  particle.phi);
          treeEvent.push_back("particle1_e" + suffix,  particle.e);
          treeEvent.push_back("particle1_charge" + suffix, particle.charge);
          treeEvent.push_back("particle1_pid" + suffix, particle.pdgid);
          treeEvent.push_back("particle1_jetid" + suffix, i);
        }
        for(int ii=0;ii<twoplanes.first.softer_constituents_info.size();ii++){
          auto particle = twoplanes.first.softer_constituents_info.at(ii);
          treeEvent.push_back("particle2_pt" + suffix, particle.pt);
          treeEvent.push_back("particle2_eta" + suffix, particle.eta);
          treeEvent.push_back("particle2_phi" + suffix,  particle.phi);
          treeEvent.push_back("particle2_e" + suffix,  particle.e);
          treeEvent.push_back("particle2_charge" + suffix, particle.charge);
          treeEvent.push_back("particle2_pid" + suffix, particle.pdgid);
          treeEvent.push_back("particle2_jetid" + suffix, i);
        }

        for(int ii=0;ii<twoplanes.second.harder_constituents_info.size();ii++){
          auto particle = twoplanes.second.harder_constituents_info.at(ii);
          treeEvent.push_back("particle3_pt" + suffix, particle.pt);
          treeEvent.push_back("particle3_eta" + suffix, particle.eta);
          treeEvent.push_back("particle3_phi" + suffix,  particle.phi);
          treeEvent.push_back("particle3_e" + suffix,  particle.e);
          treeEvent.push_back("particle3_charge" + suffix, particle.charge);
          treeEvent.push_back("particle3_pid" + suffix, particle.pdgid);
          treeEvent.push_back("particle3_jetid" + suffix, i);
        }
        for(int ii=0;ii<twoplanes.second.softer_constituents_info.size();ii++){
          auto particle = twoplanes.second.softer_constituents_info.at(ii);
          treeEvent.push_back("particle4_pt" + suffix, particle.pt);
          treeEvent.push_back("particle4_eta" + suffix, particle.eta);
          treeEvent.push_back("particle4_phi" + suffix,  particle.phi);
          treeEvent.push_back("particle4_e" + suffix,  particle.e);
          treeEvent.push_back("particle4_charge" + suffix, particle.charge);
          treeEvent.push_back("particle4_pid" + suffix, particle.pdgid);
          treeEvent.push_back("particle4_jetid" + suffix, i);
        }
        

      }
      treeEvents.treeEvents.push_back(treeEvent);
    }
    treeEvents.treeEvent_backup = treeEvent_template;
    return treeEvents;
  }
  static DataFormat ExtractFeaturesFromPlanes(DataFormat dataFormat,
                                              string suffix = "") {
    DataFormat output;
    output.twoplanes = dataFormat.twoplanes;
    output.treeEvents = FormatFeature(
        dataFormat.twoplanes, dataFormat.treeEvents.treeEvent_backup, suffix);

    return output;
  }
  static DataFormat concatenateDataColumn(DataFormat data0, DataFormat data1) {
    DataFormat concatenateData;
    concatenateData.treeEvents = data0.treeEvents + data1.treeEvents;
    return concatenateData;
  }
  static DataFormat concatenateDataRow(DataFormat &data0, DataFormat &data1,
                                       bool addtofirst = false) {
    DataFormat concatenateData;
    if (addtofirst) {
      CommonTool::concatenateToFirstVect(data0.treeEvents.treeEvents,
                                         data1.treeEvents.treeEvents);
      CommonTool::concatenateToFirstVect(data0.twoplanes, data1.twoplanes);
      return concatenateData;
    }
    concatenateData.treeEvents.treeEvents = CommonTool::concatenate(
        data0.treeEvents.treeEvents, data1.treeEvents.treeEvents);
    concatenateData.twoplanes =
        CommonTool::concatenate(data0.twoplanes, data1.twoplanes);
    return concatenateData;
  }

  static bool AddFeature(DataFormat &features, string newfeaturename,
                         int newfeaturevalue) {
    for (int i = 0; i < features.treeEvents.treeEvents.size(); i++) {
      features.treeEvents.treeEvents.at(i).addBranches(newfeaturename + "/I");
      features.treeEvents.treeEvents.at(i)[newfeaturename] = newfeaturevalue;
    }
    return 1;
  }
  static bool AddFeature(DataFormat &features, string newfeaturename,
                         vector<double> newfeaturevalue) {
    for (int i = 0; i < features.treeEvents.treeEvents.size(); i++) {
      features.treeEvents.treeEvents.at(i).addBranches(newfeaturename + "/I");
      features.treeEvents.treeEvents.at(i)[newfeaturename] =
          newfeaturevalue.at(i);
    }
    return 1;
  }
  static bool AddFeature(DataFormat &features, string newfeaturename,
                         vector<vector<int>> newfeaturevalue) {
    for (int i = 0; i < features.treeEvents.treeEvents.size(); i++) {
      features.treeEvents.treeEvents.at(i).addBranches(newfeaturename + "/vI");
      features.treeEvents.treeEvents.at(i)[newfeaturename] =
          newfeaturevalue.at(i);
    }
    return 1;
  }
  static std::vector<std::vector<double>>
  transpose(const std::vector<std::vector<double>> &matrix) {
    if (matrix.empty())
      return {};

    size_t numRows = matrix.size();
    size_t numCols = matrix[0].size();

    // Create a new 2D vector with dimensions swapped
    std::vector<std::vector<double>> transposed(numCols,
                                                std::vector<double>(numRows));

    // Fill the transposed matrix
    for (size_t i = 0; i < numRows; ++i) {
      for (size_t j = 0; j < numCols; ++j) {
        transposed[j][i] = matrix[i][j];
      }
    }

    return transposed;
  }
  static std::vector<double>
  convertToIntVector(const std::vector<int> &intVector) {
    // Initialize a vector of doubles with the same size as intVector
    std::vector<double> doubleVector;
    doubleVector.reserve(intVector.size());

    // Convert each int to double
    for (int value : intVector) {
      doubleVector.push_back(static_cast<double>(value));
    }

    return doubleVector;
  }
};