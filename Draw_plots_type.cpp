// gInterpreter->AddIncludePath("/home/zlin/.local/include");
#include "TFile.h"
#include "TH1D.h"
#include "TLorentzVector.h"
#include "TTree.h"
#include "include/DataInfoML.h"
#include "include/Draw_Template.h"
#include "include/Hists.h"
#include "include/JetBranch.h"
#include "include/Process_bar.h"
#include "include/SampleAnalyzer.h"
#include <iostream>
#include <iomanip>
#include <cmath>
#include "include/common_tool.h"
#include "include/PlaneObservable.h"

class EventsAnalyzer : public SampleAnalyzer<DataInfoML> {
public:
  vector<string> spin_strs;
  vector<string> cut_strs;
  int count;
  CommonTool::Options options;
  EventsAnalyzer(CommonTool::Options _options){
    options=_options;
  }
  void initialize() override
  {
    t->Add((TString)options.inputFolder + "/*.root/DataInfo");
    hists.addHist("MC_number", 2, 0, 2);

    hists.addHist("phi_qq" , 100, 0, TMath::Pi());
    hists.addHist("phi_gg", 100, 0, TMath::Pi());
    hists.addHist("theta_qq", 100, 0, TMath::Pi());
    hists.addHist("theta_gg", 100, 0, TMath::Pi());
    hists.addHist("theta2_qq", 100, 0, TMath::Pi());
    hists.addHist("theta2_gg", 100, 0, TMath::Pi());

    hists.addHist("phi3_qq" , 100, 0, TMath::Pi());
    hists.addHist("phi3_gg", 100, 0, TMath::Pi());

    for(int i=0;i<=5;i++){
      hists.addHist((string)TString::Format("phi3_type%d",i), 100, 0, TMath::Pi());
      hists.addHist((string)TString::Format("phi_type%d",i), 100, 0, TMath::Pi());
    }
  }
  void analyze() override {
    if(events->PassPileUpRm==0) {
      return;
    }
    PlaneObservable::plane plane1(events->pt_1,events->eta_1,events->phi_1,events->e_1,
                                  events->pt_2,events->eta_2,events->phi_2,events->e_2);
    PlaneObservable::plane plane2(events->pt_3,events->eta_3,events->phi_3,events->e_3,
                                  events->pt_4,events->eta_4,events->phi_4,events->e_4);
    PlaneObservable::plane plane3(events->pt_5,events->eta_5,events->phi_5,events->e_5,
                                  events->pt_6,events->eta_6,events->phi_6,events->e_6);
    hists["MC_number"]->Fill(0);
    hists["MC_number"]->Fill(1,events->NextPassedNumber);
    bool isqq =  events->type==2 && events->kt>2;
    bool isgg =  events->type==1 && events->kt>2;
    hists[(string)TString::Format("phi_type%d",events->type)]->Fill(PlaneObservable::DeltaPhi(plane1,plane2));
    hists[(string)TString::Format("phi3_type%d",events->type3)]->Fill(PlaneObservable::DeltaPhi(plane1,plane3));
    if(isqq){
      hists["phi_qq"]->Fill(events->Phi);
      hists["theta_qq"]->Fill(events->theta);
      hists["theta2_qq"]->Fill(events->theta2);
    }else if(isgg){
      hists["phi_gg"]->Fill(events->Phi);
      hists["theta_gg"]->Fill(events->theta);
      hists["theta2_gg"]->Fill(events->theta2);
    }
    if(events->type3==2&&events->z1>0.4){
      hists["phi3_qq"]->Fill(events->Phi3);
    }else if(events->type3==1&&events->z1>0.4){
      hists["phi3_gg"]->Fill(events->Phi3);
    }
  }
};
// void Draw_plots_mini2(){
int main(int argc, char *argv[])
{
  CommonTool::Options options = CommonTool::parseArguments(argc, argv);

  TH1D *accumulative(TH1D * hist, int direct = 1, bool normalize = true);
  EventsAnalyzer analyzerspinon(options);
  // analyzerspinon.run_frac_rand(0.15);
  analyzerspinon.run_frac(1);
  // analyzerspinon.run(10000);
  string folder = options.outputFolder;
  analyzerspinon.finalize( folder + "/ML_SpinObservable.root");
  return 0;
}

TH1D *accumulative(TH1D *hist, int direct = 1,bool normalize=true) {
  TH1D *hist_out = (TH1D *)hist->Clone();
  if (direct == 1) {
    double sum = 0;
    double sumw2 = 0;
    for (int i = 0; i < hist->GetNbinsX() + 2; i++) {
      sum += hist->GetBinContent(i);
      sumw2 += hist->GetBinError(i) * hist->GetBinError(i);
      hist_out->SetBinContent(i, sum);
      hist_out->SetBinError(i, sqrt(sumw2));
    }
    if(normalize) hist_out->Scale(1.0 / hist_out->GetBinContent(hist->GetNbinsX()));
  } else if (direct == -1) {
    double sum = 0;
    double sumw2 = 0;
    for (int i = hist->GetNbinsX(); i > 0; i--) {
      sum += hist->GetBinContent(i);
      sumw2 += hist->GetBinError(i) * hist->GetBinError(i);
      hist_out->SetBinContent(i, sum);
      hist_out->SetBinError(i, sqrt(sumw2));
    }
    if(normalize) hist_out->Scale(1.0 / hist_out->GetBinContent(1));
  }
  return hist_out;
}
