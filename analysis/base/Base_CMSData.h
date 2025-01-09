#pragma once
#include "iostream"
#include "TCanvas.h"
#include "TPaveText.h"
#include "TString.h"
#include "TChain.h"
#include "TGraph.h"
#include "TH1D.h"
#include "TH2D.h"

#ifndef PROGRESSBAR_H
#define PROGRESSBAR_H
#include "/storage/shuangyuan/code/headfile/ProgressBar.h"
#endif

#ifndef BASE_PRIVATEMC_TRAIN_H
#define BASE_PRIVATEMC_TRAIN_H
std::string generateRandomSuffix()
{
  std::random_device rd;                              // 随机设备
  std::mt19937 gen(rd());                             // 随机数生成器
  std::uniform_int_distribution<int> dis(1, 1000000); // 生成1到1000之间的随机数
  return std::to_string(dis(gen));                    // 将随机数转换为字符串并返回
}
#endif

struct graphs_CMSData
{
  int num = 100;
  TH1D *score_distribute_reco_qq = new TH1D(("score_distribute_reco_qq" + generateRandomSuffix()).c_str(), "score_distribute_reco_qq", num, 0, 1);
  TH2D *phi_score_reco_qq = new TH2D(("phi_score_reco_qq" + generateRandomSuffix()).c_str(), "phi_score_reco_qq", 100, 0, M_PI, num, 0, 1);
  TH2D *dphi12_score_reco_qq = new TH2D(("dphi12_score_reco_qq" + generateRandomSuffix()).c_str(), "dphi12_score_reco_qq", 100, 0, M_PI, num, 0, 1);
  TH1D *score_distribute_reco_gg = new TH1D(("score_distribute_reco_gg" + generateRandomSuffix()).c_str(), "score_distribute_reco_gg", num, 0, 1);
  TH2D *phi_score_reco_gg = new TH2D(("phi_score_reco_gg" + generateRandomSuffix()).c_str(), "phi_score_reco_gg", 100, 0, M_PI, num, 0, 1);
  TH2D *dphi12_score_reco_gg = new TH2D(("dphi12_score_reco_gg" + generateRandomSuffix()).c_str(), "dphi12_score_reco_gg", 100, 0, M_PI, num, 0, 1);
};

class Base_CMSData
{
public:
  Base_CMSData(TString input_file)
  {
    t = new TChain();
    TString name = input_file + "/*.root/DNNTrainTree";
    t->Add(name);
    t->SetBranchAddress("Recoscore0", &Recoscore0);
    t->SetBranchAddress("Recoscore1", &Recoscore1);
    t->SetBranchAddress("Recoscore2", &Recoscore2);
    t->SetBranchAddress("Recoscore3", &Recoscore3);
    t->SetBranchAddress("RecoPhi2", &RecoPhi2);
    t->SetBranchAddress("RecodPhi12_X2", &RecodPhi12_X2);

    t->SetBranchAddress("GeneratorWeight", &generator_weight);
  }

  void SetWeight(std::vector<double> input_weights_qq, std::vector<double> input_weights_gg)
  {
    weights_qq = input_weights_qq;
    weights_gg = input_weights_gg;
  }

  graphs_CMSData GetBaseHist(int input_entries = -1)
  {
    graphs_CMSData graphs;
    int entries = t->GetEntries();
    if (entries < input_entries)
      throw std::runtime_error(TString::Format("There are not enough events! Max events num %d", entries));
    if (input_entries != -1)
      entries = input_entries;
    ProgressBar process1(entries);
    for (int k = 0; k < entries; k++)
    {
      process1.update(k + 1);
      t->GetEntry(k);
      int jetsnum = Recoscore0->size();
      for (int i = 0; i < jetsnum; i++)
      {
        double recoscore0 = Recoscore0->at(i);
        double recoscore1 = Recoscore1->at(i);
        double recoscore2 = Recoscore2->at(i);
        double recoscore3 = Recoscore3->at(i);
        double recoscore_qq, recoscore_gg;

        // clang-format off
        recoscore_qq = recoscore2 * weights_qq.at(2) / (recoscore0 * weights_qq.at(0) + recoscore1 * weights_qq.at(1) + 
                                                        recoscore2 * weights_qq.at(2) + recoscore3 * weights_qq.at(3));

        recoscore_gg = recoscore1 * weights_gg.at(1) / (recoscore0 * weights_gg.at(0) + recoscore1 * weights_gg.at(1) + 
                                                        recoscore2 * weights_gg.at(2) + recoscore3 * weights_gg.at(3));
        // clang-format on
        
        graphs.score_distribute_reco_qq->Fill(recoscore_qq, generator_weight);
        graphs.score_distribute_reco_gg->Fill(recoscore_gg, generator_weight);
        graphs.phi_score_reco_qq->Fill(RecoPhi2->at(i), recoscore_qq, generator_weight);
        graphs.phi_score_reco_gg->Fill(RecoPhi2->at(i), recoscore_gg, generator_weight);
        graphs.dphi12_score_reco_qq->Fill(RecodPhi12_X2->at(i), recoscore_qq, generator_weight);
        graphs.dphi12_score_reco_gg->Fill(RecodPhi12_X2->at(i), recoscore_gg, generator_weight);
      }
    }
    std::cout << std::endl;
    return graphs;
  }

private:
  TChain *t = new TChain();
  TString TPR = "qq";
  std::vector<double> weights_qq = {1, 1, 1, 1};
  std::vector<double> weights_gg = {1, 1, 1, 1};

  std::vector<double> *Recoscore0 = new std::vector<double>;
  std::vector<double> *Recoscore1 = new std::vector<double>;
  std::vector<double> *Recoscore2 = new std::vector<double>;
  std::vector<double> *Recoscore3 = new std::vector<double>;
  std::vector<double> *RecoPhi2 = new std::vector<double>;
  std::vector<double> *RecodPhi12_X2 = new std::vector<double>;

  double generator_weight;
};