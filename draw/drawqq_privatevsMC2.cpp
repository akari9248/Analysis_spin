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
vector<int> ptrange = {80,120};
string obs = "phi_qq";
string ptstr = (string)TString::Format("%d_%d", ptrange[0], ptrange[1]);
string ptrangestr = (string)TString::Format("%d<pt2<%d", ptrange[0], ptrange[1]);
TString generator="Herwig";
void drawqq_privatevsMC2(){
    Hists herwigSpinon_hists("../plots/ML_plots/Private_Herwig_spinon_jinitpt450_600_j2pt"+ptstr+"/ML_SpinObservable.root");
    Hists herwigSpinoff_hists("../plots/ML_plots/Private_Herwig_spinoff_jinitpt450_600_j2pt"+ptstr+"/ML_SpinObservable.root");
    Hists herwigGen_hists("../plots/ML_plots/CMS_herwig_Pt-15to7000_20UL18_jinitpt450_600_j2pt"+ptstr+"Gen_lumi59800/ML_SpinObservable.root");
    Hists herwigGenReweightSpinoff_hists("../plots/ML_plots/CMS_herwig_Pt-15to7000_20UL18_jinitpt450_600_j2pt"+ptstr+"GenReweightSpinoff_lumi59800/ML_SpinObservable.root");

    Hists pythiaSpinon_hists("../plots/ML_plots/Private_pythia_spinon_jinitpt450_600_j2pt"+ptstr+"/ML_SpinObservable.root");
    Hists pythiaSpinoff_hists("../plots/ML_plots/Private_pythia_spinoff_jinitpt450_600_j2pt"+ptstr+"/ML_SpinObservable.root");
    Hists pythiaGen_hists("../plots/ML_plots/CMS_pythia_Pt470to1000_jinitpt450_600_j2pt"+ptstr+"Gen_lumi59800/ML_SpinObservable.root");
    Hists pythiaGenReweightSpinoff_hists("../plots/ML_plots/CMS_pythia_Pt470to1000_jinitpt450_600_j2pt"+ptstr+"GenReweightSpinoff_lumi59800/ML_SpinObservable.root");

    cout<<"../plots/ML_plots/CMS_pythia_Pt470to1000_jinitpt450_600_j2pt"+ptstr+"Gen_lumi59800/ML_SpinObservable.root"<<endl;
    cout<<"../plots/ML_plots/CMS_herwig_Pt-15to7000_20UL18_jinitpt450_600_j2pt"+ptstr+"Gen_lumi59800/ML_SpinObservable.root"<<endl;

    TH1D *herwigoff = GetHist(herwigSpinoff_hists,{obs});
    TH1D *herwigon  =  GetHist(herwigSpinon_hists,{obs});
    TH1D *herwiggen  =  GetHist(herwigGen_hists,{obs});
    TH1D *herwigreco  =  GetHist(herwigGen_hists,{"Reco"+obs});
    TH1D *herwiggenoff  =  GetHist(herwigGenReweightSpinoff_hists,{obs});
    TH1D *herwigrecooff  =  GetHist(herwigGenReweightSpinoff_hists,{"Reco"+obs});
    handlehists({herwigoff,herwigon,herwiggen,herwigreco,herwiggenoff,herwigrecooff});

    chiscan::chiscan chi_reco_sample(herwigreco,chiscan::chiscan::GetStandarCov(herwigrecooff),herwigrecooff,{});
    chiscan::chiscan chi_gen_sample(herwigreco,chiscan::chiscan::GetStandarCov(herwiggenoff),herwiggenoff,{});
    cout<<" HERWIG "<<" "<<ptrangestr<<" @ lumi = 59.8 fb: "<<chi_reco_sample.calchi2()<<endl;

    TH1D *pythiaoff = GetHist(pythiaSpinoff_hists,{obs});
    TH1D *pythiaon  =  GetHist(pythiaSpinon_hists,{obs});
    TH1D *pythiagen  =  GetHist(pythiaGen_hists,{obs});
    TH1D *pythiareco  =  GetHist(pythiaGen_hists,{"Reco"+obs});
    TH1D *pythiagenoff  =  GetHist(pythiaGenReweightSpinoff_hists,{obs});
    TH1D *pythiarecooff  =  GetHist(pythiaGenReweightSpinoff_hists,{"Reco"+obs});
    handlehists({pythiaoff,pythiaon,pythiagen,pythiareco,pythiagenoff,pythiarecooff});

    chiscan::chiscan chi_reco_sample2(pythiareco,chiscan::chiscan::GetStandarCov(herwigrecooff),pythiarecooff,{});
    chiscan::chiscan chi_gen_sample2(pythiagen,chiscan::chiscan::GetStandarCov(herwiggenoff),pythiagenoff,{});
    cout<<" PYTHIA "<<ptrangestr<<" @ lumi = 59.8 fb: "<<chi_reco_sample2.calchi2()<<endl;

    herwigoff->SetTitle("herwig spin off");
    herwigon->SetTitle("herwig spin on");
    herwiggen->SetTitle("herwig Gen");
    herwigreco->SetTitle("herwig Reco");
    herwiggenoff->SetTitle("herwig Gen Reweight spin off");
    herwigrecooff->SetTitle("herwig Reco Reweight spin off");

    pythiaoff->SetTitle("pythia spin off");
    pythiaon->SetTitle("pythia spin on");
    pythiagen->SetTitle("pythia Gen");
    pythiareco->SetTitle("pythia Reco");
    pythiagenoff->SetTitle("pythia Gen Reweight spin off");
    pythiarecooff->SetTitle("pythia Reco Reweight spin off");

    //auto hists = Draw_Template::SymmetryHists({herwiggen,herwigreco},true);
    //NorTwoPads({herwigoff,herwigon},obs+"/herwigspin"+ptstr+".pdf",ptrangestr);
    NorTwoPads({pythiagenoff,pythiagen,herwiggenoff,herwiggen},"private/"+obs+"_jinitpt450_600_j2pt"+ptstr+"_genpythiavsherwig.pdf",{(TString)ptrangestr,"450<JetPt<600"});
    NorTwoPads({pythiarecooff,pythiareco,herwigrecooff,herwigreco},"private/"+obs+"_jinitpt450_600_j2pt"+ptstr+"_recopythiavsherwig.pdf",{(TString)ptrangestr,"450<JetPt<600"});
    NorTwoPads({herwiggenoff,herwiggen},"private/"+obs+"_jinitpt450_600_j2pt"+ptstr+"_geneffsherwig.pdf",{TString::Format("#chi^{2} = %.2f",chi_gen_sample.calchi2()),(TString)ptrangestr,"450<JetPt<600"});
    NorTwoPads({pythiagenoff,pythiagen},"private/"+obs+"_jinitpt450_600_j2pt"+ptstr+"_geneffpythia.pdf",{TString::Format("#chi^{2} = %.2f",chi_gen_sample2.calchi2()),(TString)ptrangestr,"450<JetPt<600"});
    
    NorTwoPads({herwigrecooff,herwigreco},"private/"+obs+"_jinitpt450_600_j2pt"+ptstr+"_recoeffsherwig.pdf",{TString::Format("#chi^{2} = %.2f",chi_reco_sample.calchi2()),(TString)ptrangestr,"450<JetPt<600"});
    NorTwoPads({pythiarecooff,pythiareco},"private/"+obs+"_jinitpt450_600_j2pt"+ptstr+"_recoeffpythia.pdf",{TString::Format("#chi^{2} = %.2f",chi_reco_sample2.calchi2()),(TString)ptrangestr,"450<JetPt<600"});
    
    TH1D *pythiarecospin=(TH1D *)pythiareco->Clone();
    pythiarecospin->SetTitle("pythia spin effect");
    pythiarecospin->Divide(pythiarecooff);
    TH1D *herwigrecospin=(TH1D *)herwigreco->Clone();
    herwigrecospin->SetTitle("herwig spin effect");
    herwigrecospin->Divide(herwigrecooff);
    NorTwoPads({pythiarecospin,herwigrecospin},"private/"+obs+"_jinitpt450_600_j2pt"+ptstr+"_recoeffpythiavsherwig.pdf",{(TString)ptrangestr,"450<JetPt<600"});

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
    for(int i=0;i<=hist->GetNbinsX();i++){
        hist->SetBinError(i,sqrt(hist->GetBinContent(i)));
    }
    hist->Scale(1.0/hist->Integral());
  }
}
void SymmetryTwoPads(vector<TH1D *> hists,TString filename,TString ExtraText="",vector<double> XbinRange={}){
      auto hists_sym = Draw_Template::SymmetryHists(hists,true);
      ROOTPlot plot1(hists_sym);
      plot1.Load.TwoPads();
      //plot1.SetYRangeRatio(0.7,1.3);
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
      ROOTPlot plot1(hists_sym);
      plot1.Load.TwoPads();
      if (XbinRange.size() == 0)
      {
        plot1.SetXbinRange(1, hists_sym.at(0)->GetNbinsX());
      }
      else
      {
        plot1.SetXbinRange(XbinRange.at(0), XbinRange.at(1));
      }
      //plot1.SetYRangeRatio(0.7,1.3);
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