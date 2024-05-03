#include "/home/zlin/higgs/include/Process_bar.h"
#include <TChain.h>
#include <TFile.h>
#include <TLorentzVector.h>
#include <TTree.h>
#include <cassert>
#include <fastjet/ClusterSequence.hh>
#include <fastjet/PseudoJet.hh>
#include <fstream>
#include <iostream>
#include <tuple>
#include <vector>
#include <algorithm>
#include <random>
// 使用FastJet的命名空间
using namespace fastjet;
using namespace std;
// 加载数据和标签的函数，返回一个pair包含数据和标签
vector<double> DeltaPhi(std::vector<float> features){
    TLorentzVector j1,j2, j3, j4;
    j1.SetPtEtaPhiE(features[0], features[1], features[2], features[3]);
    j2.SetPtEtaPhiE(features[4], features[5], features[6], features[7]);
    j3.SetPtEtaPhiE(features[8], features[9], features[10], features[11]);
    j4.SetPtEtaPhiE(features[12], features[13], features[14], features[15]);
    TVector3 n1 = (j1.Vect()).Cross(j2.Vect()); 
    TVector3 n2 = (j3.Vect()).Cross(j4.Vect()); 
    n1 = n1.Unit();
    n2 = n2.Unit();
    double phi = abs(n1.Phi() - n2.Phi());
    double cos_angle = abs(n1.Dot(n2));
    if((n1.Cross(n2)).Dot(j3.Vect())<0){
      cos_angle = -1.0*cos_angle;
      phi= -1.0*phi;
    }
    double angle_radians = TMath::ACos(cos_angle); 
    return {n1.X(),n1.Y(),n1.Z(),n2.X(),n2.Y(),n2.Z(),angle_radians,phi};
}
struct JetVariables {
    PseudoJet harder;
    PseudoJet softer;
    double theta;
    double deltaR;
    double z;
    double kt;
};

std::pair<JetVariables, JetVariables> findPrimaryAndSecondaryJets(PseudoJet& j0) {
    PseudoJet j1,j2,j3,j4;
    JetVariables maxPrimary = {PseudoJet(), PseudoJet(), 0.0,0.0, 0.0, 0.0};
    JetVariables maxSecondary = {PseudoJet(), PseudoJet(), 0.0,0.0, 0.0, 0.0};
    while (j0.has_parents(j1, j2)) {
        PseudoJet primaryHarder = (j1.pt() > j2.pt()) ? j1 : j2;
        PseudoJet primarySofter = (j1.pt() > j2.pt()) ? j2 : j1;
        double primaryTheta = primaryHarder.delta_phi_to(primarySofter);
        double primaryDeltaR= primaryHarder.delta_R(primarySofter);
        double primaryZ = primarySofter.pt() / (primarySofter.pt() + primaryHarder.pt());
        double primaryKt = primarySofter.pt() * primaryDeltaR;
        //double primaryKt = primarySofter.modp() * sin(primaryTheta);
        // Update maxPrimary if this kt is larger
        if (primaryKt > maxPrimary.kt) {
            maxPrimary = {primaryHarder, primarySofter, primaryTheta,primaryDeltaR, primaryZ, primaryKt};
        }
        while(primarySofter.has_parents(j3, j4)) {
            PseudoJet secondaryHarder = (j3.pt() > j4.pt()) ? j3 : j4;
            PseudoJet secondarySofter = (j3.pt() > j4.pt()) ? j4 : j3;
            double secondaryTheta = secondaryHarder.delta_phi_to(secondarySofter);
            double secondaryDeltaR = secondaryHarder.delta_phi_to(secondarySofter);
            double secondaryZ = secondarySofter.pt() / (secondarySofter.pt() + secondaryHarder.pt());
            double secondaryKt = secondarySofter.pt() * secondaryDeltaR;
            //double secondaryKt = primarySofter.modp() * sin(secondaryTheta);
            if (secondaryKt > maxSecondary.kt) {
                maxSecondary = {secondaryHarder, secondarySofter, secondaryTheta,secondaryDeltaR, secondaryZ, secondaryKt};
            }
            primarySofter = secondaryHarder;
        }

        j0 = primaryHarder; // Move to the next iteration with the harder subjet
    }

    return std::make_pair(maxPrimary, maxSecondary);
}
std::pair<std::vector<std::vector<float>>, std::vector<int>>
LoadData(TChain &chain, int label, int entries) {
  std::vector<std::vector<float>> xdata;
  std::vector<int> ydata;

  std::vector<double> *pt_particle = nullptr;
  std::vector<double> *eta_particle = nullptr;
  std::vector<double> *phi_particle = nullptr;
  std::vector<double> *energy_particle = nullptr;

  // 设置TChain分支的地址
  chain.SetBranchAddress("Pt_particle", &pt_particle);
  chain.SetBranchAddress("Eta_particle", &eta_particle);
  chain.SetBranchAddress("Phi_particle", &phi_particle);
  chain.SetBranchAddress("Energy_particle", &energy_particle);
  ProcessBar ProcessBar(entries);
  // 遍历entries
  for (int entry = 0; entry < std::min(entries, (int)chain.GetEntries());
       ++entry) {
    ProcessBar.show2(entry);
    chain.GetEntry(entry);
    std::vector<PseudoJet> particles;
    for (size_t i = 0; i < pt_particle->size(); ++i) {
      TLorentzVector p;
      p.SetPtEtaPhiE(pt_particle->at(i), eta_particle->at(i),
                     phi_particle->at(i), energy_particle->at(i));
      PseudoJet particle = PseudoJet(p.Px(), p.Py(), p.Pz(), p.Energy());
      // particle.set_user_info(new
      // ParticleInfo(tchain.DaughterPdgId->at(i),i,p.Px(),p.Py(),p.Pz(),p.Energy()));
      particles.push_back(particle);
    }
    // 使用FastJet聚类
    JetDefinition jet_def(antikt_algorithm, 0.8); // 使用 anti-k_t 算法
    ClusterSequence cs(particles, jet_def);
    std::vector<PseudoJet> jets = cs.inclusive_jets(20.0); // ptmin = 20.0
    // 对jets进行操作
    for (auto &jet : jets) {
      // 一些条件检查
      if (jet.pt() > 450 && std::abs(jet.eta()) < 2.5) {
        continue;
      }

      std::vector<PseudoJet> constituents = jet.constituents();
      JetDefinition jet_def_CA(cambridge_algorithm,
                               JetDefinition::max_allowable_R);
      ClusterSequence cs_CA(constituents, jet_def_CA);
      vector<PseudoJet> jets_CA = sorted_by_pt(cs_CA.inclusive_jets());
      PseudoJet jet_CA = jets_CA[0];
      std::vector<float> features;
      PseudoJet j0, j1, j2, j3, j4;
      j0 = jet_CA;
      double Q=j0.e();
      std::pair<JetVariables, JetVariables> twoplane=findPrimaryAndSecondaryJets(j0);
      if(twoplane.first.harder.pt()==0||twoplane.first.softer.pt()==0) continue;
      if(twoplane.second.harder.pt()==0||twoplane.second.softer.pt()==0) continue;
      features.push_back(twoplane.first.harder.pt());
      features.push_back(twoplane.first.harder.eta());
      features.push_back(twoplane.first.harder.phi());
      features.push_back(twoplane.first.harder.e());
      features.push_back(twoplane.first.softer.pt());
      features.push_back(twoplane.first.softer.eta());
      features.push_back(twoplane.first.softer.phi());
      features.push_back(twoplane.first.softer.e());

      features.push_back(twoplane.second.harder.pt());
      features.push_back(twoplane.second.harder.eta());
      features.push_back(twoplane.second.harder.phi());
      features.push_back(twoplane.second.harder.e());
      features.push_back(twoplane.second.softer.pt());
      features.push_back(twoplane.second.softer.eta());
      features.push_back(twoplane.second.softer.phi());
      features.push_back(twoplane.second.softer.e());
      
      features.push_back(twoplane.first.z);
      features.push_back(twoplane.first.kt);
      features.push_back(twoplane.first.theta);
      features.push_back(twoplane.first.deltaR);
      features.push_back((twoplane.first.harder.e()*twoplane.first.softer.e())*1.0/Q/Q);
      features.push_back(twoplane.second.z);
      features.push_back(twoplane.second.kt);
      features.push_back(twoplane.second.theta);
      features.push_back(twoplane.second.deltaR);
      features.push_back((twoplane.second.harder.e()*twoplane.second.softer.e())*1.0/Q/Q);
      assert(features.size() == 26);
      auto phi = DeltaPhi(features);
      features.push_back(phi.at(0));
      features.push_back(phi.at(1));
      features.push_back(phi.at(2));
      features.push_back(phi.at(3));
      features.push_back(phi.at(4));
      features.push_back(phi.at(5));
      features.push_back(phi.at(6));
      features.push_back(phi.at(7));
      xdata.push_back(features);
      ydata.push_back(label);
      features.clear();

    }
  }
  return {xdata, ydata};
}

int main() {
  // 创建TChain
  TChain chain_on("on");
  TChain chain_off("off");

  // 添加ROOT文件到TChain
  for (int i = 1; i <= 100; ++i) {
    chain_on.Add(Form("/storage/xiaoxue/code/git_file/QCDAnalysis/"
                      "OfflineExamples/data/herwig/Decay_1_spinon_450/"
                      "chunk%i/Decay_1_spinon_450.root/JetsAndDaughters",
                      i));
    chain_off.Add(Form("/storage/xiaoxue/code/git_file/QCDAnalysis/"
                       "OfflineExamples/data/herwig/Decay_1_spinoff_450/"
                       "chunk%i/Decay_1_spinoff_450.root/JetsAndDaughters",
                       i));
  }
  std::vector<std::vector<float>> xdata_on, xdata_off;
  std::vector<int> ydata_on, ydata_off;
  // 初始化空的列表来存储数据和标签
  std::tie(xdata_on, ydata_on) = LoadData(chain_on, 1, 1000000);
  std::tie(xdata_off, ydata_off) = LoadData(chain_off, 0, 1000000);
  std::vector<std::vector<float>> xdata_combined = xdata_on;
  xdata_combined.insert(xdata_combined.end(), xdata_off.begin(),
                        xdata_off.end());
  std::vector<int> ydata_combined = ydata_on;
  ydata_combined.insert(ydata_combined.end(), ydata_off.begin(),
                        ydata_off.end());

  // 存储到CSV文件
  std::ofstream csv_file("combined_data_CA_lundplane.csv");
  if (!csv_file.is_open()) {
    std::cerr << "Error: Unable to open file." << std::endl;
    return 1;
  }

  vector<TString> feature_type = {"pt1","eta1","phi1","e1","pt2","eta2","phi2","e2","pt3","eta3","phi3","e3","pt4","eta4","phi4","e4","z1","kt1","theta1","deltaR1","eec1","z2","kt2","theta2","deltaR2","eec2","n1x","n1y","n1z","n2x","n2y","n2z","phi1","phi2"};
  for (size_t i = 0; i < xdata_combined[0].size(); ++i) {
    csv_file << feature_type.at(i) << ",";
  }
  csv_file << "Label\n";

  // 创建索引数组
    std::vector<size_t> indices(xdata_combined.size());
    std::iota(indices.begin(), indices.end(), 0); // 填充索引

    // 创建随机数生成器
    std::random_device rd;
    std::mt19937 g(rd());

    // 打乱索引
    std::shuffle(indices.begin(), indices.end(), g);

    // 按照乱序索引写入数据
    for (auto idx : indices) {
        for (const auto &val : xdata_combined[idx]) {
            csv_file << val << ",";
        }
        csv_file << ydata_combined[idx] << "\n";
    }

  return 0;
}