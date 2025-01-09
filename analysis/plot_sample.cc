#include "/storage/shuangyuan/code/headfile/plotratio_beta.h"
#include "TFile.h"

void plot_sample()
{
  Plots::Histdispose hists;

  TFile *f1 = new TFile("root/plots_ML_Private_herwig_scale0.496.root");
  TFile *f1_noscale = new TFile("root/plots_ML_Private_herwig.root");
  TFile *f2 = new TFile("root/plots_ML_Private_pythia_scale1.143.root");
  TFile *f2_noscale = new TFile("root/plots_ML_Private_pythia.root");
  TFile *f3 = new TFile("root/plots_ML_CMSMC_herwig_RunIISummer20UL18_pt.root");
  TFile *f3_reweight = new TFile("/home/xiaoxue/code/spin/ways/Machine_learning/analysis/root/plots_ML_CMSMC_herwig_RunIISummer20UL18_reweight.root");
  TFile *f4 = new TFile("root/plots_ML_CMS_data_JetHT_Run2018.root");

  TH2D *herwig_phi_score_off = (TH2D *)f1->Get("phi_score_qq_off");
  TH2D *herwig_phi_score_on = (TH2D *)f1->Get("phi_score_qq_on");
  TH2D *pythia_phi_score_off = (TH2D *)f2->Get("phi_score_qq_off");
  TH2D *pythia_phi_score_on = (TH2D *)f2->Get("phi_score_qq_on");
  TH2D *gen_phi_score = (TH2D *)f3->Get("phi_score_gen_qq");
  TH2D *reco_phi_genscore = (TH2D *)f3->Get("phi_genscore_reco_qq");
  TH2D *reco_phi_recoscore = (TH2D *)f3->Get("phi_recoscore_reco_qq");
  TH2D *data_phi_score = (TH2D *)f4->Get("phi_score_reco_gg");

  int bins = herwig_phi_score_off->GetYaxis()->GetNbins();

  std::vector<TString> legends1;
  for (int i = 0; i < bins; i++)
  {
    if (i % 5 == 1)
    {
      double scorecut = herwig_phi_score_off->GetYaxis()->GetBinLowEdge(i);
      TH1D *phi_off_herwig = herwig_phi_score_off->ProjectionX(TString::Format("phi_off_herwig%d", i), i, bins);
      TH1D *phi_on_herwig = herwig_phi_score_on->ProjectionX(TString::Format("phi_on_herwig%d", i), i, bins);
      TH1D *phi_off_pythia = pythia_phi_score_off->ProjectionX(TString::Format("phi_off_pythia%d", i), i, bins);
      TH1D *phi_on_pythia = pythia_phi_score_on->ProjectionX(TString::Format("phi_on_pythia%d", i), i, bins);
      TH1D *phi_cms_gen = gen_phi_score->ProjectionX(TString::Format("phi_cms_gen%d", i), i, bins);
      TH1D *phi_cms_reco_gen = reco_phi_genscore->ProjectionX(TString::Format("phi_cms_reco_gen%d", i), i, bins);
      TH1D *phi_cms_reco_reco = reco_phi_recoscore->ProjectionX(TString::Format("phi_cms_reco_reco%d", i), i, bins);
      TH1D *phi_cms_data = data_phi_score->ProjectionX(TString::Format("phi_cms_data%d", i), i, bins);

      // std::vector<TH1D *> privates_off = {phi_off_herwig, phi_off_pythia};
      // hists.rebin(privates_off, 10);
      // hists.normalize(privates_off);
      // Plots::Plotratio plot1(privates_off);
      // plot1.Draw();
      // plot1.AddPave({"qq", "spin off", TString::Format("score cut = %.2f", scorecut)});
      // plot1.SetLegPosition(0.6, 0.8, 0.9, 0.9);
      // plot1.AddLegend({"Private herwig", "Private pythia"});
      // plot1.AddChisquare();
      // plot1.Write(TString::Format("phi_scan/sample/private_off/phi_scorecut%.2f.pdf", scorecut));

      // std::vector<TH1D *> privates_on = {phi_on_herwig, phi_on_pythia};
      // hists.rebin(privates_on, 10);
      // hists.normalize(privates_on);
      // Plots::Plotratio plot2(privates_on);
      // plot2.Draw();
      // plot2.AddPave({"qq", "spin on", TString::Format("score cut = %.2f", scorecut)});
      // plot2.SetLegPosition(0.6, 0.8, 0.9, 0.9);
      // plot2.AddLegend({"Private herwig", "Private pythia"});
      // plot2.AddChisquare();
      // plot2.Write(TString::Format("phi_scan/sample/private_on/phi_scorecut%.2f.pdf", scorecut));

      // std::vector<TH1D *> private_cms_gen = {phi_on_herwig, phi_cms_gen};
      // hists.rebin(private_cms_gen, 10);
      // hists.normalize(private_cms_gen);
      // Plots::Plotratio plot3(private_cms_gen);
      // plot3.Draw();
      // plot3.AddPave({"qq", TString::Format("score cut = %.2f", scorecut)});
      // plot3.SetLegPosition(0.6, 0.8, 0.9, 0.9);
      // plot3.AddLegend({"Private herwig", "CMS herwig gen"});
      // plot3.AddChisquare();
      // plot3.Write(TString::Format("phi_scan/sample/private_cms_gen/phi_scorecut%.2f.pdf", scorecut));

      std::vector<TH1D *> private_cms_reco_data = {phi_cms_gen, phi_cms_reco_gen, phi_cms_reco_reco, phi_cms_data};
      hists.rebin(private_cms_reco_data, 10);
      hists.normalize(private_cms_reco_data);
      Plots::Plotratio plot3(private_cms_reco_data);
      plot3.Draw();
      plot3.AddPave({"qq", TString::Format("score cut = %.2f", scorecut)});
      plot3.SetLegPosition(0.6, 0.8, 0.9, 0.9);
      plot3.AddLegend({"CMS herwig gen", "CMS herwig reco (gen cut)", "CMS herwig reco (reco cut)", "CMS data"}, 0.03);
      plot3.AddChisquare();
      // plot3.Write(TString::Format("phi_scan/sample/cms_reco_data/phi_scorecut%.2f.pdf", scorecut));
      // if (scorecut == 0.45)
      // {
      //   TH1D *phi_cms_reco_gen_reweight = (TH1D *)f3_reweight->Get("phi_reweight_reco_0.45");
      //   std::vector<TH1D *> private_cms_reco_data = {phi_cms_gen, phi_cms_reco_gen, phi_cms_reco_gen_reweight, phi_cms_data};
      //   hists.rebin(private_cms_reco_data, 10);
      //   hists.normalize(private_cms_reco_data);
      //   Plots::Plotratio plot3(private_cms_reco_data);
      //   plot3.Draw();
      //   plot3.AddPave({"qq", TString::Format("score cut = %.2f", scorecut)});
      //   plot3.SetLegPosition(0.6, 0.8, 0.9, 0.9);
      //   plot3.AddLegend({"CMS herwig gen", "CMS herwig reco (gen cut)", "CMS herwig reco (reweight)", "CMS data"}, 0.03);
      //   plot3.AddChisquare();
      //   plot3.Write(TString::Format("phi_scan/sample/cms_reco_data/phi_scorecut%.2f.pdf", scorecut));
      // }
    }
  }
}