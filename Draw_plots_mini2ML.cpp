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
class EventsAnalyzer : public SampleAnalyzer<DataInfoML> {
public:
  void initialize() override {
    t->Add("ML_OUT/train_outhadron_spinon_64_128_128_64_16_kt_batch64/kto4_selectopt0_Chunk*.root/DNNTrainTree");

    hists.addHist("phi_qq_spinon", 100, 0, TMath::Pi());
    hists.addHist("phi_gg_spinon", 100, 0, TMath::Pi());
    hists.addHist("phi_rest_spinon", 100, 0, TMath::Pi());
    hists.addHist("phi_full_spinon", 100, 0, TMath::Pi());
    hists.addHist("phi_qq_spinoff", 100, 0, TMath::Pi());
    hists.addHist("phi_gg_spinoff", 100, 0, TMath::Pi());
    hists.addHist("phi_rest_spinoff", 100, 0, TMath::Pi());
    hists.addHist("phi_full_spinoff", 100, 0, TMath::Pi());

    hists.addHist("score_qq", 100, 0, 1);
    hists.addHist("score_gg", 100, 0, 1);
    hists.addHist("score_rest", 100, 0, 1);
  }
  void analyze() override {
    bool isqq = events->score > 0.9 && (events->type==0);
    bool isgg = events->score < 0.1 && (events->type==0);
    isqq = events->score > 0.9 && (events->type==0);
    isgg = events->score < 0.1 && (events->type==0);

    bool isrest = !(isqq || isgg);
    double phi = events->phi;
    if (events->spin == 1) {
      if (isqq) {
        hists["phi_qq_spinon"]->Fill(phi);
        
      } else if (isgg) {
        hists["phi_gg_spinon"]->Fill(phi);
        hists["score_gg"]->Fill(phi);
      } else if (isrest) {
        hists["phi_rest_spinon"]->Fill(phi);
        hists["score_rest"]->Fill(phi);
      }
      hists["phi_full_spinon"]->Fill(phi);

      if(events->type==2){
        hists["score_qq"]->Fill(events->score);
      }else if(events->type==1){
        hists["score_gg"]->Fill(events->score);
      }else if(events->type==0){
        hists["score_rest"]->Fill(events->score);
      }
      
    } else if (events->spin == 0) {
      isqq = events->type==2;
      isgg = events->type==1;
      if (isqq) {
        hists["phi_qq_spinoff"]->Fill(phi);
      } else if (isgg) {
        hists["phi_gg_spinoff"]->Fill(phi);
      } else if (isrest) {
        hists["phi_rest_spinoff"]->Fill(phi);
      }
      hists["phi_full_spinoff"]->Fill(phi);
    }
  }
};
// void Draw_plots_mini2(){
int main() {
  EventsAnalyzer analyzerspinon;
  analyzerspinon.run();
  analyzerspinon.finalize("ML_plot.root");

  vector<string> types = {"qq", "gg", "rest", "full"};
  for(auto &type :types){
    TH1D *hist_spinon = (TH1D *)analyzerspinon.hists["phi_"+type+"_spinon"];
     TH1D *hist_spinoff = (TH1D *)analyzerspinon.hists["phi_"+type+"_spinoff"];
     hist_spinon->SetTitle("spin on");
     hist_spinoff->SetTitle("spin off");
     vector<TH1D *> hists_draw = {hist_spinoff,hist_spinon };
     Draw_Template::SymmetryTwoPads(hists_draw, "ML"+type+"_phi_onoff.pdf","plane type: "+type);
  }
  TH1D *score_qq = (TH1D *)analyzerspinon.hists["score_qq"];
  TH1D *score_gg = (TH1D *)analyzerspinon.hists["score_gg"];
  TH1D *score_rest = (TH1D *)analyzerspinon.hists["score_rest"];
  Draw_Template::NorOnePad({score_qq,score_gg,score_rest}, "score.pdf");


  return 0;
}