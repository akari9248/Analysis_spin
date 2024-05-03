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
double DeltaPhi(std::vector<float> features){
    TLorentzVector j1, j3, j4;
    j1.SetPtEtaPhiE(features[0], features[1], features[2], features[3]);
    j3.SetPtEtaPhiE(features[4], features[5], features[6], features[7]);
    j4.SetPtEtaPhiE(features[8], features[9], features[10], features[11]);
    TVector3 n1 = (j3.Vect()).Cross(j4.Vect()); // j3 和 j4 的叉积给出第一个平面的法向量
    TVector3 n2 = (j3.Vect() + j4.Vect()).Cross(j1.Vect()); // (j3+j4) 和 j1 的叉积给出第二个平面的法向量
    n1 = n1.Unit();
    n2 = n2.Unit();
    double cos_angle = abs(n1.Dot(n2));
    double angle_radians = TMath::ACos(cos_angle); // 返回的角度是弧度
    return angle_radians;
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
      while (j0.has_parents(j1, j2)) {
        if (j1.pt2() > j2.pt2() && j2.has_parents(j3, j4)) {
          features.push_back(j1.pt());
          features.push_back(j1.eta());
          features.push_back(j1.phi());
          features.push_back(j1.e());
          features.push_back(j3.pt());
          features.push_back(j3.eta());
          features.push_back(j3.phi());
          features.push_back(j3.e());
          features.push_back(j4.pt());
          features.push_back(j4.eta());
          features.push_back(j4.phi());
          features.push_back(j4.e());
          j0 = j1;
        } else if (j1.pt2() < j2.pt2() && j1.has_parents(j3, j4)) {
          features.push_back(j2.pt());
          features.push_back(j2.eta());
          features.push_back(j2.phi());
          features.push_back(j2.e());
          features.push_back(j3.pt());
          features.push_back(j3.eta());
          features.push_back(j3.phi());
          features.push_back(j3.e());
          features.push_back(j4.pt());
          features.push_back(j4.eta());
          features.push_back(j4.phi());
          features.push_back(j4.e());
          j0 = j2;
        }else{
            j0 = (j1.pt2() > j2.pt2()) ? j1 : j2;
            continue;
        }
        assert(features.size() == 12);
        features.push_back(DeltaPhi(features));
        xdata.push_back(features);
        ydata.push_back(label);
        features.clear();
      }
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
  std::ofstream csv_file("combined_data_CA_soft.csv");
  if (!csv_file.is_open()) {
    std::cerr << "Error: Unable to open file." << std::endl;
    return 1;
  }

  // 写入列标题（可选）
  for (size_t i = 0; i < xdata_combined[0].size(); ++i) {
    csv_file << "Feature_" << i << ",";
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