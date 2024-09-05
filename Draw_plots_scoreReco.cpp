// gInterpreter->AddIncludePath("/home/zlin/.local/include");
#include "TFile.h"
#include "TH1D.h"
#include "TLorentzVector.h"
#include "TTree.h"
#include "include/DNNTrainTree.h"
#include "include/Draw_Template.h"
#include "include/Hists.h"
#include "include/JetBranch.h"
#include "include/Process_bar.h"
#include "include/SampleAnalyzer.h"
#include <iostream>
#include <iomanip>
#include <cmath>
#include "include/common_tool.h"
#include "include/Draw_Template.h"
#include "include/chiscan.h"
class EventsAnalyzer : public SampleAnalyzer<DNNTrainTree> {
public:
  vector<string> spin_strs;
  vector<string> cut_strs;
  int count;
  CommonTool::Options options;
  EventsAnalyzer(CommonTool::Options _options){
    options=_options;
  }
  void initialize() override {
    t->Add((TString)options.inputFolder+"/Chunk*.root/DNNTrainTree");
    events = new DNNTrainTree(t);
    hists.addHist("Genphi_typeqq", 10 , 0, TMath::Pi(),100,0,1);
    hists.addHist("GendphiX_typeqq", 10 , 0, TMath::Pi(),100,0,1);
    hists.addHist("Recophi_typeqq", 10 , 0, TMath::Pi(),100,0,1);
    hists.addHist("RecodphiX_typeqq", 10 , 0, TMath::Pi(),100,0,1);
  }
  void analyze() override {
    for(int i=0;i<events->Recotype2->size();i++){
      double score2_weight[4] = {1,20,1,200};
      double score2 =events->Recoscore2->at(i)*score2_weight[2]*5/(events->Recoscore0->at(i)*score2_weight[0]+events->Recoscore1->at(i)*score2_weight[1]+events->Recoscore2->at(i)*score2_weight[2]+events->Recoscore3->at(i)*score2_weight[3]);
      ((TH2D *)hists["Recophi_typeqq"])->Fill(events->RecoPhi2->at(i),score2,events->GeneratorWeight);
        ((TH2D *)hists["RecodphiX_typeqq"])->Fill(events->RecodPhi12_X2->at(i),score2,events->GeneratorWeight);
     
    }
    for(int i=0;i<events->Gentype2->size();i++){
      double score2_weight[4] = {1,20,1,200};
      double score2 =events->Genscore2->at(i)*score2_weight[2]*5/(events->Genscore0->at(i)*score2_weight[0]+events->Genscore1->at(i)*score2_weight[1]+events->Genscore2->at(i)*score2_weight[2]+events->Genscore3->at(i)*score2_weight[3]);
        ((TH2D *)hists["Genphi_typeqq"])->Fill(events->GenPhi2->at(i),score2,events->GeneratorWeight);
        ((TH2D *)hists["GendphiX_typeqq"])->Fill(events->GendPhi12_X2->at(i),score2,events->GeneratorWeight);
      
    }

  }


};
void SymmetryTwoPads(vector<TH1D *> hists,TString filename,TString ExtraText="",vector<TString> legend_name={}){
      chiscan::chiscan chi2(hists[0],chiscan::chiscan::GetStandarCov(hists[0]),hists[1],{});
      
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
      plot1.AddExtraText({ExtraText,TString::Format("#chi^{2} = %.2f",chi2.calchi2())});
      plot1.Draw();
      // plot1.Write(TString::Format("output/Unweighted%d.png", i));
      plot1.Write(
          filename);
      // plot1.Write(
      //     "zlin://mnt/c/Users/win10/machine_learning/plots2/"+filename);
}
// void Draw_plots_mini2(){
int main(int argc, char *argv[])
{
  CommonTool::Options options;
  options.inputFolder = "/home/zlin/Machine_learning/ML/Datasets/Prediction/CMS_herwig_Pt-15to7000Run3jinitpt6007000j2pt1307000_FourLabel_unmatched";
  EventsAnalyzer spinon_sample(options);
  options.inputFolder = "/home/zlin/Machine_learning/ML/Datasets/Prediction/CMS_herwig_Pt-15to7000Run3_SpinOFFjinitpt6007000j2pt1307000_FourLabel_unmatched";
  EventsAnalyzer spinoff_sample(options);
  options.inputFolder = "/home/zlin/Machine_learning/ML/Datasets/Prediction/CMS_pythia_Pt-15to7000Run3jinitpt6007000j2pt1307000_FourLabel_unmatched";
  EventsAnalyzer spinon_pythia_sample(options);

  // spinon_sample.run_frac(1);
  // spinoff_sample.run_frac(1);
  // spinon_pythia_sample.run_frac(1);
  // spinon_sample.finalize("draw/cmsmc_on_2D.root");
  // spinoff_sample.finalize("draw/cmsmc_off_2D.root");
  // spinon_pythia_sample.finalize("draw/cmsmc_pythiaon_2D.root");
  spinon_sample.hists = Hists("draw/cmsmc_on_2D.root");
  spinoff_sample.hists = Hists("draw/cmsmc_off_2D.root");
  spinon_pythia_sample.hists = Hists("draw/cmsmc_pythiaon_2D.root");


  // spinon_sample.run(100000000);
  // spinoff_sample.run(100000000);

  
  vector<string> types = {"typeqq"};
  for (int i=0;i<10;i++)
  {
    TString range = TString::Format("on_scorecut0_%d_0_%d",i,i+1);
    TH1D *hist_cmsmc_spinon =((TH2D *)spinon_sample.hists["Recophi_typeqq"])->ProjectionX("on"+range,i*10,(i+1)*10);
    TH1D *hist_cmsmc_spinoff = ((TH2D *)spinoff_sample.hists["Recophi_typeqq"])->ProjectionX("off"+range,i*10,(i+1)*10);
    TH1D *hist_cmspythia_spinoff = ((TH2D *)spinon_pythia_sample.hists["Recophi_typeqq"])->ProjectionX("off_pythia"+range,i*10,(i+1)*10);
    hist_cmsmc_spinon->SetTitle("CMS Herwig Spinon");
    hist_cmsmc_spinoff->SetTitle("CMS Herwig Spinoff");
    hist_cmspythia_spinoff->SetTitle("CMS Pythia Spinon");
    vector<TH1D *> hists_draw = {hist_cmsmc_spinoff,hist_cmsmc_spinon,hist_cmspythia_spinoff};

    SymmetryTwoPads(hists_draw,"draw/cmsmc/Reco"+range+ ".pdf",
                    "score range: " + range);
  }
  for (int i=0;i<10;i++)
  {
    TString range = TString::Format("on_scorecut0_%d_0_%d",i,i+1);
    TH1D *hist_cmsmc_spinon =((TH2D *)spinon_sample.hists["Genphi_typeqq"])->ProjectionX("on"+range,i*10,(i+1)*10);
    TH1D *hist_cmsmc_spinoff = ((TH2D *)spinoff_sample.hists["Genphi_typeqq"])->ProjectionX("off"+range,i*10,(i+1)*10);
    TH1D *hist_cmspythia_spinoff = ((TH2D *)spinon_pythia_sample.hists["Genphi_typeqq"])->ProjectionX("off_pythia"+range,i*10,(i+1)*10);

    hist_cmsmc_spinon->SetTitle("CMS Herwig Spinon");
    hist_cmsmc_spinoff->SetTitle("CMS Herwig Spinoff");
    hist_cmspythia_spinoff->SetTitle("CMS Pythia Spinon");
    vector<TH1D *> hists_draw = {hist_cmsmc_spinoff,hist_cmsmc_spinon,hist_cmspythia_spinoff};

    SymmetryTwoPads(hists_draw,"draw/cmsmc/Gen"+range+ ".pdf",
                    "score range: " + range);
  }
  return 0;
}

