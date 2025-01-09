#include "iostream"
#include "TCanvas.h"
#include "TPaveText.h"
#include "TString.h"
#include "TChain.h"
#include "TGraph.h"
#include "TH1D.h"
#include "TH2D.h"
#include "Reweight.h"

void Reweight(TString input_plots_private_herwig, TString input_plots_private_pythia,
              TString input_cms_herwig_path, TString input_cms_pythia_path,
              TString input_cms_data_path, TString outputfolder = "", TString outputname = "",
              TString input_qq_weights = "", TString input_gg_weights = "", int entries = -1)
{
  TString Plots_herwig_path = input_plots_private_herwig;
  TString Plots_pythia_path = input_plots_private_pythia;
  TString CMSherwig_path = input_cms_herwig_path;
  TString CMSpythia_path = input_cms_pythia_path;
  TString CMSdata_path = input_cms_data_path;

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

  if (Plots_herwig_path != "" && CMSherwig_path != "")
  {
    std::cout << "Reweighting CMS herwig predict sample ......" << std::endl;
    TFile *f1 = new TFile(Plots_herwig_path);
    TH2D *phi_genscore_qq_off = (TH2D *)f1->Get("phi_score_qq_off");
    TH2D *phi_genscore_qq_on = (TH2D *)f1->Get("phi_score_qq_on");
    ReWeight reweight(CMSherwig_path);
    reweight.SetWeight(weights_qq, weights_gg);
    reweight.reweight(phi_genscore_qq_off, phi_genscore_qq_on, "qq",
                      outputfolder + "/plots_ML_CMSMC_herwig" + outputname + suffix_qq + "_reweight.root", entries);
  }
}