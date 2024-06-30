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
void NorTwoPads(vector<TH1D *> hists,TString filename,TString ExtraText="",vector<TString> legend_name={});
TH1D *GetHist(Hists &hists,vector<string> histnames);
void handlehists(vector<TH1D *> hists);
void drawqq_herwigvsherwigCMS3(){
    // Hists herwig("../plots/ML_train_out/jpt80_120/june6_herwig4/ML_plot.root");
    // Hists herwigGen("../plots/ML_train_out/j1pt450_600jpt80_120/june11_herwigCMSGen/ML_plot.root");
    // Hists herwigReco("../plots/ML_train_out/j1pt450_600jpt80_120/june11_herwigCMSReco/ML_plot.root");

    // Hists herwig("../plots/ML_train_out/jpt80_120/june6_herwig2/ML_plot.root");
    // Hists herwigGen("../plots/ML_plots/CMS_herwig_Pt-15to7000UL17j2pt80_120Gen/ML_plot.root");
    // Hists herwigReco("../plots/ML_plots/CMS_herwig_Pt-15to7000UL17j2pt80_120Reco/ML_plot.root");

    // Hists herwig("../plots/ML_train_out/jpt80_120/june12_herwig_one1GeVcut/ML_plot.root");
    // Hists herwigGen("../plots/ML_plots/CMS_herwig_HT1000to1500Summer17j2pt80_120Gen/ML_plot.root");
    // Hists herwigReco("../plots/ML_plots/CMS_herwig_HT1000to1500Summer17j2pt80_120Reco/ML_plot.root");
    // herwigGen.Add("../plots/ML_plots/CMS_herwig_HT1000to1500j2pt80_120Gen/ML_plot.root");
    // herwigGen.Add("../plots/ML_plots/CMS_herwig_HT1000to1500-preVFPj2pt80_120Gen/ML_plot.root");
    // herwigGen.Add("../plots/ML_plots/CMS_herwig_HT1500to1200j2pt80_120Gen/ML_plot.root");
    // herwigGen.Add("../plots/ML_plots/CMS_herwig_HT1500to1200-preVFPj2pt80_120Gen/ML_plot.root");

    // herwigReco.Add("../plots/ML_plots/CMS_herwig_HT1000to1500j2pt80_120Reco/ML_plot.root");
    // herwigReco.Add("../plots/ML_plots/CMS_herwig_HT1000to1500-preVFPj2pt80_120Reco/ML_plot.root");
    // herwigReco.Add("../plots/ML_plots/CMS_herwig_HT1500to1200j2pt80_120Reco/ML_plot.root");
    // herwigReco.Add("../plots/ML_plots/CMS_herwig_HT1500to1200-preVFPj2pt80_120Reco/ML_plot.root");

    //Hists herwig("../plots/ML_plots/PrivateHerwigj2pt80_120/ML_plot.root");
    // Hists herwigSpinon("../plots/ML_plots/herwig_pt450_IFN_May28j2pt80_120Spinon/ML_plot.root");
    // Hists herwigSpinoff("../plots/ML_plots/herwig_pt450_IFN_May28j2pt80_120Spinoff/ML_plot.root");

    Hists pythiaSpinon("../plots/ML_plots/Private_pythia_spinonj2pt80_120/ML_SpinObservable.root");
    Hists pythiaSpinoff("../plots/ML_plots/Private_pythia_spinoffj2pt80_120/ML_SpinObservable.root");

    Hists pythiaGen("../plots/ML_plots/CMS_pythia_Pt470to600j2pt80_120Gen/ML_SpinObservable.root");
    Hists pythiaReco("../plots/ML_plots/CMS_pythia_Pt470to600j2pt80_120Reco/ML_SpinObservable.root");

    Hists herwigSpinon("../plots/ML_plots/Private_Herwig_spinonj2pt80_120/ML_SpinObservable.root");
    Hists herwigSpinoff("../plots/ML_plots/Private_Herwig_spinoffj2pt80_120/ML_SpinObservable.root");

    Hists herwigGen("../plots/ML_plots/CMS_herwig_Pt-15to7000UL18j2pt80_120Gen/ML_SpinObservable.root");
    Hists herwigReco("../plots/ML_plots/CMS_herwig_Pt-15to7000UL18j2pt80_120Reco/ML_SpinObservable.root");

    Hists Data("../plots/ML_plots/JetHT_Run2016_UL2016j2pt80_120Reco/ML_SpinObservable.root");

    // Hists herwigSpinon("../plots/ML_plots/Private_Herwig_spinonj2pt80_120/ML_plot.root");
    // Hists herwigSpinoff("../plots/ML_plots/Private_Herwig_spinoffj2pt80_120//ML_plot.root");

    // Hists herwigGen("../plots/ML_plots/CMS_herwig_HT700toInfj2pt80_120Gen/ML_plot.root");
    // Hists herwigReco("../plots/ML_plots/CMS_herwig_HT700toInfj2pt80_120Reco/ML_plot.root");
    string obs="phi_qq";
    TH1D *pythiaqqoff = GetHist(pythiaSpinoff,{obs});
    TH1D *pythiaqqon  =  GetHist(pythiaSpinon,{obs});

    TH1D *herwigqqoff = GetHist(herwigSpinoff,{obs});
    TH1D *herwigqqon  =  GetHist(herwigSpinon,{obs});

    TH1D *pythiaGenqq  = GetHist(pythiaGen,{obs});
    TH1D *pythiaRecoqq = GetHist(pythiaReco,{obs});

    TH1D *herwigGenqq  = GetHist(herwigGen,{obs});
    TH1D *herwigRecoqq = GetHist(herwigReco,{obs});

    TH1D *Dataqq = GetHist(Data,{obs});

    // for(int i=0;i<herwigqqoff->GetNbinsX()+2;i++){
    //   herwigqqoff->SetBinError(i,sqrt(herwigqqoff->GetBinContent(i)));
    //   herwigqqon->SetBinError(i,sqrt(herwigqqon->GetBinContent(i)));
    //   herwigGenqq->SetBinError(i,sqrt(herwigGenqq->GetBinContent(i)));
    //   herwigRecoqq->SetBinError(i,sqrt(herwigRecoqq->GetBinContent(i)));
    // }
    handlehists({pythiaqqoff,pythiaqqon,herwigqqoff,herwigqqon,pythiaGenqq,pythiaRecoqq,herwigGenqq,herwigRecoqq,Dataqq});
    auto herwig_qq=Draw_Template::SymmetryHists({herwigGenqq,herwigRecoqq},true);
    NorTwoPads({pythiaqqoff,pythiaqqon},obs+"/pythiaspinqq_80_120.pdf","80<pt2<120",{"Pythia spin off","Pythia spin on"});
    NorTwoPads({herwigqqoff,herwigqqon},obs+"/herwigspinqq_80_120.pdf","80<pt2<120",{"Herwig spin off","Herwig spin on"});
    NorTwoPads({pythiaqqoff,pythiaqqon,herwigqqoff,herwigqqon,Dataqq,pythiaGenqq,pythiaRecoqq},obs+"/herwigvspythiaqq_80_120.pdf","80<pt2<120",{"Pythia spin off","Pythia spin on","Herwig spin off","Herwig spin on","Data","Pythia Gen spin on","Pythia Reco spin on"});
    NorTwoPads({pythiaGenqq,pythiaRecoqq,herwig_qq[0],herwig_qq[1],Dataqq},obs+"/DatavsMC_80_120.pdf","80<pt2<120",{"Pythia Gen spin on","Pythia Reco spin on","Herwig Gen spin on","Herwig Reco spin on","Data"});
    NorTwoPads({pythiaGenqq,pythiaRecoqq,Dataqq},obs+"/Datavspythia_80_120.pdf","80<pt2<120",{"Pythia Gen spin on","Pythia Reco spin on","Data"});
    NorTwoPads({pythiaqqoff,pythiaqqon,herwigqqoff,herwigqqon},obs+"/herwigvspythia_80_120.pdf","80<pt2<120",{"Pythia spin off","Pythia spin on","Herwig spin off","Herwig spin on"});
    NorTwoPads({pythiaGenqq,herwig_qq[0]},obs+"/herwigvspythiaGen_80_120.pdf","80<pt2<120",{"Pythia Gen","Herwig Gen"});
    NorTwoPads({pythiaRecoqq,herwig_qq[1]},obs+"/herwigvspythiaReco_80_120.pdf","80<pt2<120",{"Pythia Reco","Herwig Reco"});
    TH1D *Pythia_deteff = (TH1D *)pythiaRecoqq->Clone();
    Pythia_deteff->Divide(pythiaGenqq);
    TH1D *herwigRecoqq_sim= (TH1D *)herwigqqon->Clone();
    herwigRecoqq_sim->Multiply(Pythia_deteff);
    NorTwoPads({herwigqqon,herwigRecoqq,Dataqq},obs+"/Datavsherwig_80_120.pdf","80<pt2<120",{"herwig Gen spin on","herwig Reco spin on","Data"});
    NorTwoPads({pythiaGenqq,pythiaRecoqq,herwigqqon,herwigRecoqq,Dataqq},obs+"/Datavsherwigvspythia_80_120.pdf","80<pt2<120",{"Pythia Gen spin on","Pythia Reco spin on","herwig Gen spin on","herwig Reco spin on","Data"});
    NorTwoPads({pythiaRecoqq,herwigRecoqq,Dataqq},obs+"/DatavsherwigvspythiaReco_80_120.pdf","80<pt2<120",{"Pythia Reco spin on","herwig Reco spin on","Data"});

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
  for(auto &hist : hists){
    hist->Rebin(10);
    hist->Scale(1.0/hist->Integral());
  }
}
void SymmetryTwoPads(vector<TH1D *> hists,TString filename,TString ExtraText="",vector<TString> legend_name={}){
      auto hists_sym = Draw_Template::SymmetryHists(hists,true);
      ROOTPlot plot1(hists_sym);
      plot1.Load.TwoPads();
      plot1.SetYRangeRatio(0.7,1.3);
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
  void NorTwoPads(vector<TH1D *> hists,TString filename,TString ExtraText="",vector<TString> legend_name={}){
    vector<TH1D *>hists2;
    for (auto &hist : hists)
    {
      TH1D *hist2 = (TH1D *)hist->Clone();
      hists2.push_back(hist2);
    }
      auto hists_sym = Draw_Template::NorHists(hists2);
      ROOTPlot plot1(hists_sym);
      plot1.Load.TwoPads();
      plot1.SetXbinRange(1,hists_sym.at(0)->GetNbinsX());
      plot1.SetYRangeRatio(0.7,1.3);
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