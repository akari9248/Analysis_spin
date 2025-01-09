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

struct graphs_CMSMC
{
  int num = 100;
  TH1D *score_distribute_gen_qq = new TH1D(("score_distribute_gen_qq" + generateRandomSuffix()).c_str(), "score_distribute_gen_qq", num, 0, 1);
  TH1D *score_distribute_reco_qq = new TH1D(("score_distribute_reco_qq" + generateRandomSuffix()).c_str(), "score_distribute_reco_qq", num, 0, 1);
  TH2D *phi_score_gen_qq = new TH2D(("phi_score_gen_qq" + generateRandomSuffix()).c_str(), "phi_score_gen_qq", 100, 0, M_PI, num, 0, 1);
  TH2D *phi_genscore_reco_qq = new TH2D(("phi_genscore_reco_qq" + generateRandomSuffix()).c_str(), "phi_genscore_reco_qq", 100, 0, M_PI, num, 0, 1);
  TH2D *phi_recoscore_reco_qq = new TH2D(("phi_recoscore_reco_qq" + generateRandomSuffix()).c_str(), "phi_recoscore_reco_qq", 100, 0, M_PI, num, 0, 1);
  TH2D *dphi12_score_gen_qq = new TH2D(("dphi12_score_gen_qq" + generateRandomSuffix()).c_str(), "dphi12_score_gen_qq", 100, 0, M_PI, num, 0, 1);
  TH2D *dphi12_genscore_reco_qq = new TH2D(("dphi12_genscore_reco_qq" + generateRandomSuffix()).c_str(), "dphi12_genscore_reco_qq", 100, 0, M_PI, num, 0, 1);
  TH2D *dphi12_recoscore_reco_qq = new TH2D(("dphi12_recoscore_reco_qq" + generateRandomSuffix()).c_str(), "dphi12_recoscore_reco_qq", 100, 0, M_PI, num, 0, 1);

  TH1D *score_distribute_gen_gg = new TH1D(("score_distribute_gen_gg" + generateRandomSuffix()).c_str(), "score_distribute_gen_gg", num, 0, 1);
  TH1D *score_distribute_reco_gg = new TH1D(("score_distribute_reco_gg" + generateRandomSuffix()).c_str(), "score_distribute_reco_gg", num, 0, 1);
  TH2D *phi_score_gen_gg = new TH2D(("phi_score_gen_gg" + generateRandomSuffix()).c_str(), "phi_score_gen_gg", 100, 0, M_PI, num, 0, 1);
  TH2D *phi_genscore_reco_gg = new TH2D(("phi_genscore_reco_gg" + generateRandomSuffix()).c_str(), "phi_genscore_reco_gg", 100, 0, M_PI, num, 0, 1);
  TH2D *phi_recoscore_reco_gg = new TH2D(("phi_recoscore_reco_gg" + generateRandomSuffix()).c_str(), "phi_recoscore_reco_gg", 100, 0, M_PI, num, 0, 1);
  TH2D *dphi12_score_gen_gg = new TH2D(("dphi12_score_gen_gg" + generateRandomSuffix()).c_str(), "dphi12_score_gen_gg", 100, 0, M_PI, num, 0, 1);
  TH2D *dphi12_genscore_reco_gg = new TH2D(("dphi12_genscore_reco_gg" + generateRandomSuffix()).c_str(), "dphi12_genscore_reco_gg", 100, 0, M_PI, num, 0, 1);
  TH2D *dphi12_recoscore_reco_gg = new TH2D(("dphi12_recoscore_reco_gg" + generateRandomSuffix()).c_str(), "dphi12_recoscore_reco_gg", 100, 0, M_PI, num, 0, 1);
};

class Base_CMSMC
{
public:
  Base_CMSMC(TString input_file)
  {
    t = new TChain();
    TString name = input_file + "/*.root/DNNTrainTree";
    t->Add(name);
    t->SetBranchAddress("Genscore0", &Genscore0);
    t->SetBranchAddress("Genscore1", &Genscore1);
    t->SetBranchAddress("Genscore2", &Genscore2);
    t->SetBranchAddress("Genscore3", &Genscore3);
    t->SetBranchAddress("GenPhi2", &GenPhi2);
    t->SetBranchAddress("GendPhi12_X2", &GendPhi12_X2);
    t->SetBranchAddress("MatchedRecoPhi", &MatchedRecoPhi);

    t->SetBranchAddress("Recoscore0", &Recoscore0);
    t->SetBranchAddress("Recoscore1", &Recoscore1);
    t->SetBranchAddress("Recoscore2", &Recoscore2);
    t->SetBranchAddress("Recoscore3", &Recoscore3);
    t->SetBranchAddress("Recojpt", &Recojpt);
    t->SetBranchAddress("Recopt2", &Recopt2);
    t->SetBranchAddress("RecoPhi2", &RecoPhi2);
    t->SetBranchAddress("RecodPhi12_X2", &RecodPhi12_X2);

    t->SetBranchAddress("GeneratorWeight", &generator_weight);
  }

  void SetWeight(std::vector<double> input_weights_qq, std::vector<double> input_weights_gg)
  {
    weights_qq = input_weights_qq;
    weights_gg = input_weights_gg;
  }

  graphs_CMSMC GetBaseHist(int input_entries = -1)
  {
    graphs_CMSMC graphs;
    int entries = t->GetEntries();
    if (entries < input_entries)
      throw std::runtime_error(TString::Format("There are not enough events! Max events num %d", entries));
    if (input_entries != -1)
      entries = input_entries;
    ProgressBar process1(entries);
    int equal = 0;
    int noequal = 0;
    for (int k = 0; k < entries; k++)
    {
      process1.update(k + 1);
      t->GetEntry(k);
      int gennum = Genscore0->size();
      for (int i = 0; i < gennum; i++)
      {
        double genscore0 = Genscore0->at(i);
        double genscore1 = Genscore1->at(i);
        double genscore2 = Genscore2->at(i);
        double genscore3 = Genscore3->at(i);
        double genscore_qq, genscore_gg;
        // clang-format off
        genscore_qq = genscore2 * weights_qq.at(2) / (genscore0 * weights_qq.at(0) + genscore1 * weights_qq.at(1) + 
                                                      genscore2 * weights_qq.at(2) + genscore3 * weights_qq.at(3));
        genscore_gg = genscore1 * weights_gg.at(1) / (genscore0 * weights_gg.at(0) + genscore1 * weights_gg.at(1) + 
                                                      genscore2 * weights_gg.at(2) + genscore3 * weights_gg.at(3));
        // clang-format on

        graphs.score_distribute_gen_qq->Fill(genscore_qq, generator_weight);
        graphs.score_distribute_gen_gg->Fill(genscore_gg, generator_weight);
        graphs.phi_score_gen_qq->Fill(GenPhi2->at(i), genscore_qq, generator_weight);
        graphs.phi_score_gen_gg->Fill(GenPhi2->at(i), genscore_gg, generator_weight);
        graphs.dphi12_score_gen_qq->Fill(GendPhi12_X2->at(i), genscore_qq, generator_weight);
        graphs.dphi12_score_gen_gg->Fill(GendPhi12_X2->at(i), genscore_gg, generator_weight);

        int reconum = Recoscore0->size();
        for (int j = 0; j < reconum; j++)
        {
          if (MatchedRecoPhi->at(i) == RecoPhi2->at(j))
          {
            if (Recojpt->at(j) < 600 || Recopt2->at(j) < 130)
              continue;
            double recoscore0 = Recoscore0->at(j);
            double recoscore1 = Recoscore1->at(j);
            double recoscore2 = Recoscore2->at(j);
            double recoscore3 = Recoscore3->at(j);
            double recoscore_qq, recoscore_gg;
            // clang-format off
            recoscore_qq = recoscore2 * weights_qq.at(2) / (recoscore0 * weights_qq.at(0) + recoscore1 * weights_qq.at(1) + 
                                                            recoscore2 * weights_qq.at(2) + recoscore3 * weights_qq.at(3));

            recoscore_gg = recoscore1 * weights_gg.at(1) / (recoscore0 * weights_gg.at(0) + recoscore1 * weights_gg.at(1) + 
                                                            recoscore2 * weights_gg.at(2) + recoscore3 * weights_gg.at(3));
            // clang-format on

            graphs.score_distribute_reco_qq->Fill(recoscore_qq, generator_weight);
            graphs.score_distribute_reco_gg->Fill(recoscore_gg, generator_weight);
            graphs.phi_recoscore_reco_qq->Fill(RecoPhi2->at(j), recoscore_qq, generator_weight);
            graphs.phi_recoscore_reco_gg->Fill(RecoPhi2->at(j), recoscore_gg, generator_weight);
            graphs.phi_genscore_reco_qq->Fill(RecoPhi2->at(j), genscore_qq, generator_weight);
            graphs.phi_genscore_reco_gg->Fill(RecoPhi2->at(j), genscore_gg, generator_weight);
            graphs.dphi12_recoscore_reco_qq->Fill(RecoPhi2->at(j), recoscore_qq, generator_weight);
            graphs.dphi12_recoscore_reco_gg->Fill(RecoPhi2->at(j), recoscore_gg, generator_weight);
            graphs.dphi12_genscore_reco_qq->Fill(RecoPhi2->at(j), genscore_qq, generator_weight);
            graphs.dphi12_genscore_reco_gg->Fill(RecoPhi2->at(j), genscore_gg, generator_weight);
            break;
          }
        }
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

  std::vector<double> *Genscore0 = new std::vector<double>;
  std::vector<double> *Genscore1 = new std::vector<double>;
  std::vector<double> *Genscore2 = new std::vector<double>;
  std::vector<double> *Genscore3 = new std::vector<double>;
  std::vector<double> *GenPhi2 = new std::vector<double>;
  std::vector<double> *GendPhi12_X2 = new std::vector<double>;
  std::vector<double> *MatchedRecoPhi = new std::vector<double>;

  std::vector<double> *Recoscore0 = new std::vector<double>;
  std::vector<double> *Recoscore1 = new std::vector<double>;
  std::vector<double> *Recoscore2 = new std::vector<double>;
  std::vector<double> *Recoscore3 = new std::vector<double>;
  std::vector<double> *Recojpt = new std::vector<double>;
  std::vector<double> *Recopt2 = new std::vector<double>;
  std::vector<double> *RecoPhi2 = new std::vector<double>;
  std::vector<double> *RecodPhi12_X2 = new std::vector<double>;
  double generator_weight;
};