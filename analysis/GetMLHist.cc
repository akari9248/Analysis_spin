#include "iostream"
#include "TCanvas.h"
#include "TPaveText.h"
#include "TString.h"
#include "TChain.h"
#include "TGraph.h"
#include "TH1D.h"
#include "TH2D.h"
#include "GetMLHist.h"

void GetMLHist(TString input_herwig_off_path, TString input_herwig_on_path,
               TString input_pythia_off_path, TString input_pythia_on_path,
               TString input_CMSherwig_path, TString input_CMSpythia_path,
               TString input_CMSdata_path, TString input_qq_weights, TString input_gg_weights,
               int entries = -1, TString outputfolder = "",
               TString output_CMSherwig_name = "", TString output_CMSpythia_name = "", TString output_CMSdata_name = "")
{
  // 初始化，输入文件路径
  TString herwig_off_path = input_herwig_off_path;
  TString herwig_on_path = input_herwig_on_path;
  TString pythia_off_path = input_pythia_off_path;
  TString pythia_on_path = input_pythia_on_path;
  TString CMSherwig_path = input_CMSherwig_path;
  TString CMSpythia_path = input_CMSpythia_path;
  TString CMSdata_path = input_CMSdata_path;

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

  GetMLHists MLHists;
  MLHists.SetEntries(entries);
  MLHists.SetWeight(weights_qq, weights_gg);

  // Analyzing Private Herwig
  if (herwig_off_path != "" && herwig_on_path != "")
  {
    graphs_PrivateMC_train hists_PrivateMC_train_herwig_off = MLHists.GetHists_PrivateMC_train_herwig_off(herwig_off_path);
    graphs_PrivateMC_predict hists_PrivateMC_predict_herwig_on = MLHists.GetHists_PrivateMC_predict_herwig_on(herwig_on_path);

    TFile *f0 = new TFile(outputfolder + "/plots_ML_Roc" + suffix_qq + suffix_gg + ".root", "RECREATE");
    hists_PrivateMC_train_herwig_off.true_distribute_qq->Write("true_distribute_qq");
    hists_PrivateMC_train_herwig_off.true_distribute_gg->Write("true_distribute_gg");
    hists_PrivateMC_train_herwig_off.false_distribute_qq->Write("false_distribute_qq");
    hists_PrivateMC_train_herwig_off.false_distribute_gg->Write("false_distribute_gg");
    f0->Close();
    std::cout << outputfolder + "/plots_ML_Roc" + suffix_qq + suffix_gg + ".root generated" << std::endl;

    TFile *f1 = new TFile(outputfolder + "/plots_ML_Private_herwig" + suffix_qq + suffix_gg + ".root", "RECREATE");
    hists_PrivateMC_train_herwig_off.score_distribute_qq->SetNameTitle("score_qq_off", "score_qq_off");
    hists_PrivateMC_train_herwig_off.score_distribute_gg->SetNameTitle("score_gg_off", "score_gg_off");
    hists_PrivateMC_train_herwig_off.phi_score_qq->SetNameTitle("phi_score_qq_off", "phi_score_qq_off");
    hists_PrivateMC_train_herwig_off.phi_score_gg->SetNameTitle("phi_score_gg_off", "phi_score_gg_off");
    hists_PrivateMC_train_herwig_off.dphi12_score_qq->SetNameTitle("dphi12_score_qq_off", "dphi12_score_qq_off");
    hists_PrivateMC_train_herwig_off.dphi12_score_gg->SetNameTitle("dphi12_score_gg_off", "dphi12_score_gg_off");

    hists_PrivateMC_predict_herwig_on.score_distribute_qq->SetNameTitle("score_qq_on", "score_qq_on");
    hists_PrivateMC_predict_herwig_on.score_distribute_gg->SetNameTitle("score_gg_on", "score_gg_on");
    hists_PrivateMC_predict_herwig_on.phi_score_qq->SetNameTitle("phi_score_qq_on", "phi_score_qq_on");
    hists_PrivateMC_predict_herwig_on.phi_score_gg->SetNameTitle("phi_score_gg_on", "phi_score_gg_on");
    hists_PrivateMC_predict_herwig_on.dphi12_score_qq->SetNameTitle("dphi12_score_qq_on", "dphi12_score_qq_on");
    hists_PrivateMC_predict_herwig_on.dphi12_score_gg->SetNameTitle("dphi12_score_gg_on", "dphi12_score_gg_on");

    hists_PrivateMC_train_herwig_off.score_distribute_qq->Write();
    hists_PrivateMC_train_herwig_off.score_distribute_gg->Write();
    hists_PrivateMC_train_herwig_off.phi_score_qq->Write();
    hists_PrivateMC_train_herwig_off.phi_score_gg->Write();
    hists_PrivateMC_train_herwig_off.dphi12_score_qq->Write();
    hists_PrivateMC_train_herwig_off.dphi12_score_gg->Write();

    hists_PrivateMC_predict_herwig_on.score_distribute_qq->Write();
    hists_PrivateMC_predict_herwig_on.score_distribute_gg->Write();
    hists_PrivateMC_predict_herwig_on.phi_score_qq->Write();
    hists_PrivateMC_predict_herwig_on.phi_score_gg->Write();
    hists_PrivateMC_predict_herwig_on.dphi12_score_qq->Write();
    hists_PrivateMC_predict_herwig_on.dphi12_score_gg->Write();
    f1->Close();
    std::cout << outputfolder + "/plots_ML_Private_herwig" + suffix_qq + suffix_gg + ".root generated" << std::endl;
  }

  // Analyzing Private Pythia
  if (pythia_off_path != "" && pythia_on_path != "")
  {
    graphs_PrivateMC_predict hists_PrivateMC_predict_pythia_off = MLHists.GetHists_PrivateMC_predict_pythia_off(pythia_off_path);
    graphs_PrivateMC_predict hists_PrivateMC_predict_pythia_on = MLHists.GetHists_PrivateMC_predict_pythia_on(pythia_on_path);

    TFile *f2 = new TFile(outputfolder + "/plots_ML_Private_pythia" + suffix_qq + suffix_gg + ".root", "RECREATE");
    hists_PrivateMC_predict_pythia_off.score_distribute_qq->SetNameTitle("score_qq_off", "score_qq_off");
    hists_PrivateMC_predict_pythia_off.score_distribute_gg->SetNameTitle("score_gg_off", "score_gg_off");
    hists_PrivateMC_predict_pythia_off.phi_score_qq->SetNameTitle("phi_score_qq_off", "phi_score_qq_off");
    hists_PrivateMC_predict_pythia_off.phi_score_gg->SetNameTitle("phi_score_gg_off", "phi_score_gg_off");
    hists_PrivateMC_predict_pythia_off.dphi12_score_qq->SetNameTitle("dphi12_score_qq_off", "dphi12_score_qq_off");
    hists_PrivateMC_predict_pythia_off.dphi12_score_gg->SetNameTitle("dphi12_score_gg_off", "dphi12_score_gg_off");

    hists_PrivateMC_predict_pythia_on.score_distribute_qq->SetNameTitle("score_qq_on", "score_qq_on");
    hists_PrivateMC_predict_pythia_on.score_distribute_gg->SetNameTitle("score_gg_on", "score_gg_on");
    hists_PrivateMC_predict_pythia_on.phi_score_qq->SetNameTitle("phi_score_qq_on", "phi_score_qq_on");
    hists_PrivateMC_predict_pythia_on.phi_score_gg->SetNameTitle("phi_score_gg_on", "phi_score_gg_on");
    hists_PrivateMC_predict_pythia_on.dphi12_score_qq->SetNameTitle("dphi12_score_qq_on", "dphi12_score_qq_on");
    hists_PrivateMC_predict_pythia_on.dphi12_score_gg->SetNameTitle("dphi12_score_gg_on", "dphi12_score_gg_on");

    hists_PrivateMC_predict_pythia_off.score_distribute_qq->Write();
    hists_PrivateMC_predict_pythia_off.score_distribute_gg->Write();
    hists_PrivateMC_predict_pythia_on.score_distribute_qq->Write();
    hists_PrivateMC_predict_pythia_on.score_distribute_gg->Write();

    hists_PrivateMC_predict_pythia_off.phi_score_qq->Write();
    hists_PrivateMC_predict_pythia_off.phi_score_gg->Write();
    hists_PrivateMC_predict_pythia_off.dphi12_score_qq->Write();
    hists_PrivateMC_predict_pythia_off.dphi12_score_gg->Write();
    hists_PrivateMC_predict_pythia_on.phi_score_qq->Write();
    hists_PrivateMC_predict_pythia_on.phi_score_gg->Write();
    hists_PrivateMC_predict_pythia_on.dphi12_score_qq->Write();
    hists_PrivateMC_predict_pythia_on.dphi12_score_gg->Write();
    f2->Close();
    std::cout << outputfolder + "/plots_ML_Private_pythia" + suffix_qq + suffix_gg + ".root generated" << std::endl;
  }

  // Analyzing CMS Herwig
  if (CMSherwig_path != "")
  {
    graphs_CMSMC hists_CMSMC_herwig = MLHists.GetHists_CMSMC_predict_herwig(CMSherwig_path);

    TFile *f3 = new TFile(outputfolder + "/plots_ML_CMSMC_herwig" + output_CMSherwig_name + suffix_qq + suffix_gg + ".root", "RECREATE");
    hists_CMSMC_herwig.score_distribute_gen_qq->SetNameTitle("score_gen_qq", "score_gen_qq");
    hists_CMSMC_herwig.score_distribute_gen_gg->SetNameTitle("score_gen_gg", "score_gen_gg");
    hists_CMSMC_herwig.score_distribute_reco_qq->SetNameTitle("score_reco_qq", "score_reco_qq");
    hists_CMSMC_herwig.score_distribute_reco_gg->SetNameTitle("score_reco_gg", "score_reco_gg");

    hists_CMSMC_herwig.phi_score_gen_qq->SetNameTitle("phi_score_gen_qq", "phi_score_gen_qq");
    hists_CMSMC_herwig.phi_score_gen_gg->SetNameTitle("phi_score_gen_gg", "phi_score_gen_gg");
    hists_CMSMC_herwig.dphi12_score_gen_qq->SetNameTitle("dphi12_score_gen_qq", "dphi12_score_gen_qq");
    hists_CMSMC_herwig.dphi12_score_gen_gg->SetNameTitle("dphi12_score_gen_gg", "dphi12_score_gen_gg");

    hists_CMSMC_herwig.phi_genscore_reco_qq->SetNameTitle("phi_genscore_reco_qq", "phi_genscore_reco_qq");
    hists_CMSMC_herwig.phi_genscore_reco_gg->SetNameTitle("phi_genscore_reco_gg", "phi_genscore_reco_gg");
    hists_CMSMC_herwig.phi_recoscore_reco_qq->SetNameTitle("phi_recoscore_reco_qq", "phi_recoscore_reco_qq");
    hists_CMSMC_herwig.phi_recoscore_reco_gg->SetNameTitle("phi_recoscore_reco_gg", "phi_recoscore_reco_gg");

    hists_CMSMC_herwig.dphi12_genscore_reco_qq->SetNameTitle("dphi12_genscore_reco_qq", "dphi12_genscore_reco_qq");
    hists_CMSMC_herwig.dphi12_genscore_reco_gg->SetNameTitle("dphi12_genscore_reco_gg", "dphi12_genscore_reco_gg");
    hists_CMSMC_herwig.dphi12_recoscore_reco_qq->SetNameTitle("dphi12_recoscore_reco_qq", "dphi12_recoscore_reco_qq");
    hists_CMSMC_herwig.dphi12_recoscore_reco_gg->SetNameTitle("dphi12_recoscore_reco_gg", "dphi12_recoscore_reco_gg");

    hists_CMSMC_herwig.score_distribute_gen_qq->Write();
    hists_CMSMC_herwig.score_distribute_gen_gg->Write();
    hists_CMSMC_herwig.score_distribute_reco_qq->Write();
    hists_CMSMC_herwig.score_distribute_reco_gg->Write();
    hists_CMSMC_herwig.phi_score_gen_qq->Write();
    hists_CMSMC_herwig.phi_genscore_reco_qq->Write();
    hists_CMSMC_herwig.phi_recoscore_reco_qq->Write();
    hists_CMSMC_herwig.phi_score_gen_gg->Write();
    hists_CMSMC_herwig.phi_genscore_reco_gg->Write();
    hists_CMSMC_herwig.phi_recoscore_reco_gg->Write();

    hists_CMSMC_herwig.dphi12_score_gen_qq->Write();
    hists_CMSMC_herwig.dphi12_score_gen_gg->Write();
    hists_CMSMC_herwig.dphi12_genscore_reco_qq->Write();
    hists_CMSMC_herwig.dphi12_genscore_reco_gg->Write();
    hists_CMSMC_herwig.dphi12_recoscore_reco_qq->Write();
    hists_CMSMC_herwig.dphi12_recoscore_reco_gg->Write();
    f3->Close();
    std::cout << outputfolder + "/plots_ML_CMSMC_herwig" + output_CMSherwig_name + suffix_qq + suffix_gg + ".root generated" << std::endl;
  }

  // Analyzing CMS Pythia
  if (CMSpythia_path != "")
  {
    graphs_CMSMC hists_CMSMC_pythia = MLHists.GetHists_CMSMC_predict_pythia(CMSpythia_path);

    TFile *f4 = new TFile(outputfolder + "/plots_ML_CMSMC_pythia" + output_CMSpythia_name + suffix_qq + suffix_gg + ".root", "RECREATE");
    hists_CMSMC_pythia.score_distribute_gen_qq->SetNameTitle("score_gen_qq", "score_gen_qq");
    hists_CMSMC_pythia.score_distribute_gen_gg->SetNameTitle("score_gen_gg", "score_gen_gg");
    hists_CMSMC_pythia.score_distribute_reco_qq->SetNameTitle("score_reco_qq", "score_reco_qq");
    hists_CMSMC_pythia.score_distribute_reco_gg->SetNameTitle("score_reco_gg", "score_reco_gg");

    hists_CMSMC_pythia.phi_score_gen_qq->SetNameTitle("phi_score_gen_qq", "phi_score_gen_qq");
    hists_CMSMC_pythia.phi_score_gen_gg->SetNameTitle("phi_score_gen_gg", "phi_score_gen_gg");
    hists_CMSMC_pythia.dphi12_score_gen_qq->SetNameTitle("dphi12_score_gen_qq", "dphi12_score_gen_qq");
    hists_CMSMC_pythia.dphi12_score_gen_gg->SetNameTitle("dphi12_score_gen_gg", "dphi12_score_gen_gg");

    hists_CMSMC_pythia.phi_genscore_reco_qq->SetNameTitle("phi_genscore_reco_qq", "phi_genscore_reco_qq");
    hists_CMSMC_pythia.phi_genscore_reco_gg->SetNameTitle("phi_genscore_reco_gg", "phi_genscore_reco_gg");
    hists_CMSMC_pythia.phi_recoscore_reco_qq->SetNameTitle("phi_recoscore_reco_qq", "phi_recoscore_reco_qq");
    hists_CMSMC_pythia.phi_recoscore_reco_gg->SetNameTitle("phi_recoscore_reco_gg", "phi_recoscore_reco_gg");

    hists_CMSMC_pythia.dphi12_genscore_reco_qq->SetNameTitle("dphi12_genscore_reco_qq", "dphi12_genscore_reco_qq");
    hists_CMSMC_pythia.dphi12_genscore_reco_gg->SetNameTitle("dphi12_genscore_reco_gg", "dphi12_genscore_reco_gg");
    hists_CMSMC_pythia.dphi12_recoscore_reco_qq->SetNameTitle("dphi12_recoscore_reco_qq", "dphi12_recoscore_reco_qq");
    hists_CMSMC_pythia.dphi12_recoscore_reco_gg->SetNameTitle("dphi12_recoscore_reco_gg", "dphi12_recoscore_reco_gg");

    hists_CMSMC_pythia.score_distribute_gen_qq->Write();
    hists_CMSMC_pythia.score_distribute_gen_gg->Write();
    hists_CMSMC_pythia.score_distribute_reco_qq->Write();
    hists_CMSMC_pythia.score_distribute_reco_gg->Write();
    hists_CMSMC_pythia.phi_score_gen_qq->Write();
    hists_CMSMC_pythia.phi_genscore_reco_qq->Write();
    hists_CMSMC_pythia.phi_recoscore_reco_qq->Write();
    hists_CMSMC_pythia.phi_score_gen_gg->Write();
    hists_CMSMC_pythia.phi_genscore_reco_gg->Write();
    hists_CMSMC_pythia.phi_recoscore_reco_gg->Write();

    hists_CMSMC_pythia.dphi12_score_gen_qq->Write();
    hists_CMSMC_pythia.dphi12_score_gen_gg->Write();
    hists_CMSMC_pythia.dphi12_genscore_reco_qq->Write();
    hists_CMSMC_pythia.dphi12_genscore_reco_gg->Write();
    hists_CMSMC_pythia.dphi12_recoscore_reco_qq->Write();
    hists_CMSMC_pythia.dphi12_recoscore_reco_gg->Write();
    f4->Close();
    std::cout << outputfolder + "/plots_ML_CMSMC_pythia" + output_CMSpythia_name + suffix_qq + suffix_gg + ".root generated" << std::endl;
  }

  // Analyzing CMS Data
  if (CMSdata_path != "")
  {
    graphs_CMSData hists_CMSdata = MLHists.GetHists_CMSData_predict(CMSdata_path);

    TFile *f5 = new TFile(outputfolder + "/plots_ML_CMS_data" + output_CMSdata_name + suffix_qq + suffix_gg + ".root", "RECREATE");
    hists_CMSdata.score_distribute_reco_qq->SetNameTitle("score_reco_qq", "score_reco_qq");
    hists_CMSdata.score_distribute_reco_gg->SetNameTitle("score_reco_gg", "score_reco_gg");
    hists_CMSdata.phi_score_reco_qq->SetNameTitle("phi_score_reco_qq", "phi_score_reco_qq");
    hists_CMSdata.phi_score_reco_gg->SetNameTitle("phi_score_reco_gg", "phi_score_reco_gg");
    hists_CMSdata.dphi12_score_reco_qq->SetNameTitle("dphi12_score_reco_qq", "dphi12_score_reco_qq");
    hists_CMSdata.dphi12_score_reco_gg->SetNameTitle("dphi12_score_reco_gg", "dphi12_score_reco_gg");

    hists_CMSdata.score_distribute_reco_qq->Write();
    hists_CMSdata.score_distribute_reco_gg->Write();
    hists_CMSdata.phi_score_reco_qq->Write();
    hists_CMSdata.phi_score_reco_gg->Write();
    hists_CMSdata.dphi12_score_reco_qq->Write();
    hists_CMSdata.dphi12_score_reco_gg->Write();
    f5->Close();
    std::cout << outputfolder + "/plots_ML_CMS_data" + output_CMSdata_name + suffix_qq + suffix_gg + ".root generated" << std::endl;
  }
}