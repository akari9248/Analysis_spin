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
    t->Add((TString)options.inputFolder + "/Chunk*.root/DNNTrainTree");
    hists.addHist("MC_number", 2, 0, 2);

    hists.addHist("phi_qq" , 100, 0, TMath::Pi());
    hists.addHist("phi_gg", 100, 0, TMath::Pi());
    hists.addHist("theta_qq", 100, 0, TMath::Pi());
    hists.addHist("theta_gg", 100, 0, TMath::Pi());
    hists.addHist("theta2_qq", 100, 0, TMath::Pi());
    hists.addHist("theta2_gg", 100, 0, TMath::Pi());
  }
  void analyze() override {
    if(events->PassPileUpRm==0) {
      return;
    }
    hists["MC_number"]->Fill(0);
    hists["MC_number"]->Fill(1,events->NextPassedNumber);
    double likelihoods[4] = {events->score0, events->score1, events->score2, events->score3};
    double priors[4] = {0.004, 0.09, 0.004, 0.86};
    double marginal_probability = 0.0;
    for (int i = 0; i < 4; ++i) {
        marginal_probability += likelihoods[i] * priors[i];
    }

    double posteriors[4];
    for (int i = 0; i < 4; ++i) {
        posteriors[i] = (likelihoods[i] * priors[i]) / marginal_probability;
    }

    int predicted_class = std::distance(posteriors, std::max_element(posteriors, posteriors + 4));
    double score0 = posteriors[0];
    double score1 = posteriors[1];
    double score2 = posteriors[2];

    double score2_weight[4] = {1,20,1,200};
    score2 = events->score2*score2_weight[2]*5/(events->score0*score2_weight[0]+events->score1*score2_weight[1]+events->score2*score2_weight[2]+events->score3*score2_weight[3]);
    double score1_weight[4] = {1,1,1,1};
    score1 = events->score1*score1_weight[1]*50/(events->score0*score1_weight[0]+events->score1*score1_weight[1]+events->score2*score1_weight[2]+events->score3*score1_weight[3]);
    
    bool isqq =  score2 > 0.55 && events->kt0>20 && events->kt > 2.0;
    bool isgg =  score1 > 0.5  && events->kt0>20 && events->kt > 2.0;
    if(isqq){
      hists["phi_qq"]->Fill(events->Phi);
      hists["theta_qq"]->Fill(events->theta);
      hists["theta2_qq"]->Fill(events->theta2);
    }else if(isgg){
      hists["phi_gg"]->Fill(events->Phi);
      hists["theta_gg"]->Fill(events->theta);
      hists["theta2_gg"]->Fill(events->theta2);
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
