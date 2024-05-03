#include <TChain.h>
#include <TFile.h>
#include <TLorentzVector.h>
#include <TTree.h>
#include <fastjet/ClusterSequence.hh>
#include <fastjet/PseudoJet.hh>
#include <vector>
#include <tuple>
#include <iostream>
#include <cassert>
#include <fstream>
#include "/home/zlin/higgs/include/Process_bar.h"
// 使用FastJet的命名空间
using namespace fastjet;
using namespace std;
// 加载数据和标签的函数，返回一个pair包含数据和标签
std::pair<std::vector<std::vector<float>>, std::vector<int>> LoadData(TChain& chain, int label, int entries) {
    std::vector<std::vector<float>> xdata;
    std::vector<int> ydata;

    std::vector<double>* pt_particle = nullptr;
    std::vector<double>* eta_particle = nullptr;
    std::vector<double>* phi_particle = nullptr;
    std::vector<double>* energy_particle = nullptr;

    // 设置TChain分支的地址
    chain.SetBranchAddress("Pt_particle", &pt_particle);
    chain.SetBranchAddress("Eta_particle", &eta_particle);
    chain.SetBranchAddress("Phi_particle", &phi_particle);
    chain.SetBranchAddress("Energy_particle", &energy_particle);
    ProcessBar ProcessBar(entries);
    // 遍历entries
    for (int entry = 0; entry < std::min(entries, (int)chain.GetEntries()); ++entry) {
        ProcessBar.show2(entry);
        chain.GetEntry(entry);
        std::vector<PseudoJet> particles;
        for (size_t i = 0; i < pt_particle->size(); ++i) {
            TLorentzVector p;
            p.SetPtEtaPhiE(pt_particle->at(i), eta_particle->at(i), phi_particle->at(i), energy_particle->at(i));
            PseudoJet particle = PseudoJet(p.Px(), p.Py(), p.Pz(), p.Energy());
            //particle.set_user_info(new ParticleInfo(tchain.DaughterPdgId->at(i),i,p.Px(),p.Py(),p.Pz(),p.Energy()));       
            particles.push_back(particle);
        }
        // 使用FastJet聚类
        JetDefinition jet_def(antikt_algorithm, 0.8); // 使用 anti-k_t 算法
        ClusterSequence cs(particles, jet_def);
        std::vector<PseudoJet> jets = cs.inclusive_jets(20.0); // ptmin = 20.0
        // 对jets进行操作
        for (auto& jet : jets) {
            // 一些条件检查
            if (jet.pt() > 450 && std::abs(jet.eta()) < 2.5) {
                continue;
            }

            std::vector<PseudoJet> constituents = jet.constituents();
            std::vector<float> features;

            // 对于每个jet的组成部分
            for (size_t i = 0; i < constituents.size(); ++i) {
                for (size_t j = 0; j < constituents.size(); ++j) {
                    for (size_t k = 0; k < constituents.size(); ++k) {
                        auto particle0 = constituents[i];
                        auto particle1 = constituents[j];
                        auto particle2 = constituents[k];
                        if((i==j)||(i==k)||(j==k)) continue;
                        if (particle0.pt() < 10 || particle1.pt() < 10 || particle2.pt() < 10) {
                            continue;
                        }

                        features.push_back(particle0.pt());
                        features.push_back(particle0.eta());
                        features.push_back(particle0.phi());
                        features.push_back(particle0.e());
                        features.push_back(particle1.pt());
                        features.push_back(particle1.eta());
                        features.push_back(particle1.phi());
                        features.push_back(particle1.e());
                        features.push_back(particle2.pt());
                        features.push_back(particle2.eta());
                        features.push_back(particle2.phi());
                        features.push_back(particle2.e());

                        assert(features.size() == 12);
                        xdata.push_back(features);
                        ydata.push_back(label);
                        features.clear();
                    }
                }
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
        chain_on.Add(Form("/storage/xiaoxue/code/git_file/QCDAnalysis/OfflineExamples/data/herwig/Decay_1_spinon_450/chunk%i/Decay_1_spinon_450.root/JetsAndDaughters", i));
        chain_off.Add(Form("/storage/xiaoxue/code/git_file/QCDAnalysis/OfflineExamples/data/herwig/Decay_1_spinoff_450/chunk%i/Decay_1_spinoff_450.root/JetsAndDaughters", i));
    }
    std::vector<std::vector<float>> xdata_on, xdata_off;
    std::vector<int> ydata_on, ydata_off;
    // 初始化空的列表来存储数据和标签
     std::tie(xdata_on, ydata_on) = LoadData(chain_on, 1, 100000);
   std::tie(xdata_off, ydata_off) = LoadData(chain_off, 0, 100000);
    std::vector<std::vector<float>> xdata_combined = xdata_on;
    xdata_combined.insert(xdata_combined.end(), xdata_off.begin(), xdata_off.end());
    std::vector<int> ydata_combined = ydata_on;
    ydata_combined.insert(ydata_combined.end(), ydata_off.begin(), ydata_off.end());

    // 存储到CSV文件
    std::ofstream csv_file("combined_data.csv");
    if (!csv_file.is_open()) {
        std::cerr << "Error: Unable to open file." << std::endl;
        return 1;
    }

    // 写入列标题（可选）
    for (size_t i = 0; i < xdata_combined[0].size(); ++i) {
        csv_file << "Feature_" << i << ",";
    }
    csv_file << "Label\n";

    // 写入数据和标签
    for (size_t i = 0; i < xdata_combined.size(); ++i) {
        for (const auto& val : xdata_combined[i]) {
            csv_file << val << ",";
        }
        csv_file << ydata_combined[i] << "\n";
    }
    csv_file.close();

    return 0;
}