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
void drawgg_herwigvspythia(){
    Hists herwig("../plots/ML_train_out/jpt80_120/june6_herwig5/ML_plot.root");
    Hists pythia("../plots/ML_train_out/jpt80_120/june6_pythia5/ML_plot.root");
    
    TH1D *herwigggoff = GetHist(herwig,{"phi_gg_spinoff_ktcut25","phi_gg_spinoff_ktcut5"});
    TH1D *herwigggon  =  GetHist(herwig,{"phi_gg_spinon_ktcut25","phi_gg_spinon_ktcut5"});

    TH1D *pythiaggoff  = GetHist(pythia,{"phi_gg_spinoff_ktcut25","phi_gg_spinoff_ktcut5"});
    TH1D *pythiaggon = GetHist(pythia,{"phi_gg_spinon_ktcut25","phi_gg_spinon_ktcut5"});
    

    SymmetryTwoPads({herwigggoff,herwigggon,pythiaggoff,pythiaggon},"herwigvspythiagg_80_120.pdf","80<pt2<120",{"herwig spin off","herwig spin on","pythia spin off","pythia spin on"});

    // Hists herwig2("../plots/ML_train_out/jpt160_200/june6_herwig2/ML_plot.root");
    // Hists pythia2("../plots/ML_train_out/jpt160_200/june6_pythia2/ML_plot.root");
    
    // TH1D *herwigggoff2 = GetHist(herwig2,{"phi_gg_spinoff_ktcut25","phi_gg_spinoff_ktcut5"});
    // TH1D *herwigggon2  =  GetHist(herwig2,{"phi_gg_spinon_ktcut25","phi_gg_spinon_ktcut5"});

    // TH1D *pythiaggoff2  = GetHist(pythia2,{"phi_gg_spinoff_ktcut25","phi_gg_spinoff_ktcut5"});
    // TH1D *pythiaggon2 = GetHist(pythia2,{"phi_gg_spinon_ktcut25","phi_gg_spinon_ktcut5"});
    

    // SymmetryTwoPads({pythiaggoff2,pythiaggon2,herwigggoff2,herwigggon2},"herwigvspythiagg_160_200.pdf","160<pt2<200",{"pythia spin off","pythia spin on","herwig spin off","herwig spin on"});

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