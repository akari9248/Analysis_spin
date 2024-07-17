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
void drawqq_private2(){
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

    vector<int> ptrange={80,120};
    string obs="phi_qq";
    string ptstr=(string)TString::Format("%d_%d",ptrange[0],ptrange[1]);
    string ptrangestr = (string)TString::Format("%d<p_{T2}<%d",ptrange[0],ptrange[1]);

    // Hists herwigSpinon_hists("../plots/ML_plots/Private_Herwig_spinon_jinitpt450_600_j2pt"+ptstr+"/ML_SpinObservable.root");
    // Hists herwigSpinoff_hists("../plots/ML_plots/Private_Herwig_spinoff_jinitpt450_600_j2pt"+ptstr+"/ML_SpinObservable.root");

    // Hists herwigSpinon_hists("../plots/ML_plots/Maxscore/Private_Herwig_spinon_jinitpt200_800_j2pt"+ptstr+"/ML_SpinObservable.root");
    // Hists herwigSpinoff_hists("../plots/ML_plots/Maxscore/Private_Herwig_spinoff_jinitpt200_800_j2pt"+ptstr+"/ML_SpinObservable.root");
    // Hists pythiaSpinon_hists("../plots/ML_plots/Maxscore/Private_pythia_spinon_jinitpt200_800_j2pt"+ptstr+"/ML_SpinObservable.root");
    // Hists pythiaSpinoff_hists("../plots/ML_plots/Maxscore/Private_pythia_spinoff_jinitpt200_800_j2pt"+ptstr+"/ML_SpinObservable.root");
    // Hists herwigGen_hists("../plots/ML_plots/Maxscore/CMS_herwig_HT200toInf_jinitpt200_800_j2pt"+ptstr+"Gen/ML_SpinObservable.root");
    // Hists herwigReco_hists("../plots/ML_plots/Maxscore/CMS_herwig_HT200toInf_jinitpt200_800_j2pt"+ptstr+"Reco/ML_SpinObservable.root");
    // Hists pythiaGen_hists("../plots/ML_plots/Maxscore/CMS_pythia_Pt470to1000_jinitpt200_800_j2pt"+ptstr+"Gen/ML_SpinObservable.root");
    // Hists pythiaReco_hists("../plots/ML_plots/Maxscore/CMS_pythia_Pt470to1000_jinitpt200_800_j2pt"+ptstr+"Reco/ML_SpinObservable.root");
    // Hists Data("../plots/ML_plots/Maxscore/JetHT_Run2016_UL2016_jinitpt200_800_j2pt160_200Reco/ML_SpinObservable.root");

    Hists herwigGen_hists("../plots/ML_plots/CMS_herwig_HT200toInf_jinitpt450_600_j2pt"+ptstr+"Gen/ML_SpinObservable.root");
    Hists herwigReco_hists("../plots/ML_plots/CMS_herwig_HT200toInf_jinitpt450_600_j2pt"+ptstr+"Reco/ML_SpinObservable.root");
    Hists herwigflatGen_hists("../plots/ML_plots/CMS_herwig_Pt-15to7000_20UL18_jinitpt450_600_j2pt"+ptstr+"Gen/ML_SpinObservable.root");
    Hists herwigflatReco_hists("../plots/ML_plots/CMS_herwig_Pt-15to7000_20UL18_jinitpt450_600_j2pt"+ptstr+"Reco/ML_SpinObservable.root");
    Hists pythiaGen_hists("../plots/ML_plots/CMS_pythia_Pt470to1000_jinitpt450_600_j2pt"+ptstr+"Gen/ML_SpinObservable.root");
    Hists pythiaReco_hists("../plots/ML_plots/CMS_pythia_Pt470to1000_jinitpt450_600_j2pt"+ptstr+"Reco/ML_SpinObservable.root");
    Hists Data("../plots/ML_plots/JetHT_Run2016_UL2016_jinitpt450_600_j2pt160_200Reco/ML_SpinObservable.root");

    TH1D *herwiggen  =  GetHist(herwigGen_hists,{obs});
    TH1D *herwigreco  =  GetHist(herwigReco_hists,{obs});
    TH1D *herwigflatgen  =  GetHist(herwigflatGen_hists,{obs});
    TH1D *herwigflatreco  =  GetHist(herwigflatReco_hists,{obs});
    TH1D *pythiagen  =  GetHist(pythiaGen_hists,{obs});
    TH1D *pythiareco  =  GetHist(pythiaReco_hists,{obs});
    TH1D *data  =  GetHist(Data,{obs});
    handlehists({herwigflatgen,herwigflatreco,herwiggen,herwigreco,pythiagen,pythiareco,data});


    herwiggen->SetTitle("MG5 + Herwig7.2.2");
    herwigreco->SetTitle("MG5 + Herwig7.2.2");
    herwigflatgen->SetTitle("Herwig7.2.0");
    herwigflatreco->SetTitle("Herwig7.2.0");
    pythiagen->SetTitle("Pythia8.240");
    pythiareco->SetTitle("Pythia8.240");
    data->SetTitle("Data");
    //auto hists = Draw_Template::SymmetryHists({herwiggen,herwigreco},true);
    //NorTwoPads({herwigoff,herwigon},obs+"/herwigspin"+ptstr+".pdf",ptrangestr);

    NorTwoPads({data,herwigflatreco,pythiareco},"private/"+obs+"_jinitpt450_600_j2pt"+ptstr+"_datavsMC.pdf",{(TString)ptrangestr,"450<Jet Pt<600"});
    NorTwoPads({herwigflatgen,pythiagen},"private/"+obs+"_jinitpt450_600_j2pt"+ptstr+"_GenMC.pdf",{(TString)ptrangestr,"450<Jet Pt<600","Generated Level"});
    //NorTwoPads({herwigoff,herwigon},"private/"+obs+"_jinitpt200_800_j2pt"+ptstr+".pdf",{(TString)ptrangestr,"200<JetPt<800"});
    NorTwoPads({data,herwigreco},"private/"+obs+"_jinitpt450_600_j2pt"+ptstr+"_datavsherwigHT.pdf",{(TString)ptrangestr,"450<Jet Pt<600"});

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
    //hist->GetXaxis()->SetRange(1,20);
  }
}
void SymmetryTwoPads(vector<TH1D *> hists,TString filename,TString ExtraText="",vector<TString> legend_name={}){
      auto hists_sym = Draw_Template::SymmetryHists(hists,true);
      ROOTPlot plot1(hists_sym);
      plot1.Load.TwoPads();
      plot1.SetYRangeRatio(0.7,1.3);
      plot1.SetXbinRange(1,hists_sym.at(0)->GetNbinsX());
      plot1.SetLegend(0.22, 0.35, 0.32, 0.7);
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
            

      plot1.SetLineStyle({1,1,1,1});
      //plot1.SetXbinRange(1,50);
      plot1.SetYRangeRatio(0.7,1.3);
      plot1.SetLegend(0.19, 0.40, 0.32, 0.66);
      if(legend_name.size()==0)
        plot1.SetLegendName(Draw_Template::GetTitles(hists));
      else
        plot1.SetLegendName(legend_name);
      //plot1.ratios_Xtitle = "z_{2}";
      plot1.ratios_Xtitle = "#varphi";
      plot1.AddExtraText(ExtraText,0.08);
      //plot1.histsArray.at(0).at(4)->SetLineColor(plot1.histsArray.at(0).at(1)->GetLineColor());
      plot1.Draw();
      //plot1.histsArray.at(0).at(4)->SetLineColor(plot1.histsArray.at(0).at(1)->GetLineColor());

      // plot1.Write(TString::Format("output/Unweighted%d.png", i));
      plot1.Write(
          "plots/"+filename);
      // plot1.Write(
      //     "zlin://mnt/c/Users/win10/machine_learning/plots2/"+filename);
   } 