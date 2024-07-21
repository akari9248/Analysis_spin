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
#include "../include/chiscan.h"
void SymmetryTwoPads(vector<TH1D *> hists,TString filename,TString ExtraText="",vector<TString> legend_name={});
void NorTwoPads(vector<TH1D *> hists,TString filename,vector<TString> ExtraText={""},vector<TString> legend_name={});
TH1D *GetHist(Hists &hists,vector<string> histnames);
void handlehists(vector<TH1D *> hists);
void drawqq_phi(){

    // Hists herwigSpinoff("../plots/ML_plots/herwig_pt450_IFN_May28j2pt160_200Spinoff/ML_plot.root");

    vector<int> ptrange={130,7000};
    string obs="phi_type2";
    string ptstr=(string)TString::Format("%d_%d",ptrange[0],ptrange[1]);
    string ptrangestr = (string)TString::Format("%d<pt2<%d",ptrange[0],ptrange[1]);

    // Hists herwigSpinon_hists("../plots/plots/Private_threeplanes_Herwig_spinon_jinitpt800_7000_j2pt130_7000/ML_SpinObservable.root");
    // Hists herwigSpinoff_hists("../plots/plots/Private_threeplanes_Herwig_spinoff_jinitpt800_7000_j2pt130_7000/ML_SpinObservable.root");
    // Hists herwigSpinon_hists("../plots/plots/Hadronspinon/ML_SpinObservable.root");
    // Hists herwigSpinoff_hists("../plots/plots/Hadronspinoff/ML_SpinObservable.root");
    Hists herwigSpinon_hists("../plots/plots/Hadronspinon/ML_SpinObservable.root");
    Hists herwigSpinoff_hists("../plots/plots/Hadronspinoff/ML_SpinObservable.root");
    TH1D *herwigoff = GetHist(herwigSpinoff_hists,{obs});
    TH1D *herwigon  =  GetHist(herwigSpinon_hists,{obs});

    handlehists({herwigoff,herwigon});

    herwigoff->SetTitle("Herwig spin off");
    herwigon->SetTitle("Herwig spin on");

    NorTwoPads({herwigoff,herwigon},obs+".pdf",{(TString)ptrangestr,"800<JetPt<Inf"});


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
  void NorTwoPads(vector<TH1D *> hists,TString filename,vector<TString> ExtraText={""},vector<TString> legend_name={}){
    vector<TH1D *>hists2;
    for (auto &hist : hists)
    {
      TH1D *hist2 = (TH1D *)hist->Clone();
      hists2.push_back(hist2);
    }
      auto hists_sym = Draw_Template::NorHists(hists2);
      ROOTPlot plot1(hists2);
      plot1.Load.TwoPads();
      plot1.SetXbinRange(1,hists_sym.at(0)->GetNbinsX());
      // plot1.SetYRangeRatio(0.7,1.3);
      plot1.SetLegend(0.15, 0.35, 0.32, 0.7);
      if(legend_name.size()==0)
        plot1.SetLegendName(Draw_Template::GetTitles(hists));
      else
        plot1.SetLegendName(legend_name);
      plot1.ratios_Xtitle = "#varphi";
      plot1.AddExtraText(ExtraText);
      
      plot1.Draw();
      // plot1.Write(TString::Format("output/Unweighted%d.png", i));
      plot1.Write(
          "plots/"+filename);
      // plot1.Write(
      //     "zlin://mnt/c/Users/win10/machine_learning/plots2/"+filename);
   } 