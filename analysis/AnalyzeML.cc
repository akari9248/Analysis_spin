#include "iostream"
#include "TCanvas.h"
#include "TPaveText.h"
#include "TString.h"
#include "TChain.h"
#include "TGraph.h"
#include "TH1D.h"
#include "TH2D.h"
#include "AnalyzeML.h"

void AnalyzeML(TString input_plots_roc, TString input_plots_private_herwig, TString input_plots_private_pythia,
               TString input_plots_cms_herwig, TString input_plots_cms_pythia,
               TString input_plots_cms_herwig_reweight, TString input_plots_cms_pythia_reweight,
               TString input_plots_cms_data, TString outputfolder = "",
               TString input_qq_weights = "", TString input_gg_weights = "")
{
  TString Plots_roc = input_plots_roc;
  TString Plots_private_herwig = input_plots_private_herwig;
  TString Plots_private_pythia = input_plots_private_pythia;
  TString Plots_cms_herwig = input_plots_cms_herwig;
  TString Plots_cms_pythia = input_plots_cms_pythia;
  TString Plots_cms_herwig_reweight = input_plots_cms_herwig_reweight;
  TString Plots_cms_pythia_reweight = input_plots_cms_pythia_reweight;
  TString Plots_cms_data = input_plots_cms_data;

  std::vector<double> weights_qq, weights_gg;
  std::stringstream ss1(input_qq_weights.Data());
  std::string token1;
  while (std::getline(ss1, token1, ','))
  {
    weights_qq.push_back(std::stod(token1));
  }
  std::stringstream ss2(input_gg_weights.Data());
  std::string token2;
  while (std::getline(ss2, token2, ','))
  {
    weights_gg.push_back(std::stod(token2));
  }

  TString suffix_qq = "";
  TString suffix_gg = "";
  // if (weights_qq.at(0) != 1 || weights_qq.at(1) != 1 || weights_qq.at(2) != 1 || weights_qq.at(3) != 1)
  //   suffix_qq = TString::Format("_weightqq_%.0f_%.0f_%.0f_%.0f", weights_qq.at(0), weights_qq.at(1), weights_qq.at(2), weights_qq.at(3));
  // if (weights_gg.at(0) != 1 || weights_gg.at(1) != 1 || weights_gg.at(2) != 1 || weights_gg.at(3) != 1)
  //   suffix_gg = TString::Format("_weightgg_%.0f_%.0f_%.0f_%.0f", weights_gg.at(0), weights_gg.at(1), weights_gg.at(2), weights_gg.at(3));

  AnalysisML analysis;

  // GetRoc
  if (Plots_roc != "")
  {
    TFile *f0 = new TFile(Plots_roc);
    TH1D *true_qq = (TH1D *)f0->Get("true_distribute_qq");
    TH1D *true_gg = (TH1D *)f0->Get("true_distribute_gg");
    TH1D *false_qq = (TH1D *)f0->Get("false_distribute_qq");
    TH1D *false_gg = (TH1D *)f0->Get("false_distribute_gg");

    analysis.DrawRoc(true_qq, false_qq, "qq", suffix_qq, outputfolder);
    analysis.DrawRoc(true_gg, false_gg, "gg", suffix_gg, outputfolder);

    f0->Close();
  }

  // Analyzing Private sample
  if (Plots_private_herwig != "" && Plots_private_pythia != "")
  {
    TFile *f1 = new TFile(Plots_private_herwig);
    TFile *f2 = new TFile(Plots_private_pythia);

    TH2D *phi_score_qq_off_herwig = (TH2D *)f1->Get("phi_score_qq_off");
    TH2D *phi_score_qq_on_herwig = (TH2D *)f1->Get("phi_score_qq_on");
    TH2D *phi_score_gg_off_herwig = (TH2D *)f1->Get("phi_score_gg_off");
    TH2D *phi_score_gg_on_herwig = (TH2D *)f1->Get("phi_score_gg_on");

    TH2D *phi_score_qq_off_pythia = (TH2D *)f2->Get("phi_score_qq_off");
    TH2D *phi_score_qq_on_pythia = (TH2D *)f2->Get("phi_score_qq_on");
    TH2D *phi_score_gg_off_pythia = (TH2D *)f2->Get("phi_score_gg_off");
    TH2D *phi_score_gg_on_pythia = (TH2D *)f2->Get("phi_score_gg_on");

    analysis.DrawChi2(phi_score_qq_off_pythia, phi_score_qq_on_pythia, phi_score_qq_off_herwig, phi_score_qq_on_herwig,
                      "qq", suffix_qq, outputfolder);
    analysis.DrawRatio(phi_score_qq_off_pythia, phi_score_qq_on_pythia, phi_score_qq_off_herwig, phi_score_qq_on_herwig,
                       "qq", suffix_qq, outputfolder);
    analysis.DrawFrac(phi_score_qq_off_pythia, phi_score_qq_on_pythia, phi_score_qq_off_herwig, phi_score_qq_on_herwig,
                      "qq", suffix_qq, outputfolder);
    analysis.DrawModel(phi_score_qq_off_pythia, phi_score_qq_on_pythia, phi_score_qq_off_herwig, phi_score_qq_on_herwig,
                       "qq", suffix_qq, outputfolder);
    f1->Close();
    f2->Close();
  }

  // if (Plots_private_herwig != "" && Plots_private_pythia != "" && Plots_cms_data != "")
  // {
  //   TFile *f1 = new TFile(Plots_private_herwig);
  //   TFile *f2 = new TFile(Plots_private_pythia);
  //   TFile *f3 = new TFile(Plots_cms_data);

  //   TH2D *phi_score_qq_off_herwig = (TH2D *)f1->Get("phi_score_qq_off");
  //   TH2D *phi_score_qq_on_herwig = (TH2D *)f1->Get("phi_score_qq_on");
  //   TH2D *phi_score_gg_off_herwig = (TH2D *)f1->Get("phi_score_gg_off");
  //   TH2D *phi_score_gg_on_herwig = (TH2D *)f1->Get("phi_score_gg_on");

  //   TH2D *phi_score_qq_off_pythia = (TH2D *)f2->Get("phi_score_qq_off");
  //   TH2D *phi_score_qq_on_pythia = (TH2D *)f2->Get("phi_score_qq_on");
  //   TH2D *phi_score_gg_off_pythia = (TH2D *)f2->Get("phi_score_gg_off");
  //   TH2D *phi_score_gg_on_pythia = (TH2D *)f2->Get("phi_score_gg_on");

  //   TH2D *phi_score_qq_data = (TH2D *)f3->Get("phi_score_reco_qq");
  //   TH2D *phi_score_gg_data = (TH2D *)f3->Get("phi_score_reco_gg");

  //   analysis.DrawChi2Data(phi_score_qq_off_pythia, phi_score_qq_on_pythia, phi_score_qq_off_herwig, phi_score_qq_on_herwig, phi_score_qq_data,
  //                         "qq", suffix_qq, outputfolder);
  //   // f1->Close();
  //   // f2->Close();
  //   // f3->Close();
  // }

  // if (Plots_cms_herwig != "" && Plots_cms_herwig_reweight != "" && Plots_cms_data != "")
  // {
  //   TFile *f1 = new TFile(Plots_cms_herwig);
  //   TFile *f5 = new TFile(Plots_cms_data);
  //   TH2D *phi_score_gen_qq = (TH2D *)f1->Get("phi_score_gen_qq");
  //   TH2D *phi_score_qq_data = (TH2D *)f5->Get("phi_score_reco_qq");

  //   analysis.DrawReweight(phi_score_gen_qq, Plots_cms_herwig_reweight, phi_score_qq_data, "qq", suffix_qq, outputfolder);
  //   f1->Close();
  //   f5->Close();
  // }
}