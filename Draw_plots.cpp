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
    t->Add((TString)options.inputFolder+"/Chunk1*.root/DataInfo");
    for(int i=0;i<=5;i++){
      hists.addHist((string)TString::Format("phi_type%d",i), 10 , 0, TMath::Pi());
      hists.addHist((string)TString::Format("dphiX_type%d",i), 10 , 0, TMath::Pi());
    }
  }
  void analyze() override {
    for(int i=0;i<events->type2_Hadron->size();i++){
      hists[(string)TString::Format("phi_type%d",events->type2_Hadron->at(i))]->Fill(events->Phi2_Hadron->at(i));
      hists[(string)TString::Format("dphiX_type%d",events->type2_Hadron->at(i))]->Fill(events->dPhi12_X2_Hadron->at(i));
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
  options.inputFolder = "/extdisk/zlin/Machine_learning/RecoPlanes/Private_Herwig_spinon";
  EventsAnalyzer spinon_sample(options);
  options.inputFolder = "/extdisk/zlin/Machine_learning/RecoPlanes/Private_Herwig_spinoff";
  EventsAnalyzer spinoff_sample(options);
  cout<<"yyyy"<<endl;
  spinon_sample.run_frac(1);
  spinoff_sample.run_frac(1);
  spinon_sample.finalize("draw/spinon.root");
  spinoff_sample.finalize("draw/spinoff.root");

  vector<string> types = {"type0", "type1", "type2", "type3", "type4", "type5"};

  for (auto &type : types)
  {
    TH1D *hist_spinon = (TH1D *)spinon_sample.hists["phi_" + type];
    TH1D *hist_spinoff = (TH1D *)spinoff_sample.hists["phi_" + type];
    hist_spinon->SetTitle("spin on");
    hist_spinoff->SetTitle("spin off");
    vector<TH1D *> hists_draw = {hist_spinoff, hist_spinon};
    SymmetryTwoPads(hists_draw,"draw/"+type+ ".pdf",
                    "plane type: " + type);
  }
  for (auto &type : types)
  {
    TH1D *hist_spinon = (TH1D *)spinon_sample.hists["dphiX_" + type];
    TH1D *hist_spinoff = (TH1D *)spinoff_sample.hists["dphiX_" + type];
    hist_spinon->SetTitle("spin on");
    hist_spinoff->SetTitle("spin off");
    vector<TH1D *> hists_draw = {hist_spinoff, hist_spinon};
    SymmetryTwoPads(hists_draw,"draw/"+type+ "dphiX.pdf",
                    "plane type: " + type);
  }
  return 0;
}
