#pragma once
#include "iostream"
#include "TCanvas.h"
#include "TPaveText.h"
#include "TString.h"
#include "TChain.h"
#include "TGraph.h"
#include "TH1D.h"
#include "TH2D.h"
#include <random>

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

struct graphs_PrivateMC_predict
{
  int num = 100;
  TH1D *score_distribute_qq = new TH1D(("score_distribute_predict_qq" + generateRandomSuffix()).c_str(), "score_distribute_predict_qq", num, 0, 1);
  TH1D *score_distribute_gg = new TH1D(("score_distribute_predict_gg" + generateRandomSuffix()).c_str(), "score_distribute_predict_gg", num, 0, 1);
  TH2D *phi_score_qq = new TH2D(("phi_score_predict_qq" + generateRandomSuffix()).c_str(), "phi_score_predict_qq", 100, 0, M_PI, num, 0, 1);
  TH2D *phi_score_gg = new TH2D(("phi_score_predict_gg" + generateRandomSuffix()).c_str(), "phi_score_predict_gg", 100, 0, M_PI, num, 0, 1);
  TH2D *dphi12_score_qq = new TH2D(("dphi12_score_predict_qq" + generateRandomSuffix()).c_str(), "phi_score_predict_qq", 100, 0, M_PI, num, 0, 1);
  TH2D *dphi12_score_gg = new TH2D(("dphi12_score_predict_gg" + generateRandomSuffix()).c_str(), "phi_score_predict_gg", 100, 0, M_PI, num, 0, 1);
};

class Base_PrivateMC_predict
{
public:
  Base_PrivateMC_predict(TString input_file)
  {
    TString name = input_file + "/*.root/DNNTrainTree";
    t->Add(name);
    t->SetBranchAddress("score0_Hadron", &score0_Hadron);
    t->SetBranchAddress("score1_Hadron", &score1_Hadron);
    t->SetBranchAddress("score2_Hadron", &score2_Hadron);
    t->SetBranchAddress("score3_Hadron", &score3_Hadron);
    t->SetBranchAddress("Phi2_Hadron", &Phi2_Hadron);
    t->SetBranchAddress("dPhi12_X2_Hadron", &dPhi12_X2_Hadron);
  }

  void SetWeight(std::vector<double> input_weights_qq, std::vector<double> input_weights_gg)
  {
    weights_qq = input_weights_qq;
    weights_gg = input_weights_gg;
  }

  graphs_PrivateMC_predict GetBaseHist(int input_entries = -1)
  {
    graphs_PrivateMC_predict graphs;
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
      int jetsnum = score0_Hadron->size();
      for (int i = 0; i < jetsnum; i++)
      {
        double score0 = score0_Hadron->at(i);
        double score1 = score1_Hadron->at(i);
        double score2 = score2_Hadron->at(i);
        double score3 = score3_Hadron->at(i);
        double score_qq, score_gg;

        // clang-format off
        score_qq = score2 * weights_qq.at(2) / (score0 * weights_qq.at(0) + score1 * weights_qq.at(1) + 
                                                score2 * weights_qq.at(2) + score3 * weights_qq.at(3));
        score_gg = score1 * weights_gg.at(1) / (score0 * weights_gg.at(0) + score1 * weights_gg.at(1) + 
                                                score2 * weights_gg.at(2) + score3 * weights_gg.at(3));
        // clang-format on

        graphs.score_distribute_qq->Fill(score_qq);
        graphs.score_distribute_gg->Fill(score_gg);
        graphs.phi_score_qq->Fill(Phi2_Hadron->at(i), score_qq);
        graphs.phi_score_gg->Fill(Phi2_Hadron->at(i), score_gg);
        graphs.dphi12_score_qq->Fill(dPhi12_X2_Hadron->at(i), score_qq);
        graphs.dphi12_score_gg->Fill(dPhi12_X2_Hadron->at(i), score_gg);
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

  std::vector<double> *score0_Hadron = new std::vector<double>;
  std::vector<double> *score1_Hadron = new std::vector<double>;
  std::vector<double> *score2_Hadron = new std::vector<double>;
  std::vector<double> *score3_Hadron = new std::vector<double>;
  std::vector<double> *Phi2_Hadron = new std::vector<double>;
  std::vector<double> *dPhi12_X2_Hadron = new std::vector<double>;
};