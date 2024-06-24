#include "TFile.h"
#include "TH1D.h"
#include "TTree.h"
#include "TChain.h"
#include "TLorentzVector.h"
#include "../include/Hists.h"
#include "../include/Process_bar.h"
#include "../include/Draw_Template.h"
#include <getopt.h>
#include "TDirectory.h"
void SymmetryTwoPads(vector<TH1D *> hists,TString filename,TString ExtraText="",vector<TString> legend_name={});
TH1D *GetHist(Hists &hists,vector<string> histnames);
void handlehists(vector<TH1D *> hists);
void drawqq_herwigvsherwigCMS2(){
    // Hists herwig("../plots/ML_train_out/jpt160_200/june6_herwig4/ML_plot.root");
    // Hists herwigGen("../plots/ML_train_out/j1pt450_600jpt160_200/june11_herwigCMSGen/ML_plot.root");
    // Hists herwigReco("../plots/ML_train_out/j1pt450_600jpt160_200/june11_herwigCMSReco/ML_plot.root");

    // Hists herwig("../plots/ML_train_out/jpt160_200/june6_herwig2/ML_plot.root");
    // Hists herwigGen("../plots/ML_plots/CMS_herwig_Pt-15to7000UL17j2pt160_200Gen/ML_plot.root");
    // Hists herwigReco("../plots/ML_plots/CMS_herwig_Pt-15to7000UL17j2pt160_200Reco/ML_plot.root");

    // Hists herwig("../plots/ML_train_out/jpt80_120/june12_herwig_one1GeVcut/ML_plot.root");
    // Hists herwigGen("../plots/ML_plots/CMS_herwig_HT1000to1500Summer17j2pt80_120Gen/ML_plot.root");
    // Hists herwigReco("../plots/ML_plots/CMS_herwig_HT1000to1500Summer17j2pt80_120Reco/ML_plot.root");
    // herwigGen.Add("../plots/ML_plots/CMS_herwig_HT1000to1500j2pt80_120Gen/ML_plot.root");
    // herwigGen.Add("../plots/ML_plots/CMS_herwig_HT1000to1500-preVFPj2pt80_120Gen/ML_plot.root");
    // herwigGen.Add("../plots/ML_plots/CMS_herwig_HT1500to2000j2pt80_120Gen/ML_plot.root");
    // herwigGen.Add("../plots/ML_plots/CMS_herwig_HT1500to2000-preVFPj2pt80_120Gen/ML_plot.root");

    // herwigReco.Add("../plots/ML_plots/CMS_herwig_HT1000to1500j2pt80_120Reco/ML_plot.root");
    // herwigReco.Add("../plots/ML_plots/CMS_herwig_HT1000to1500-preVFPj2pt80_120Reco/ML_plot.root");
    // herwigReco.Add("../plots/ML_plots/CMS_herwig_HT1500to2000j2pt80_120Reco/ML_plot.root");
    // herwigReco.Add("../plots/ML_plots/CMS_herwig_HT1500to2000-preVFPj2pt80_120Reco/ML_plot.root");

    //Hists herwig("../plots/ML_plots/PrivateHerwigj2pt160_200/ML_plot.root");
    // Hists herwigSpinon("../plots/ML_plots/herwig_pt450_IFN_May28j2pt160_200Spinon/ML_plot.root");
    // Hists herwigSpinoff("../plots/ML_plots/herwig_pt450_IFN_May28j2pt160_200Spinoff/ML_plot.root");

    Hists herwigSpinon("../plots/ML_plots/Private_pythia_spinonj2pt80_120/ML_plot.root");
    Hists herwigSpinoff("../plots/ML_plots/Private_pythia_spinoffj2pt80_120/ML_plot.root");

    Hists herwigGen("../plots/ML_plots/CMS_pythia_Pt470to1000j2pt80_120Gen/ML_plot.root");
    Hists herwigReco("../plots/ML_plots/CMS_pythia_Pt470to1000j2pt80_120Reco/ML_plot.root");

    // Hists herwigSpinon("../plots/ML_plots/Private_Herwig_spinonj2pt80_120/ML_plot.root");
    // Hists herwigSpinoff("../plots/ML_plots/Private_Herwig_spinoffj2pt80_120//ML_plot.root");

    // Hists herwigGen("../plots/ML_plots/CMS_herwig_HT700toInfj2pt80_120Gen/ML_plot.root");
    // Hists herwigReco("../plots/ML_plots/CMS_herwig_HT700toInfj2pt80_120Reco/ML_plot.root");


    TH1D *herwigqqoff = GetHist(herwigSpinoff,{"phi_qq_spinon_ktcut25","phi_qq_spinon_ktcut5"});
    TH1D *herwigqqon  =  GetHist(herwigSpinon,{"phi_qq_spinon_ktcut25","phi_qq_spinon_ktcut5"});

    TH1D *herwigGenqq  = GetHist(herwigGen,{"phi_qq_spinon_ktcut25","phi_qq_spinon_ktcut5"});
    TH1D *herwigRecoqq = GetHist(herwigReco,{"phi_qq_spinon_ktcut25","phi_qq_spinon_ktcut5"});

    // for(int i=0;i<herwigqqoff->GetNbinsX()+2;i++){
    //   herwigqqoff->SetBinError(i,sqrt(herwigqqoff->GetBinContent(i)));
    //   herwigqqon->SetBinError(i,sqrt(herwigqqon->GetBinContent(i)));
    //   herwigGenqq->SetBinError(i,sqrt(herwigGenqq->GetBinContent(i)));
    //   herwigRecoqq->SetBinError(i,sqrt(herwigRecoqq->GetBinContent(i)));
    // }
    
    SymmetryTwoPads({herwigqqoff,herwigqqon,herwigGenqq,herwigRecoqq},"herwigvspythiaqq_80_120.pdf","80<pt2<120",{"pythia spin off","pythia spin on","pythia Gen spin on","pythia Reco spin on"});

    
}
TH1D *GetHist(Hists &hists, vector<string> histnames) {
  TH1D *hist = 0;
  for (auto histname : histnames) {
    TH1D * hist0 = (TH1D *)hists[histname]->Clone();
    if (hist == 0) {
      hist = (TH1D *)hist0->Clone();
      hist->SetDirectory(0);
    } else {
      hist->Add(hist0);
    }
  }
  return hist;
}
void handlehists(vector<TH1D *> hists){
  for(auto hist : hists){
    hist->Rebin(10);
    hist->Scale(1.0/hist->Integral());
  }
}
void SymmetryTwoPads(vector<TH1D *> hists,TString filename,TString ExtraText="",vector<TString> legend_name={}){
      auto hists_sym = Draw_Template::SymmetryHists(hists,true);
      ROOTPlot plot1(hists_sym);
      plot1.Load.TwoPads();
      plot1.SetXbinRange(1,hists_sym.at(0)->GetNbinsX());
      plot1.SetLegend(0.15, 0.35, 0.32, 0.7);
      if(legend_name.size()==0)
        plot1.SetLegendName(Draw_Template::GetTitles(hists));
      else
        plot1.SetLegendName(legend_name);
      plot1.ratios_Xtitle = "#varphi";
      plot1.AddExtraText({ExtraText});
      plot1.Draw();
      // plot1.Write(TString::Format("output/Unweighted%d.png", i));
      plot1.Write(
          "plots/"+filename);
      // plot1.Write(
      //     "zlin://mnt/c/Users/win10/machine_learning/plots2/"+filename);
   } 