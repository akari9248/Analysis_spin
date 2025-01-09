#include "iostream"
#include "TCanvas.h"
#include "TPaveText.h"
#include "TString.h"
#include "TChain.h"
#include "TGraph.h"
#include "TH1D.h"
#include "TH2D.h"
#include <random>
// #include "../include/common_tool.h"
// #include "AnalyzeML.h"

#ifndef PROGRESSBAR_H
#define PROGRESSBAR_H
#include "/storage/shuangyuan/code/headfile/ProgressBar.h"
#endif

#ifndef PLOTRATIO_H
#define PLOTRATIO_H
#include "/storage/shuangyuan/code/headfile/plotratio_beta.h"
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

struct graphs_reweight
{
  int num = 100;
  TH2D *phi_score_gen_qq = new TH2D(("phi_score_gen_qq" + generateRandomSuffix()).c_str(), "phi_score_gen_qq", 100, 0, M_PI, num, 0, 1);
  TH2D *phi_score_reco_qq = new TH2D(("phi_score_reco_qq" + generateRandomSuffix()).c_str(), "phi_score_reco_qq", 100, 0, M_PI, num, 0, 1);
  TH2D *phi_score_gen_gg = new TH2D(("phi_score_gen_gg" + generateRandomSuffix()).c_str(), "phi_score_gen_gg", 100, 0, M_PI, num, 0, 1);
  TH2D *phi_score_reco_gg = new TH2D(("phi_score_reco_gg" + generateRandomSuffix()).c_str(), "phi_score_reco_gg", 100, 0, M_PI, num, 0, 1);
};

class ReWeight
{
public:
  ReWeight(TString CMSMC_path)
  {
    t = new TChain();
    TString name = CMSMC_path + "/*.root/DNNTrainTree";
    t->Add(name);
    t->SetBranchAddress("Genscore0", &Genscore0);
    t->SetBranchAddress("Genscore1", &Genscore1);
    t->SetBranchAddress("Genscore2", &Genscore2);
    t->SetBranchAddress("Genscore3", &Genscore3);
    t->SetBranchAddress("GenPhi2", &GenPhi2);
    t->SetBranchAddress("MatchedRecoPhi", &MatchedRecoPhi);

    t->SetBranchAddress("Recoscore0", &Recoscore0);
    t->SetBranchAddress("Recoscore1", &Recoscore1);
    t->SetBranchAddress("Recoscore2", &Recoscore2);
    t->SetBranchAddress("Recoscore3", &Recoscore3);
    t->SetBranchAddress("RecoPhi2", &RecoPhi2);

    t->SetBranchAddress("GeneratorWeight", &generator_weight);
  }

  void SetWeight(std::vector<double> input_weights_qq, std::vector<double> input_weights_gg)
  {
    weights_qq = input_weights_qq;
    weights_gg = input_weights_gg;
  }

  void reweight(TH2D *Private_off, TH2D *Private_on,
                TString flavour = "qq", TString name = "",
                int input_entries = -1)
  {
    int bins = Private_on->GetYaxis()->GetNbins();
    int entries = t->GetEntries();
    if (entries < input_entries)
      throw std::runtime_error(TString::Format("There are not enough events! Max events num %d", entries));
    if (input_entries != -1)
      entries = input_entries;
    ProgressBar process1(entries * bins);
    int loop = 1;
    TFile *f1 = new TFile(name, "RECREATE");
    
    for (int i = 1; i <= bins; i++)
    {
      double scorecut = Private_off->GetYaxis()->GetBinLowEdge(i);
      TH1D *phi_off = Private_off->ProjectionX("phi_off", i, bins);
      TH1D *phi_on = Private_on->ProjectionX("phi_on", i, bins);
      std::vector<TH1D *> phis = {phi_off, phi_on};
      Plots::Histdispose hists;
      hists.normalize(phis);
      TH1D *phi_ratio = (TH1D *)phi_off->Clone(TString::Format("phi_weight_%.2f", scorecut));
      phi_ratio->Divide(phi_on);
      TString name1 = TString::Format("phi_reweight_gen_%.2f", scorecut);
      TH1D *phi_reweight_gen = new TH1D(name1, name1, 100, 0, M_PI);
      TString name2 = TString::Format("phi_reweight_reco_%.2f", scorecut);
      TH1D *phi_reweight_reco = new TH1D(name2, name2, 100, 0, M_PI);
      for (int k = 0; k < entries; k++)
      {
        process1.update(loop);
        loop++;

        t->GetEntry(k);
        int gennum = Genscore0->size();
        for (int j = 0; j < gennum; j++)
        {
          double genscore0 = Genscore0->at(j);
          double genscore1 = Genscore1->at(j);
          double genscore2 = Genscore2->at(j);
          double genscore3 = Genscore3->at(j);
          double genscore;

          if (flavour == "qq")
          {
            // clang-format off
            genscore = genscore2 * weights_qq.at(2) / (genscore0 * weights_qq.at(0) + genscore1 * weights_qq.at(1) + 
                                                       genscore2 * weights_qq.at(2) + genscore3 * weights_qq.at(3));
            // clang-format on
          }
          if (flavour == "gg")
          {
            // clang-format off
            genscore = genscore1 * weights_gg.at(1) / (genscore0 * weights_gg.at(0) + genscore1 * weights_gg.at(1) + 
                                                       genscore2 * weights_gg.at(2) + genscore3 * weights_gg.at(3));
            // clang-format on
          }
          if (genscore < scorecut)
            continue;
          int phibin = phi_ratio->GetXaxis()->FindBin(GenPhi2->at(j));
          double weight = phi_ratio->GetBinContent(phibin);
          phi_reweight_gen->Fill(GenPhi2->at(j), weight);
          int reconum = Recoscore0->size();
          for (int l = 0; l < reconum; l++)
          {
            if (MatchedRecoPhi->at(j) == RecoPhi2->at(l))
            {
              phi_reweight_reco->Fill(RecoPhi2->at(l), weight);
              break;
            }
          }
        }
      }
      f1->cd();
      phi_ratio->Write();
      phi_reweight_gen->Write();
      phi_reweight_reco->Write();
    }
    f1->Close();
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
  std::vector<double> *MatchedRecoPhi = new std::vector<double>;

  std::vector<double> *Recoscore0 = new std::vector<double>;
  std::vector<double> *Recoscore1 = new std::vector<double>;
  std::vector<double> *Recoscore2 = new std::vector<double>;
  std::vector<double> *Recoscore3 = new std::vector<double>;
  std::vector<double> *RecoPhi2 = new std::vector<double>;
  double generator_weight;
};