#include "/storage/shuangyuan/code/headfile/plotratio_beta.h"
#include "TFile.h"

void plot_phi()
{
  Plots::Histdispose hists;

  TFile *f1 = new TFile("root/plots_ML_Private_herwig_scale0.496.root");
  TFile *f1_noscale = new TFile("root/plots_ML_Private_herwig.root");
  TFile *f2 = new TFile("root/plots_ML_Private_pythia_scale1.143.root");
  TFile *f2_noscale = new TFile("root/plots_ML_Private_pythia.root");
  TFile *f3 = new TFile("root/plots_ML_CMSMC_herwig_RunIISummer20UL18.root");
  TFile *f4 = new TFile("root/plots_ML_CMS_data_JetHT_Run2018.root");
  TFile *test = new TFile("/storage/shuangyuan/code/analysis_spin/Machine_learning/analysis/test.root");

  TH2D *herwig_phi_score_off = (TH2D *)f1->Get("phi_score_qq_off");
  TH2D *herwig_phi_score_on = (TH2D *)f1->Get("phi_score_qq_on");
  TH2D *pythia_phi_score_off = (TH2D *)f2->Get("phi_score_qq_off");
  TH2D *pythia_phi_score_on = (TH2D *)f2->Get("phi_score_qq_on");
  TH2D *gen_phi_score = (TH2D *)f3->Get("phi_score_gen_qq");
  TH2D *reco_phi_genscore = (TH2D *)f3->Get("phi_genscore_reco_qq");
  TH2D *reco_phi_recoscore = (TH2D *)f3->Get("phi_recoscore_reco_qq");

  TH1D *score_herwig = (TH1D *)f1_noscale->Get("score_qq_on");
  TH1D *score_pythia = (TH1D *)f2_noscale->Get("score_qq_on");
  TH1D *score_cms_herwig_gen = (TH1D *)f3->Get("score_gen_qq");
  TH1D *score_cms_herwig_reco = (TH1D *)reco_phi_recoscore->ProjectionY("score_reco_qq", 1, 100);
  std::cout << score_cms_herwig_reco->GetBinError(10) / score_cms_herwig_reco->GetBinContent(10) << std::endl;
  std::cout << score_cms_herwig_reco->GetBinError(10) << std::endl;
  std::cout << score_cms_herwig_reco->GetBinContent(10) << std::endl;
  // TH1D *score_cms_herwig_reco = (TH1D *)test->Get("score_reco_qq");
  TFile *f = new TFile("test.root", "RECREATE");
  score_cms_herwig_reco->Write();
  f->Close();
  TH1D *score_data = (TH1D *)f4->Get("score_reco_qq");
  std::vector<TH1D *> scores = {score_herwig, score_pythia, score_cms_herwig_gen, score_cms_herwig_reco, score_data};
  // hists.rebin(scores);
  // hists.normalize(scores);
  // Plots::Plotratio plot0(scores);
  // plot0.Draw();
  // plot0.SetLegPosition(0.6, 0.75, 0.8, 0.9);
  // plot0.AddLegend({"Private herwig", "Private pythia", "CMS herwig gen", "CMS herwig reco", "data"});
  // plot0.SetXRatioTitle("score_qq", 0.15, 0.55);
  // plot0.Write("phi_scan/score.pdf");

  std::vector<TH1D *> scores1 = {score_herwig, score_pythia, score_cms_herwig_gen};
  // hists.rebin(scores1);
  hists.normalize(scores1);
  Plots::Plotratio plot01(scores1);
  plot01.Draw();
  plot01.SetLegPosition(0.6, 0.75, 0.8, 0.9);
  plot01.AddLegend({"Private herwig", "Private pythia", "CMS herwig gen"});
  plot01.SetXRatioTitle("score_qq", 0.15, 0.55);
  plot01.Write("phi_scan/score1.pdf");

  std::vector<TH1D *> scores2 = {score_cms_herwig_gen, score_cms_herwig_reco, score_data};
  // hists.rebin(scores2);
  hists.normalize(scores2);
  Plots::Plotratio plot02(scores2);
  plot02.Draw();
  plot02.SetLegPosition(0.6, 0.75, 0.8, 0.9);
  plot02.AddLegend({"CMS herwig gen", "CMS herwig reco", "data"});
  plot02.SetXRatioTitle("score_qq", 0.15, 0.55);
  plot02.Write("phi_scan/score2.pdf");

  int binsize = 5;
  int bins = herwig_phi_score_off->GetYaxis()->GetNbins();
  
  std::vector<TString> spins = {"spin off", "spin on"};
  // for (int i = 1; i <= bins; i++)
  // {
  //   if (i % binsize == 1)
  //   {
  //     TH1D *phi_off_herwig = herwig_phi_score_off->ProjectionX("phi_off_herwig", i, bins);
  //     TH1D *phi_on_herwig = herwig_phi_score_on->ProjectionX("phi_on_herwig", i, bins);
  //     TH1D *phi_off_pythia = pythia_phi_score_off->ProjectionX("phi_off_pythia", i, bins);
  //     TH1D *phi_on_pythia = pythia_phi_score_on->ProjectionX("phi_on_pythia", i, bins);
  //     double scorecut = herwig_phi_score_off->GetYaxis()->GetBinLowEdge(i);

  //     std::vector<TH1D *> phis_herwig = {phi_off_herwig, phi_on_herwig};
  //     std::vector<TH1D *> phis_pythia = {phi_off_pythia, phi_on_pythia};
  //     std::vector<TH1D *> phis_spinon = {phi_on_herwig, phi_on_pythia};
  //     hists.rebin(phis_herwig, 10);
  //     hists.rebin(phis_pythia, 10);
  //     hists.normalize(phis_herwig);
  //     hists.normalize(phis_pythia);

  //     Plots::Plotratio plot1(phis_herwig);
  //     plot1.Draw();
  //     plot1.SetXRatioTitle("#varphi");
  //     plot1.AddPave({"qq", "Private herwig", TString::Format("score cut = %.2f", scorecut)});
  //     plot1.AddLegend(spins);
  //     plot1.AddChisquare();
  //     plot1.Write(TString::Format("phi_scan/herwig/phi_scorecut%.2f.pdf", scorecut));

  //     Plots::Plotratio plot2(phis_pythia);
  //     plot2.Draw();
  //     plot2.SetXRatioTitle("#varphi");
  //     plot2.AddPave({"qq", "Private pythia", TString::Format("score cut = %.2f", scorecut)});
  //     plot2.AddLegend(spins);
  //     plot2.AddChisquare();
  //     plot2.Write(TString::Format("phi_scan/pythia/phi_scorecut%.2f.pdf", scorecut));
  //   }
  // }
}