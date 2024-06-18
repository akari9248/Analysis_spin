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
    t->Add("ML_OUT/"
           "train_outhadron_spinoff_pythia/"
           "kto4_selectopt0_Chunk*.root/DNNTrainTree");

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

    hists.addHist("score_qq_spinon", 100, 0, 1);
    hists.addHist("score_gg_spinon", 100, 0, 1);
    hists.addHist("score_rest_spinon", 100, 0, 1);

    hists.addHist("score_qq_spinoff", 100, 0, 1);
    hists.addHist("score_gg_spinoff", 100, 0, 1);
    hists.addHist("score_rest_spinoff", 100, 0, 1);
  }
  void analyze() override {
    bool isqq = events->score > 0.9 && (events->type == 0);
    bool isgg = events->score < 0.1 && (events->type == 0);
    isqq = events->score > 0.8 && (events->type == 0);
    isgg = events->score < 0.2 && (events->type == 0);
    isqq = events->score > 0.9 && events->score < 1 ;
    isgg = events->score > 0.0 && events->score < 0.1;
    bool isrest = !(isqq || isgg);
    double phi = events->Phi;
    if (events->spin == 1) {
      if (isqq) {
        hists["phi_qq_spinon"]->Fill(phi);
      } else if (isgg) {
        hists["phi_gg_spinon"]->Fill(phi);
      } else if (isrest) {
        hists["phi_rest_spinon"]->Fill(phi);
      }
      hists["phi_full_spinon"]->Fill(phi);
      if (events->type == 2) {
        hists["score_qq_spinon"]->Fill(events->score);
      } else if (events->type == 1) {
        hists["score_gg_spinon"]->Fill(events->score);
      } else if (events->type == 0) {
        hists["score_rest_spinon"]->Fill(events->score);
      }
    } else if (events->spin == 0) {
      if (isqq) {
        hists["phi_qq_spinoff"]->Fill(phi);
      } else if (isgg) {
        hists["phi_gg_spinoff"]->Fill(phi);
      } else if (isrest) {
        hists["phi_rest_spinoff"]->Fill(phi);
      }
      hists["phi_full_spinoff"]->Fill(phi);
      if (events->type == 2) {
        hists["score_qq_spinoff"]->Fill(events->score);
      } else if (events->type == 1) {
        hists["score_gg_spinoff"]->Fill(events->score);
      } else if (events->type == 0) {
        hists["score_rest_spinoff"]->Fill(events->score);
      }
    }
    if (events->type == 2) {
      hists["score_qq"]->Fill(events->score);
    } else if (events->type == 1) {
      hists["score_gg"]->Fill(events->score);
    } else if (events->type == 0) {
      hists["score_rest"]->Fill(events->score);
    }
  }
};
// void Draw_plots_mini2(){
int main() {
  TH1D *accumulative(TH1D * hist, int direct = 1);
  EventsAnalyzer analyzerspinon;
  analyzerspinon.run();
  analyzerspinon.finalize("ML_plot.root");

  vector<string> types = {"qq", "gg", "rest", "full"};
  for (auto &type : types) {
    TH1D *hist_spinon = (TH1D *)analyzerspinon.hists["phi_" + type + "_spinon"];
    TH1D *hist_spinoff =
        (TH1D *)analyzerspinon.hists["phi_" + type + "_spinoff"];
    hist_spinon->SetTitle("spin on");
    hist_spinoff->SetTitle("spin off");
    vector<TH1D *> hists_draw = {hist_spinoff, hist_spinon};
    Draw_Template::SymmetryTwoPads(hists_draw, "ML" + type + "_phi_onoff.pdf",
                                   "plane type: " + type);
  }
  vector<string> spins = {"", "_spinon", "_spinoff"};
  for (auto &spin : spins) {
    TH1D *score_qq = (TH1D *)analyzerspinon.hists["score_qq" + spin];
    TH1D *score_gg = (TH1D *)analyzerspinon.hists["score_gg" + spin];
    TH1D *score_rest = (TH1D *)analyzerspinon.hists["score_rest" + spin];
    Draw_Template::NorOnePad({score_qq, score_gg, score_rest},
                             "score" + spin + ".pdf");
    TH1D *score_qq_accuforward = accumulative(score_qq, 1);
    TH1D *score_gg_accuforward = accumulative(score_gg, 1);
    TH1D *score_rest_accuforward = accumulative(score_rest, 1);
    Draw_Template::TwoPads(
        {score_gg_accuforward,score_qq_accuforward,  score_rest_accuforward},
        "score_accuforward" + spin + ".pdf");
    TH1D *score_qq_accubackward = accumulative(score_qq, -1);
    TH1D *score_gg_accubackward = accumulative(score_gg, -1);
    TH1D *score_rest_accubackward = accumulative(score_rest, -1);
    Draw_Template::TwoPads(
        {score_qq_accubackward, score_gg_accubackward, score_rest_accubackward},
        "score_accubackward" + spin + ".pdf");
  }

  return 0;
}

TH1D *accumulative(TH1D *hist, int direct = 1) {
  TH1D *hist_out = (TH1D *)hist->Clone();
  if (direct == 1) {
    double sum = 0;
    double sumw2 = 0;
    for (int i = 1; i < hist->GetNbinsX() + 1; i++) {
      sum += hist->GetBinContent(i);
      sumw2 += hist->GetBinError(i) * hist->GetBinError(i);
      hist_out->SetBinContent(i, sum);
      hist_out->SetBinError(i, sqrt(sumw2));
    }
    hist_out->Scale(1.0 / hist_out->GetBinContent(hist->GetNbinsX()));
  } else if (direct == -1) {
    double sum = 0;
    double sumw2 = 0;
    for (int i = hist->GetNbinsX(); i > 0; i--) {
      sum += hist->GetBinContent(i);
      sumw2 += hist->GetBinError(i) * hist->GetBinError(i);
      hist_out->SetBinContent(i, sum);
      hist_out->SetBinError(i, sqrt(sumw2));
    }
    hist_out->Scale(1.0 / hist_out->GetBinContent(1));
  }
  return hist_out;
}