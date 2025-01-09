#include "/storage/shuangyuan/code/headfile/plotratio_beta.h"
#include "TFile.h"

void plot_scorecut()
{
  Plots::Histdispose hists;

  TFile *f1 = new TFile("root/plots_ML_Private_herwig_scale0.496.root");
  TFile *f1_noscale = new TFile("root/plots_ML_Private_herwig.root");
  TFile *f2 = new TFile("root/plots_ML_Private_pythia_scale1.143.root");
  TFile *f2_noscale = new TFile("root/plots_ML_Private_pythia.root");
  TFile *f3 = new TFile("root/plots_ML_CMSMC_herwig_RunIISummer20UL18.root");
  TFile *f4 = new TFile("root/plots_ML_CMS_data_JetHT_Run2018.root");

  TH2D *herwig_phi_score_off = (TH2D *)f1->Get("phi_score_qq_off");
  TH2D *herwig_phi_score_on = (TH2D *)f1->Get("phi_score_qq_on");
  TH2D *pythia_phi_score_off = (TH2D *)f2->Get("phi_score_qq_off");
  TH2D *pythia_phi_score_on = (TH2D *)f2->Get("phi_score_qq_on");
  TH2D *gen_phi_score = (TH2D *)f3->Get("phi_score_gen_qq");
  TH2D *reco_phi_genscore = (TH2D *)f3->Get("phi_genscore_reco_qq");
  TH2D *reco_phi_recoscore = (TH2D *)f3->Get("phi_recoscore_reco_qq");

  int bins = herwig_phi_score_off->GetYaxis()->GetNbins();

  std::vector<int> scorebins1 = {11, 21, 31, 41};
  std::vector<TString> legends1;
  std::vector<TH1D *> herwigs_off1, herwigs_on1, pythias_off1, pythias_on1, cms_gens1, cms_recos_gen1, cms_recos_reco1, cms_datas1;
  for (int i = 0; i < scorebins1.size(); i++)
  {
    TH1D *phi_off_herwig = herwig_phi_score_off->ProjectionX(TString::Format("phi_off_herwig%d", i), scorebins1.at(i), bins);
    herwigs_off1.push_back(phi_off_herwig);
    TH1D *phi_on_herwig = herwig_phi_score_on->ProjectionX(TString::Format("phi_on_herwig%d", i), scorebins1.at(i), bins);
    herwigs_on1.push_back(phi_on_herwig);
    TH1D *phi_off_pythia = pythia_phi_score_off->ProjectionX(TString::Format("phi_off_pythia%d", i), scorebins1.at(i), bins);
    pythias_off1.push_back(phi_off_pythia);
    TH1D *phi_on_pythia = pythia_phi_score_on->ProjectionX(TString::Format("phi_on_pythia%d", i), scorebins1.at(i), bins);
    pythias_on1.push_back(phi_on_pythia);
    TH1D *phi_cms_gen = gen_phi_score->ProjectionX(TString::Format("phi_cms_gen%d", i), scorebins1.at(i), bins);
    cms_gens1.push_back(phi_cms_gen);
    TH1D *phi_cms_reco_gen = reco_phi_genscore->ProjectionX(TString::Format("phi_cms_reco_gen%d", i), scorebins1.at(i), bins);
    cms_recos_gen1.push_back(phi_cms_reco_gen);
    TH1D *phi_cms_reco_reco = reco_phi_recoscore->ProjectionX(TString::Format("phi_cms_reco_reco%d", i), scorebins1.at(i), bins);
    cms_recos_reco1.push_back(phi_cms_reco_reco);
    legends1.push_back(TString::Format("score cut = %.2f", herwig_phi_score_off->GetYaxis()->GetBinLowEdge(scorebins1.at(i))));
  }

  hists.rebin(herwigs_off1, 10);
  hists.normalize(herwigs_off1);
  Plots::Plotratio plot11(herwigs_off1);
  plot11.Draw();
  plot11.SetLegPosition(0.62, 0.7, 0.75, 0.88);
  plot11.AddLegend(legends1);
  plot11.AddPave({"qq", "Private herwig", "spin off"});
  plot11.Write("phi_scan/scorecut/herwig_spinoff1.pdf");

  hists.rebin(herwigs_on1, 10);
  hists.normalize(herwigs_on1);
  Plots::Plotratio plot12(herwigs_on1);
  plot12.Draw();
  plot12.SetLegPosition(0.62, 0.7, 0.75, 0.88);
  plot12.AddLegend(legends1);
  plot12.AddPave({"qq", "Private herwig", "spin on"});
  plot12.Write("phi_scan/scorecut/herwig_spinon1.pdf");

  hists.rebin(pythias_off1, 10);
  hists.normalize(pythias_off1);
  Plots::Plotratio plot13(pythias_off1);
  plot13.Draw();
  plot13.SetLegPosition(0.62, 0.7, 0.75, 0.88);
  plot13.AddLegend(legends1);
  plot13.AddPave({"qq", "Private pythia", "spin off"});
  plot13.Write("phi_scan/scorecut/pythia_spinoff1.pdf");

  hists.rebin(pythias_on1, 10);
  hists.normalize(pythias_on1);
  Plots::Plotratio plot14(pythias_on1);
  plot14.Draw();
  plot14.SetLegPosition(0.62, 0.7, 0.75, 0.88);
  plot14.AddLegend(legends1);
  plot14.AddPave({"qq", "Private pythia", "spin on"});
  plot14.Write("phi_scan/scorecut/pythia_spinon1.pdf");

  hists.rebin(cms_gens1, 10);
  hists.normalize(cms_gens1);
  Plots::Plotratio plot15(cms_gens1);
  plot15.Draw();
  plot15.SetLegPosition(0.62, 0.7, 0.75, 0.88);
  plot15.AddLegend(legends1);
  plot15.AddPave({"qq", "CMS herwig gen"});
  plot15.Write("phi_scan/scorecut/cms_gen1.pdf");

  hists.rebin(cms_recos_gen1, 10);
  hists.normalize(cms_recos_gen1);
  Plots::Plotratio plot16(cms_recos_gen1);
  plot16.Draw();
  plot16.SetLegPosition(0.62, 0.7, 0.75, 0.88);
  plot16.AddLegend(legends1);
  plot16.AddPave({"qq", "CMS herwig reco", "gen score cut"});
  plot16.Write("phi_scan/scorecut/cms_reco_gen1.pdf");

  hists.rebin(cms_recos_reco1, 10);
  hists.normalize(cms_recos_reco1);
  Plots::Plotratio plot17(cms_recos_reco1);
  plot17.Draw();
  plot17.SetLegPosition(0.62, 0.7, 0.75, 0.88);
  plot17.AddLegend(legends1);
  plot17.AddPave({"qq", "CMS herwig reco", "reco score cut"});
  plot17.Write("phi_scan/scorecut/cms_reco_reco1.pdf");

  std::vector<int> scorebins2 = {41, 51, 61, 71};
  std::vector<TString> legends2;
  std::vector<TH1D *> herwigs_off2, herwigs_on2, pythias_off2, pythias_on2, cms_gens2, cms_recos_gen2, cms_recos_reco2, cms_datas2;
  for (int i = 0; i < scorebins2.size(); i++)
  {
    TH1D *phi_off_herwig = herwig_phi_score_off->ProjectionX(TString::Format("phi_off_herwig%d", i), scorebins2.at(i), bins);
    herwigs_off2.push_back(phi_off_herwig);
    TH1D *phi_on_herwig = herwig_phi_score_on->ProjectionX(TString::Format("phi_on_herwig%d", i), scorebins2.at(i), bins);
    herwigs_on2.push_back(phi_on_herwig);
    TH1D *phi_off_pythia = pythia_phi_score_off->ProjectionX(TString::Format("phi_off_pythia%d", i), scorebins2.at(i), bins);
    pythias_off2.push_back(phi_off_pythia);
    TH1D *phi_on_pythia = pythia_phi_score_on->ProjectionX(TString::Format("phi_on_pythia%d", i), scorebins2.at(i), bins);
    pythias_on2.push_back(phi_on_pythia);
    TH1D *phi_cms_gen = gen_phi_score->ProjectionX(TString::Format("phi_cms_gen%d", i), scorebins2.at(i), bins);
    cms_gens2.push_back(phi_cms_gen);
    TH1D *phi_cms_reco_gen = reco_phi_genscore->ProjectionX(TString::Format("phi_cms_reco_gen%d", i), scorebins2.at(i), bins);
    cms_recos_gen2.push_back(phi_cms_reco_gen);
    TH1D *phi_cms_reco_reco = reco_phi_recoscore->ProjectionX(TString::Format("phi_cms_reco_reco%d", i), scorebins2.at(i), bins);
    cms_recos_reco2.push_back(phi_cms_reco_reco);
    legends2.push_back(TString::Format("score cut = %.2f", herwig_phi_score_off->GetYaxis()->GetBinLowEdge(scorebins2.at(i))));
  }

  hists.rebin(herwigs_off2, 10);
  hists.normalize(herwigs_off2);
  Plots::Plotratio plot21(herwigs_off2);
  plot21.Draw();
  plot21.SetLegPosition(0.62, 0.7, 0.75, 0.88);
  plot21.AddLegend(legends2);
  plot21.AddPave({"qq", "Private herwig", "spin off"});
  plot21.Write("phi_scan/scorecut/herwig_spinoff2.pdf");

  hists.rebin(herwigs_on2, 10);
  hists.normalize(herwigs_on2);
  Plots::Plotratio plot22(herwigs_on2);
  plot22.Draw();
  plot22.SetLegPosition(0.62, 0.7, 0.75, 0.88);
  plot22.AddLegend(legends2);
  plot22.AddPave({"qq", "Private herwig", "spin on"});
  plot22.Write("phi_scan/scorecut/herwig_spinon2.pdf");

  hists.rebin(pythias_off2, 10);
  hists.normalize(pythias_off2);
  Plots::Plotratio plot23(pythias_off2);
  plot23.Draw();
  plot23.SetLegPosition(0.62, 0.7, 0.75, 0.88);
  plot23.AddLegend(legends2);
  plot23.AddPave({"qq", "Private pythia", "spin off"});
  plot23.Write("phi_scan/scorecut/pythia_spinoff2.pdf");

  hists.rebin(pythias_on2, 10);
  hists.normalize(pythias_on2);
  Plots::Plotratio plot24(pythias_on2);
  plot24.Draw();
  plot24.SetLegPosition(0.62, 0.7, 0.75, 0.88);
  plot24.AddLegend(legends2);
  plot24.AddPave({"qq", "Private pythia", "spin on"});
  plot24.Write("phi_scan/scorecut/pythia_spinon2.pdf");

  hists.rebin(cms_gens2, 10);
  hists.normalize(cms_gens2);
  Plots::Plotratio plot25(cms_gens2);
  plot25.Draw();
  plot25.SetLegPosition(0.62, 0.7, 0.75, 0.88);
  plot25.AddLegend(legends2);
  plot25.AddPave({"qq", "CMS herwig gen"});
  plot25.Write("phi_scan/scorecut/cms_gen2.pdf");

  hists.rebin(cms_recos_gen2, 10);
  hists.normalize(cms_recos_gen2);
  Plots::Plotratio plot26(cms_recos_gen2);
  plot26.Draw();
  plot26.SetLegPosition(0.62, 0.7, 0.75, 0.88);
  plot26.AddLegend(legends2);
  plot26.AddPave({"qq", "CMS herwig reco", "gen score cut"});
  plot26.Write("phi_scan/scorecut/cms_reco_gen2.pdf");

  hists.rebin(cms_recos_reco2, 10);
  hists.normalize(cms_recos_reco2);
  Plots::Plotratio plot27(cms_recos_reco2);
  plot27.Draw();
  plot27.SetLegPosition(0.62, 0.7, 0.75, 0.88);
  plot27.AddLegend(legends2);
  plot27.AddPave({"qq", "CMS herwig reco", "reco score cut"});
  plot27.Write("phi_scan/scorecut/cms_reco_reco2.pdf");
}