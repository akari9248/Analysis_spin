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
void drawqq_private(){
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

    // Hists herwigSpinon_hists("../plots/ML_plots/Private_Herwig_spinon_jinitpt450_600_j2pt"+ptstr+"/ML_SpinObservable.root");
    // Hists herwigSpinoff_hists("../plots/ML_plots/Private_Herwig_spinoff_jinitpt450_600_j2pt"+ptstr+"/ML_SpinObservable.root");

    // Hists herwigSpinon_hists("../plots/ML_plots/Maxscore/Private_Herwig_spinon_jinitpt450_600_j2pt"+ptstr+"/ML_SpinObservable.root");
    // Hists herwigSpinoff_hists("../plots/ML_plots/Maxscore/Private_Herwig_spinoff_jinitpt450_600_j2pt"+ptstr+"/ML_SpinObservable.root");
    // Hists pythiaSpinon_hists("../plots/ML_plots/Maxscore/Private_pythia_spinon_jinitpt450_600_j2pt"+ptstr+"/ML_SpinObservable.root");
    // Hists pythiaSpinoff_hists("../plots/ML_plots/Maxscore/Private_pythia_spinoff_jinitpt450_600_j2pt"+ptstr+"/ML_SpinObservable.root");
    // Hists herwigGen_hists("../plots/ML_plots/Maxscore/CMS_herwig_HT200toInf_jinitpt450_600_j2pt"+ptstr+"Gen/ML_SpinObservable.root");
    // Hists herwigReco_hists("../plots/ML_plots/Maxscore/CMS_herwig_HT200toInf_jinitpt450_600_j2pt"+ptstr+"Reco/ML_SpinObservable.root");
    // Hists pythiaGen_hists("../plots/ML_plots/Maxscore/CMS_pythia_Pt470to1000_jinitpt450_600_j2pt"+ptstr+"Gen/ML_SpinObservable.root");
    // Hists pythiaReco_hists("../plots/ML_plots/Maxscore/CMS_pythia_Pt470to1000_jinitpt450_600_j2pt"+ptstr+"Reco/ML_SpinObservable.root");
    // Hists Data("../plots/ML_plots/Maxscore/JetHT_Run2016_UL2016_jinitpt450_600_j2pt160_200Reco/ML_SpinObservable.root");


    Hists herwigSpinon_hists("../plots/ML_plots/Private_Herwig_spinon_jinitpt450_600_j2pt"+ptstr+"/ML_SpinObservable.root");
    Hists herwigSpinoff_hists("../plots/ML_plots/Private_Herwig_spinoff_jinitpt450_600_j2pt"+ptstr+"/ML_SpinObservable.root");
    Hists pythiaSpinon_hists("../plots/ML_plots/Private_pythia_spinon_jinitpt450_600_j2pt"+ptstr+"/ML_SpinObservable.root");
    Hists pythiaSpinoff_hists("../plots/ML_plots/Private_pythia_spinoff_jinitpt450_600_j2pt"+ptstr+"/ML_SpinObservable.root");
    
    Hists herwigGen_hists("../plots/ML_plots/CMS_herwig_Pt-15to7000_20UL18_jinitpt450_600_j2pt"+ptstr+"Gen/ML_SpinObservable.root");
    Hists herwigReco_hists("../plots/ML_plots/CMS_herwig_Pt-15to7000_20UL18_jinitpt450_600_j2pt"+ptstr+"Reco/ML_SpinObservable.root");
    Hists herwigGenReweightSpinoff_hists("../plots/ML_plots/CMS_herwig_Pt-15to7000_20UL18_jinitpt450_600_j2pt"+ptstr+"GenReweightSpinoff/ML_SpinObservable.root");
    Hists herwigRecoReweightSpinoff_hists("../plots/ML_plots/CMS_herwig_Pt-15to7000_20UL18_jinitpt450_600_j2pt"+ptstr+"RecoReweightSpinoff/ML_SpinObservable.root");
    Hists pythiaGen_hists("../plots/ML_plots/CMS_pythia_Pt470to1000_jinitpt450_600_j2pt"+ptstr+"Gen/ML_SpinObservable.root");
    Hists pythiaReco_hists("../plots/ML_plots/CMS_pythia_Pt470to1000_jinitpt450_600_j2pt"+ptstr+"Reco/ML_SpinObservable.root");
    Hists pythiaGenReweightSpinoff_hists("../plots/ML_plots/CMS_pythia_Pt470to1000_jinitpt450_600_j2pt"+ptstr+"GenReweightSpinoff/ML_SpinObservable.root");
    Hists pythiaRecoReweightSpinoff_hists("../plots/ML_plots/CMS_pythia_Pt470to1000_jinitpt450_600_j2pt"+ptstr+"RecoReweightSpinoff/ML_SpinObservable.root");
    Hists Data("../plots/ML_plots/JetHT_Run2016_UL2016_jinitpt450_600_j2pt"+ptstr+"Reco/ML_SpinObservable.root");


    TH1D *herwigoff = GetHist(herwigSpinoff_hists,{obs});
    TH1D *herwigon  =  GetHist(herwigSpinon_hists,{obs});
    TH1D *pythiaoff = GetHist(pythiaSpinoff_hists,{obs});
    TH1D *pythiaon  =  GetHist(pythiaSpinon_hists,{obs});
    TH1D *herwiggen  =  GetHist(herwigGen_hists,{obs});
    TH1D *herwigreco  =  GetHist(herwigGen_hists,{"Reco"+obs});
    TH1D *herwiggenoff  =  GetHist(herwigGenReweightSpinoff_hists,{obs});
    TH1D *herwigrecooff  =  GetHist(herwigGenReweightSpinoff_hists,{"Reco"+obs});
    TH1D *pythiagen  =  GetHist(pythiaGen_hists,{obs});
    TH1D *pythiareco  =  GetHist(pythiaReco_hists,{obs});
    TH1D *pythiagenoff  =  GetHist(pythiaGenReweightSpinoff_hists,{obs});
    TH1D *pythiarecooff  =  GetHist(pythiaRecoReweightSpinoff_hists,{obs});
    TH1D *data  =  GetHist(Data,{obs});
    handlehists({herwigoff,herwigon,herwiggen,herwigreco,herwiggenoff,herwigrecooff,pythiaoff,pythiaon,pythiagen,pythiareco,pythiagenoff,pythiarecooff,data});
    // auto hists_sym = Draw_Template::SymmetryHists({herwiggen,herwigreco,herwiggenoff,herwigrecooff},true);
    // herwiggen=hists_sym[0];
    // herwigreco=hists_sym[1];
    // herwiggenoff=hists_sym[2];
    // herwigrecooff=hists_sym[3];

    chiscan::chiscan chi_gen_on_herwig(herwiggen,chiscan::chiscan::GetStandarCov(herwiggen),herwigon,{});
    chiscan::chiscan chi_gen_off_herwig(herwiggen,chiscan::chiscan::GetStandarCov(herwiggen),herwigoff,{});

    chiscan::chiscan chi_gen_on_herwigoff(herwiggenoff,chiscan::chiscan::GetStandarCov(herwiggenoff),herwigon,{});
    chiscan::chiscan chi_gen_off_herwigoff(herwiggenoff,chiscan::chiscan::GetStandarCov(herwiggenoff),herwigoff,{});

    chiscan::chiscan chi_gen_on_pythia(pythiagen,chiscan::chiscan::GetStandarCov(pythiagen),pythiaon,{});
    chiscan::chiscan chi_gen_off_pythia(pythiagen,chiscan::chiscan::GetStandarCov(pythiagen),pythiaoff,{});

    chiscan::chiscan chi_gen_on_pythiaoff(pythiagenoff,chiscan::chiscan::GetStandarCov(pythiagenoff),pythiaon,{});
    chiscan::chiscan chi_gen_off_pythiaoff(pythiagenoff,chiscan::chiscan::GetStandarCov(pythiagenoff),pythiaoff,{});

    cout<<" herwig : "<<chi_gen_on_herwig.calchi2()<<" "<<chi_gen_off_herwig.calchi2()<<endl;
    cout<<" herwig : "<<chi_gen_on_herwigoff.calchi2()<<" "<<chi_gen_off_herwigoff.calchi2()<<endl;
    cout<<" pythia : "<<chi_gen_on_pythia.calchi2()<<" "<<chi_gen_off_pythia.calchi2()<<endl;
    cout<<" pythia : "<<chi_gen_on_pythiaoff.calchi2()<<" "<<chi_gen_off_pythiaoff.calchi2()<<endl;

    chiscan::chiscan chi_gen_data_pythia(pythiareco,chiscan::chiscan::GetStandarCov(pythiareco),data,{});
    chiscan::chiscan chi_gen_data_herwig(herwigreco,chiscan::chiscan::GetStandarCov(herwigreco),data,{});
    chiscan::chiscan chi_gen_data_herwigoff(herwigrecooff,chiscan::chiscan::GetStandarCov(herwigrecooff),data,{});
    chiscan::chiscan chi_gen_data_pythiaoff(pythiarecooff,chiscan::chiscan::GetStandarCov(pythiarecooff),data,{});
    cout<<" pythia vs data : "<<chi_gen_data_pythia.calchi2()<<"  herwig vs data :"<<chi_gen_data_herwig.calchi2()<<endl;
    cout<<" herwig on vs data : "<<chi_gen_data_herwig.calchi2()<<"  herwig off vs data :"<<chi_gen_data_herwigoff.calchi2()<<endl;
    cout<<" pythia on vs data : "<<chi_gen_data_pythia.calchi2()<<"  pythia off vs data :"<<chi_gen_data_pythiaoff.calchi2()<<endl;

    herwigoff->SetTitle("Herwig spin off");
    herwigon->SetTitle("Herwig spin on");
    herwiggen->SetTitle("Herwig Gen");
    herwigreco->SetTitle("Herwig Reco");
    herwiggenoff->SetTitle("Herwig Gen Reweight spin off");
    herwigrecooff->SetTitle("Herwig Reco Reweight spin off");
    pythiaoff->SetTitle("pythia spin off");
    pythiaon->SetTitle("pythia spin on");
    pythiagen->SetTitle("pythia Gen");
    pythiareco->SetTitle("pythia Reco");
    pythiagenoff->SetTitle("pythia Gen Reweight spin off");
    pythiarecooff->SetTitle("pythia Reco Reweight spin off");
    data->SetTitle("Data");
    //auto hists = Draw_Template::SymmetryHists({herwiggen,herwigreco},true);
    //NorTwoPads({herwigoff,herwigon},obs+"/herwigspin"+ptstr+".pdf",ptrangestr);
    NorTwoPads({herwigoff,herwigon,herwiggen,herwigreco,data},"private/"+obs+"_jinitpt450_600_j2pt"+ptstr+"_herwig.pdf",{(TString)ptrangestr,"450<JetPt<600"});
    NorTwoPads({herwigoff,herwigon,herwiggen,herwiggenoff},"private/"+obs+"_jinitpt450_600_j2pt"+ptstr+"_MC_herwig.pdf",{(TString)ptrangestr,"450<JetPt<600"});
    NorTwoPads({herwiggenoff,herwiggen},"private/"+obs+"_jinitpt450_600_j2pt"+ptstr+"_CMSMC_herwigGen.pdf",{(TString)ptrangestr,"450<JetPt<600"});
    NorTwoPads({herwigrecooff,herwigreco},"private/"+obs+"_jinitpt450_600_j2pt"+ptstr+"_CMSMC_herwigReco.pdf",{(TString)ptrangestr,"450<JetPt<600"});

    NorTwoPads({pythiaoff,pythiaon,pythiagen,pythiareco,data},"private/"+obs+"_jinitpt450_600_j2pt"+ptstr+"_pythia.pdf",{(TString)ptrangestr,"450<JetPt<600"});
    NorTwoPads({pythiaoff,pythiaon,pythiagen,pythiagenoff},"private/"+obs+"_jinitpt450_600_j2pt"+ptstr+"_MC_pythia.pdf",{(TString)ptrangestr,"450<JetPt<600"});
    NorTwoPads({pythiagenoff,pythiagen},"private/"+obs+"_jinitpt450_600_j2pt"+ptstr+"_CMSMC_pythiaGen.pdf",{(TString)ptrangestr,"450<JetPt<600"});    
    NorTwoPads({pythiarecooff,pythiareco},"private/"+obs+"_jinitpt450_600_j2pt"+ptstr+"_CMSMC_pythiaReco.pdf",{(TString)ptrangestr,"450<JetPt<600"});

    NorTwoPads({data,herwigreco,pythiareco},"private/"+obs+"_jinitpt450_600_j2pt"+ptstr+"_datavsMC.pdf",{(TString)ptrangestr,"450<JetPt<600"});
    NorTwoPads({data,herwigreco,herwigrecooff},"private/"+obs+"_jinitpt450_600_j2pt"+ptstr+"_datavsherwig.pdf",{(TString)ptrangestr,"450<JetPt<600"});
    NorTwoPads({data,pythiareco,pythiarecooff},"private/"+obs+"_jinitpt450_600_j2pt"+ptstr+"_datavspythia.pdf",{(TString)ptrangestr,"450<JetPt<600"});
    NorTwoPads({pythiaoff,pythiaon,herwigoff,herwigon},"private/"+obs+"_jinitpt450_600_j2pt"+ptstr+"_pythiavsherwig.pdf",{(TString)ptrangestr,"450<JetPt<600"});
    herwigreco->Divide(herwiggen);
    pythiareco->Divide(pythiagen);
    NorTwoPads({herwigreco,pythiareco},"private/"+obs+"_jinitpt450_600_j2pt"+ptstr+"_deteff.pdf",{(TString)ptrangestr,"450<JetPt<600"});
    //NorTwoPads({herwigoff,herwigon},"private/"+obs+"_jinitpt450_600_j2pt"+ptstr+".pdf",{(TString)ptrangestr,"200<JetPt<800"});

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