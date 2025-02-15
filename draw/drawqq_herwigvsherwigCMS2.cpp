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
void drawqq_herwigvsherwigCMS2(){
    // Hists herwig("../plots/ML_train_out/jpt160_200/june6_herwig4/ML_plot.root");
    // Hists herwigGen("../plots/ML_train_out/j1pt450_600jpt160_200/june11_herwigCMSGen/ML_plot.root");
    // Hists herwigReco("../plots/ML_train_out/j1pt450_600jpt160_200/june11_herwigCMSReco/ML_plot.root");

    // Hists herwig("../plots/ML_train_out/jpt160_200/june6_herwig2/ML_plot.root");
    // Hists herwigGen("../plots/ML_plots/CMS_herwig_Pt-15to7000UL17j2pt160_200Gen/ML_plot.root");
    // Hists herwigReco("../plots/ML_plots/CMS_herwig_Pt-15to7000UL17j2pt160_200Reco/ML_plot.root");

    // Hists herwig("../plots/ML_train_out/jpt160_200/june12_herwig_one1GeVcut/ML_plot.root");
    // Hists herwigGen("../plots/ML_plots/CMS_herwig_HT1000to1500Summer17j2pt160_200Gen/ML_plot.root");
    // Hists herwigReco("../plots/ML_plots/CMS_herwig_HT1000to1500Summer17j2pt160_200Reco/ML_plot.root");
    // herwigGen.Add("../plots/ML_plots/CMS_herwig_HT1000to1500j2pt160_200Gen/ML_plot.root");
    // herwigGen.Add("../plots/ML_plots/CMS_herwig_HT1000to1500-preVFPj2pt160_200Gen/ML_plot.root");
    // herwigGen.Add("../plots/ML_plots/CMS_herwig_HT1500to2000j2pt160_200Gen/ML_plot.root");
    // herwigGen.Add("../plots/ML_plots/CMS_herwig_HT1500to2000-preVFPj2pt160_200Gen/ML_plot.root");

    // herwigReco.Add("../plots/ML_plots/CMS_herwig_HT1000to1500j2pt160_200Reco/ML_plot.root");
    // herwigReco.Add("../plots/ML_plots/CMS_herwig_HT1000to1500-preVFPj2pt160_200Reco/ML_plot.root");
    // herwigReco.Add("../plots/ML_plots/CMS_herwig_HT1500to2000j2pt160_200Reco/ML_plot.root");
    // herwigReco.Add("../plots/ML_plots/CMS_herwig_HT1500to2000-preVFPj2pt160_200Reco/ML_plot.root");

    //Hists herwig("../plots/ML_plots/PrivateHerwigj2pt160_200/ML_plot.root");
    // Hists herwigSpinon("../plots/ML_plots/herwig_pt450_IFN_May28j2pt160_200Spinon/ML_plot.root");
    // Hists herwigSpinoff("../plots/ML_plots/herwig_pt450_IFN_May28j2pt160_200Spinoff/ML_plot.root");

    vector<int> ptrange={160,200};
    string obs="phi_qq";
    string ptstr=(string)TString::Format("%d_%d",ptrange[0],ptrange[1]);
    string ptrangestr = (string)TString::Format("%d<pt2<%d",ptrange[0],ptrange[1]);
    Hists pythiaSpinon_hists("../plots/ML_plots/Private_pythia_spinonj2pt"+ptstr+"/ML_SpinObservable.root");
    Hists pythiaSpinoff_hists("../plots/ML_plots/Private_pythia_spinoffj2pt"+ptstr+"/ML_SpinObservable.root");

    Hists pythiaGen_hists("../plots/ML_plots/CMS_pythia_Pt470to600j2pt"+ptstr+"Gen/ML_SpinObservable.root");
    Hists pythiaReco_hists("../plots/ML_plots/CMS_pythia_Pt470to600j2pt"+ptstr+"Reco/ML_SpinObservable.root");

    Hists herwigSpinon_hists("../plots/ML_plots/Private_Herwig_spinonj2pt"+ptstr+"/ML_SpinObservable.root");
    Hists herwigSpinoff_hists("../plots/ML_plots/Private_Herwig_spinoffj2pt"+ptstr+"/ML_SpinObservable.root");

    Hists herwigGen_hists("../plots/ML_plots/CMS_herwig_HT700toInfj2pt"+ptstr+"Gen/ML_SpinObservable.root");
    Hists herwigReco_hists("../plots/ML_plots/CMS_herwig_HT700toInfj2pt"+ptstr+"Reco/ML_SpinObservable.root");

    Hists Data_hists("../plots/ML_plots/JetHT_Run2016_UL2016j2pt"+ptstr+"Reco/ML_SpinObservable.root");

    // Hists herwigSpinon("../plots/ML_plots/Private_Herwig_spinonj2pt160_200/ML_plot.root");
    // Hists herwigSpinoff("../plots/ML_plots/Private_Herwig_spinoffj2pt160_200//ML_plot.root");

    // Hists herwigGen("../plots/ML_plots/CMS_herwig_HT700toInfj2pt160_200Gen/ML_plot.root");
    // Hists herwigReco("../plots/ML_plots/CMS_herwig_HT700toInfj2pt160_200Reco/ML_plot.root");
    

    TH1D *pythiaoff = GetHist(pythiaSpinoff_hists,{obs});
    TH1D *pythiaon  =  GetHist(pythiaSpinon_hists,{obs});

    TH1D *herwigoff = GetHist(herwigSpinoff_hists,{obs});
    TH1D *herwigon  =  GetHist(herwigSpinon_hists,{obs});

    TH1D *pythiaGen  = GetHist(pythiaGen_hists,{obs});
    TH1D *pythiaReco = GetHist(pythiaReco_hists,{obs});

    TH1D *herwigGen  = GetHist(herwigGen_hists,{obs});
    TH1D *herwigReco = GetHist(herwigReco_hists,{obs});

    TH1D *Data = GetHist(Data_hists,{obs});

    // for(int i=0;i<herwigoff->GetNbinsX()+2;i++){
    //   herwigoff->SetBinError(i,sqrt(herwigoff->GetBinContent(i)));
    //   herwigon->SetBinError(i,sqrt(herwigon->GetBinContent(i)));
    //   herwigGen->SetBinError(i,sqrt(herwigGen->GetBinContent(i)));
    //   herwigReco->SetBinError(i,sqrt(herwigReco->GetBinContent(i)));
    // }
    handlehists({pythiaoff,pythiaon,herwigoff,herwigon,pythiaGen,pythiaReco,herwigGen,herwigReco,Data});
    auto pythia_det=(TH1D *)pythiaReco->Clone();
    pythia_det->Divide(pythiaGen);
    TH1D *HerwigSimGen=(TH1D *) herwigon->Clone();
    TH1D *HerwigSimReco=(TH1D *) HerwigSimGen->Clone();
    HerwigSimReco->Multiply(pythia_det);
    HerwigSimGen->SetTitle("Herwig sim Gen");
    HerwigSimReco->SetTitle("Herwig sim Reco");

    pythiaoff->SetTitle("Pythia spin off");
    pythiaon->SetTitle("Pythia spin on");
    pythiaGen->SetTitle("Pythia Gen");
    pythiaReco->SetTitle("Pythia Reco");

    herwigoff->SetTitle("Herwig spin off");
    herwigon->SetTitle("Herwig spin on");
    herwigGen->SetTitle("Herwig Gen");
    herwigReco->SetTitle("Herwig Reco");

    Data->SetTitle("Data");
    NorTwoPads({pythiaoff,pythiaon},obs+"/pythiaspin"+ptstr+".pdf",ptrangestr);
    NorTwoPads({herwigoff,herwigon},obs+"/herwigspin"+ptstr+".pdf",ptrangestr);
    NorTwoPads({pythiaoff,pythiaon,herwigoff,herwigon},obs+"/pythiaspinvsherwigspin"+ptstr+".pdf",ptrangestr);
    NorTwoPads({pythiaoff,pythiaon,pythiaGen,pythiaReco},obs+"/pythiaspinvsGenReco"+ptstr+".pdf",ptrangestr);
    NorTwoPads({herwigoff,herwigon,herwigGen,herwigReco},obs+"/herwigspinvsGenReco"+ptstr+".pdf",ptrangestr);

    NorTwoPads({pythiaoff,pythiaon,herwigoff,herwigon,Data},obs+"/pythiaspinvsherwigspinvsData"+ptstr+".pdf",ptrangestr);
    NorTwoPads({pythiaGen,pythiaReco,herwigGen,herwigReco,Data},obs+"/MCGenRecovsData"+ptstr+".pdf",ptrangestr);
    NorTwoPads({pythiaReco,herwigReco,Data},obs+"/MCRecovsData"+ptstr+".pdf",ptrangestr);
    NorTwoPads({pythiaReco,HerwigSimReco,Data},obs+"/MCRecovsData"+ptstr+"_2.pdf",ptrangestr);


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
      // plot1.SetYRangeRatio(0.7,1.3);
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