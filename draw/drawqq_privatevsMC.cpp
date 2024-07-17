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
// Hists pythiaGen_hists("../plots/ML_plots/CMS_pythia_Pt470to1000_jinitpt450_600_j2pt"+ptstr+"Gen/ML_SpinObservable.root");
// Hists pythiaGenReweightSpinoff_hists("../plots/ML_plots/CMS_pythia_Pt470to1000_jinitpt450_600_j2pt"+ptstr+"GenReweightSpinoff/ML_SpinObservable.root");
// Hists pythiaSpinon_hists("../plots/ML_plots/Private_pythia_spinon_jinitpt450_600_j2pt"+ptstr+"/ML_SpinObservable.root");
// Hists pythiaSpinoff_hists("../plots/ML_plots/Private_pythia_spinoff_jinitpt450_600_j2pt"+ptstr+"/ML_SpinObservable.root");
void SymmetryTwoPads(vector<TH1D *> hists,TString filename,TString ExtraText="",vector<TString> legend_name={});
void NorTwoPads(vector<TH1D *> hists,TString filename,vector<TString> ExtraText={""},vector<int> XbinRange={},TString ratios_Xtitle="#varphi");
TH1D *GetHist(Hists &hists,vector<string> histnames);
void handlehists(vector<TH1D *> hists,int rebinnum=10);
void DrawObs(vector<Hists> hists, string obs,vector<double> range={},vector<TString> ExtraText={""},int rebinnum=10);
vector<int> ptrange = {160,200};
string obs = "phi_qq";
string ptstr = (string)TString::Format("%d_%d", ptrange[0], ptrange[1]);
string ptrangestr = (string)TString::Format("%d<pt2<%d", ptrange[0], ptrange[1]);
TString generator="Herwig";
void drawqq_privatevsMC(){
    Hists herwigSpinon_hists("../plots/ML_plots/Private_Herwig_spinon_jinitpt450_600_j2pt"+ptstr+"/ML_SpinObservable.root");
    Hists herwigSpinoff_hists("../plots/ML_plots/Private_Herwig_spinoff_jinitpt450_600_j2pt"+ptstr+"/ML_SpinObservable.root");
    Hists herwigGen_hists("../plots/ML_plots/CMS_herwig_Pt-15to7000_20UL18_jinitpt450_600_j2pt"+ptstr+"Gen_lumi59800/ML_SpinObservable.root");
    Hists herwigGenReweightSpinoff_hists("../plots/ML_plots/CMS_herwig_Pt-15to7000_20UL18_jinitpt450_600_j2pt"+ptstr+"GenReweightSpinoff_lumi59800/ML_SpinObservable.root");

    // Hists herwigSpinon_hists("../plots/ML_plots/Private_pythia_spinon_jinitpt450_600_j2pt"+ptstr+"/ML_SpinObservable.root");
    // Hists herwigSpinoff_hists("../plots/ML_plots/Private_pythia_spinoff_jinitpt450_600_j2pt"+ptstr+"/ML_SpinObservable.root");
    // Hists herwigGen_hists("../plots/ML_plots/CMS_pythia_Pt470to1000_jinitpt450_600_j2pt"+ptstr+"Gen_lumi59800/ML_SpinObservable.root");
    // Hists herwigGenReweightSpinoff_hists("../plots/ML_plots/CMS_pythia_Pt470to1000_jinitpt450_600_j2pt"+ptstr+"GenReweightSpinoff_lumi59800/ML_SpinObservable.root");

    

    TH1D *herwigoff = GetHist(herwigSpinoff_hists,{obs});
    TH1D *herwigon  =  GetHist(herwigSpinon_hists,{obs});
    TH1D *herwiggen  =  GetHist(herwigGen_hists,{obs});
    TH1D *herwigreco  =  GetHist(herwigGen_hists,{"Reco"+obs});
    TH1D *herwiggenoff  =  GetHist(herwigGenReweightSpinoff_hists,{obs});
    TH1D *herwigrecooff  =  GetHist(herwigGenReweightSpinoff_hists,{"Reco"+obs});


    
    handlehists({herwigoff,herwigon,herwiggen,herwigreco,herwiggenoff,herwigrecooff});

    chiscan::chiscan chi_reco_lumi(herwigreco,chiscan::chiscan::GetStandarCov(herwigrecooff,true),herwigrecooff,{});
    chiscan::chiscan chi_reco_sample(herwigreco,chiscan::chiscan::GetStandarCov(herwigrecooff,false),herwigrecooff,{});
    cout<<generator<<" "<<ptrangestr<<" @ lumi = 59.8 fb: "<<chi_reco_lumi.calchi2()<<"  @sample statistic :"<<chi_reco_sample.calchi2()<<endl;

    herwigoff->SetTitle(generator+" spin off");
    herwigon->SetTitle(generator+" spin on");
    herwiggen->SetTitle(generator+" Gen");
    herwigreco->SetTitle(generator+" Reco");
    herwiggenoff->SetTitle(generator+" Gen Reweight spin off");
    herwigrecooff->SetTitle(generator+" Reco Reweight spin off");

    //auto hists = Draw_Template::SymmetryHists({herwiggen,herwigreco},true);
    //NorTwoPads({herwigoff,herwigon},obs+"/herwigspin"+ptstr+".pdf",ptrangestr);
    NorTwoPads({herwigoff,herwigon,herwiggen,herwigreco},"private/"+obs+"_jinitpt450_600_j2pt"+ptstr+"_"+(string)generator+".pdf",{(TString)ptrangestr,"450<JetPt<600"});
    NorTwoPads({herwigoff,herwigon,herwiggen,herwiggenoff},"private/"+obs+"_jinitpt450_600_j2pt"+ptstr+"_MC_"+(string)generator+".pdf",{(TString)ptrangestr,"450<JetPt<600"});
    NorTwoPads({herwiggenoff,herwiggen},"private/"+obs+"_jinitpt450_600_j2pt"+ptstr+"_CMSMC_"+(string)generator+"Gen.pdf",{(TString)ptrangestr,"450<JetPt<600"});
    NorTwoPads({herwigrecooff,herwigreco},"private/"+obs+"_jinitpt450_600_j2pt"+ptstr+"_CMSMC_"+(string)generator+"Reco.pdf",{(TString)ptrangestr,"450<JetPt<600"});
    NorTwoPads({herwiggen,herwigreco},"private/"+obs+"_jinitpt450_600_j2pt"+ptstr+"_deteff_"+(string)generator+"on.pdf",{(TString)ptrangestr,"450<JetPt<600"});
    NorTwoPads({herwiggenoff,herwigrecooff},"private/"+obs+"_jinitpt450_600_j2pt"+ptstr+"_deteff_"+(string)generator+"off.pdf",{(TString)ptrangestr,"450<JetPt<600"});

    DrawObs({herwigSpinoff_hists,herwigSpinon_hists,herwigGen_hists,herwigGenReweightSpinoff_hists},"JetPt_qq",{450,600},{(TString)ptrangestr,"450<JetPt<600"});
    DrawObs({herwigSpinoff_hists,herwigSpinon_hists,herwigGen_hists,herwigGenReweightSpinoff_hists},"Jet1Pt_qq",{ptrange[0]*1.0,600},{(TString)ptrangestr,"450<JetPt<600"});
    DrawObs({herwigSpinoff_hists,herwigSpinon_hists,herwigGen_hists,herwigGenReweightSpinoff_hists},"Jet2Pt_qq",{ptrange[0]*1.0-10,ptrange[1]*1.0},{(TString)ptrangestr,"450<JetPt<600"},2);
    DrawObs({herwigSpinoff_hists,herwigSpinon_hists,herwigGen_hists,herwigGenReweightSpinoff_hists},"Jet3Pt_qq",{ptrange[0]*1.0/2,ptrange[1]*1.0},{(TString)ptrangestr,"450<JetPt<600"},2);
    DrawObs({herwigSpinoff_hists,herwigSpinon_hists,herwigGen_hists,herwigGenReweightSpinoff_hists},"Jet4Pt_qq",{0,ptrange[1]*1.0/2},{(TString)ptrangestr,"450<JetPt<600"},2);

    DrawObs({herwigSpinoff_hists,herwigSpinon_hists,herwigGen_hists,herwigGenReweightSpinoff_hists},"kt1_qq",{0,140},{(TString)ptrangestr,"450<JetPt<600"},40);
    DrawObs({herwigSpinoff_hists,herwigSpinon_hists,herwigGen_hists,herwigGenReweightSpinoff_hists},"kt2_qq",{0,30},{(TString)ptrangestr,"450<JetPt<600"},20);
    DrawObs({herwigSpinoff_hists,herwigSpinon_hists,herwigGen_hists,herwigGenReweightSpinoff_hists},"z1_qq",{0,0.5},{(TString)ptrangestr,"450<JetPt<600"},10);
    DrawObs({herwigSpinoff_hists,herwigSpinon_hists,herwigGen_hists,herwigGenReweightSpinoff_hists},"z2_qq",{0,0.5},{(TString)ptrangestr,"450<JetPt<600"},10);
   
}
void DrawObs(vector<Hists> hists, string obs,vector<double> range={},vector<TString> ExtraText={""},int rebinnum=10)
{
  
  TH1D *herwigoff = GetHist(hists.at(0), {obs});
  TH1D *herwigon = GetHist(hists.at(1), {obs});
  TH1D *herwiggen = GetHist(hists.at(2), {obs});
  TH1D *herwiggenoff = GetHist(hists.at(3), {obs});
  vector<int> rangex ={};
  if(range.size()!=0) rangex={herwigoff->FindBin(range.at(0)), herwigoff->FindBin(range.at(1))-1};
  if(rangex.size()!=0){
    herwigoff->GetXaxis()->SetRange(rangex.at(0),rangex.at(1));
    herwigon->GetXaxis()->SetRange(rangex.at(0),rangex.at(1));
    herwiggen->GetXaxis()->SetRange(rangex.at(0),rangex.at(1));
    herwiggenoff->GetXaxis()->SetRange(rangex.at(0),rangex.at(1));
  }
  
  handlehists({herwigoff, herwigon, herwiggen, herwiggenoff},rebinnum);
  herwigoff->SetTitle(generator+" spin off");
  herwigon->SetTitle(generator+" spin on");
  herwiggen->SetTitle(generator+" Gen");
  herwiggenoff->SetTitle(generator+" Gen Reweight spin off");
  rangex ={};
  if(range.size()!=0) rangex={herwigoff->FindBin(range.at(0)), herwigoff->FindBin(range.at(1))-1};
  ExtraText.insert(ExtraText.begin(), (TString)obs);
  NorTwoPads({herwigoff, herwigon, herwiggen, herwiggenoff}, "private/" + obs + "_jinitpt450_600_j2pt" + ptstr + "_"+(string)generator+obs+".pdf",ExtraText, rangex,obs);
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
void handlehists(vector<TH1D *> hists,int rebinnum=10){
  for(auto &hist : hists){
    hist->Rebin(rebinnum);
    //hist->Scale(1.0/hist->Integral());
  }
}
void SymmetryTwoPads(vector<TH1D *> hists,TString filename,TString ExtraText="",vector<double> XbinRange={}){
      auto hists_sym = Draw_Template::SymmetryHists(hists,true);
      ROOTPlot plot1(hists_sym);
      plot1.Load.TwoPads();
      plot1.SetYRangeRatio(0.7,1.3);
      if (XbinRange.size() == 0)
      {
        plot1.SetXbinRange(1, hists_sym.at(0)->GetNbinsX());
      }
      else
      {
        plot1.SetXbinRange(XbinRange.at(0), XbinRange.at(1));
      }
      plot1.SetLegend(0.15, 0.35, 0.32, 0.7);
      plot1.ratios_Xtitle = "#varphi";
      plot1.AddExtraText({ExtraText});
      plot1.Draw();
      // plot1.Write(TString::Format("output/Unweighted%d.png", i));
      plot1.Write(
          "plots/"+filename);
      // plot1.Write(
      //     "zlin://mnt/c/Users/win10/machine_learning/plots2/"+filename);
   } 
  void NorTwoPads(vector<TH1D *> hists,TString filename,vector<TString> ExtraText={""},vector<int> XbinRange={},TString ratios_Xtitle="#varphi"){
    vector<TH1D *>hists2;
    for (auto &hist : hists)
    {
      TH1D *hist2 = (TH1D *)hist->Clone();
      hists2.push_back(hist2);
    }
      auto hists_sym = Draw_Template::NorHists(hists2);
      ROOTPlot plot1(hists2);
      plot1.Load.TwoPads();
      if (XbinRange.size() == 0)
      {
        plot1.SetXbinRange(1, hists_sym.at(0)->GetNbinsX());
      }
      else
      {
        plot1.SetXbinRange(XbinRange.at(0), XbinRange.at(1));
      }
      plot1.SetYRangeRatio(0.7,1.3);
      plot1.SetLegend(0.15, 0.35, 0.32, 0.7);
      plot1.SetLegendName(Draw_Template::GetTitles(hists));
      plot1.ratios_Xtitle = ratios_Xtitle;
      plot1.AddExtraText(ExtraText);
      
      plot1.Draw();
      // plot1.Write(TString::Format("output/Unweighted%d.png", i));
      plot1.Write(
          "plots/"+filename);
      // plot1.Write(
      //     "zlin://mnt/c/Users/win10/machine_learning/plots2/"+filename);
   } 