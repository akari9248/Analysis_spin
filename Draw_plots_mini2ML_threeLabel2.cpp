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
  vector<string> spin_strs;
  vector<string> cut_strs;
  void initialize() override {
    t->Add("/extdisk/zlin/Machine_learning/ML_OUT/train_outdnn_herwig_hadron_spinoff_pythia_fourLabels2_matchedrest_j2pt80_120/kto4_selectopt0_Chunk*.root/DNNTrainTree");
    //t->Add("/extdisk/zlin/Machine_learning/ML_OUT/train_outdnn_hadron_spinoff_pythia_fourLabels2_matchedrest_j2pt80_120/kto4_selectopt0_Chunk*.root/DNNTrainTree");
    // t->Add("ML_OUT/"
    //        "train_outdnn_hadron_spinoff_pythia_fourLabels_matchedrest_j2pt160_200/"
    //        "kto4_selectopt0_Chunk*.root/DNNTrainTree");
        
    // t->Add("ML_OUT/"
    //        "kto4_selectopt4_Chunk*.root/DNNTrainTree");
    // t->Add("ML_OUT/"
    //        "train_outhadron_spinoff_pythia_threeLabel/"
    //        "kto4_selectopt0_Chunk*.root/DNNTrainTree");
    cut_strs={"","_z2cut01","_z2cut12","_z2cut23","_z2cut34","_z2cut45","_z1cut01","_z1cut12","_z1cut23","_z1cut34","_z1cut45"};
    for(auto cut_str:cut_strs){

      hists.addHist("phi_qq_spinon"+cut_str, 100, 0, TMath::Pi());
      hists.addHist("phi_gg_spinon"+cut_str, 100, 0, TMath::Pi());
      hists.addHist("phi_rest_spinon"+cut_str, 100, 0, TMath::Pi());
      hists.addHist("phi_unmatched_spinon"+cut_str, 100, 0, TMath::Pi());
      hists.addHist("phi_full_spinon"+cut_str, 100, 0, TMath::Pi());

      hists.addHist("phi_qq_qq_spinon"+cut_str, 100, 0, TMath::Pi());
      hists.addHist("phi_qq_gg_spinon"+cut_str, 100, 0, TMath::Pi());
      hists.addHist("phi_qq_rest_spinon"+cut_str, 100, 0, TMath::Pi());
      hists.addHist("phi_qq_unmatched_spinon"+cut_str, 100, 0, TMath::Pi());

      hists.addHist("phi_gg_qq_spinon"+cut_str, 100, 0, TMath::Pi());
      hists.addHist("phi_gg_gg_spinon"+cut_str, 100, 0, TMath::Pi());
      hists.addHist("phi_gg_rest_spinon"+cut_str, 100, 0, TMath::Pi());
      hists.addHist("phi_gg_unmatched_spinon"+cut_str, 100, 0, TMath::Pi());

      hists.addHist("phi_qq_spinoff"+cut_str, 100, 0, TMath::Pi());
      hists.addHist("phi_gg_spinoff"+cut_str, 100, 0, TMath::Pi());
      hists.addHist("phi_rest_spinoff"+cut_str, 100, 0, TMath::Pi());
      hists.addHist("phi_unmatched_spinoff"+cut_str, 100, 0, TMath::Pi());
      hists.addHist("phi_full_spinoff"+cut_str, 100, 0, TMath::Pi());

      hists.addHist("phi_qq_qq_spinoff"+cut_str, 100, 0, TMath::Pi());
      hists.addHist("phi_qq_gg_spinoff"+cut_str, 100, 0, TMath::Pi());
      hists.addHist("phi_qq_rest_spinoff"+cut_str, 100, 0, TMath::Pi());
      hists.addHist("phi_qq_unmatched_spinoff"+cut_str, 100, 0, TMath::Pi());

      hists.addHist("phi_gg_qq_spinoff"+cut_str, 100, 0, TMath::Pi());
      hists.addHist("phi_gg_gg_spinoff"+cut_str, 100, 0, TMath::Pi());
      hists.addHist("phi_gg_rest_spinoff"+cut_str, 100, 0, TMath::Pi());
      hists.addHist("phi_gg_unmatched_spinoff"+cut_str, 100, 0, TMath::Pi());
    }

    spin_strs={"","_spinon","_spinoff"};
    for(auto spin_str:spin_strs){
      hists.addHist("score0_qq"+spin_str, 100, 0, 1);
      hists.addHist("score0_gg"+spin_str, 100, 0, 1);
      hists.addHist("score0_rest"+spin_str, 100, 0, 1);
      hists.addHist("score0_unmatched"+spin_str, 100, 0, 1);

      hists.addHist("score1_qq"+spin_str, 100, 0, 1);
      hists.addHist("score1_gg"+spin_str, 100, 0, 1);
      hists.addHist("score1_rest"+spin_str, 100, 0, 1);
      hists.addHist("score1_unmatched"+spin_str, 100, 0, 1);

      hists.addHist("score2_qq"+spin_str, 100, 0, 1);
      hists.addHist("score2_gg"+spin_str, 100, 0, 1);
      hists.addHist("score2_rest"+spin_str, 100, 0, 1);
      hists.addHist("score2_unmatched"+spin_str, 100, 0, 1);

      hists.addHist("score3_qq"+spin_str, 100, 0, 1);
      hists.addHist("score3_gg"+spin_str, 100, 0, 1);
      hists.addHist("score3_rest"+spin_str, 100, 0, 1);
      hists.addHist("score3_unmatched"+spin_str, 100, 0, 1);
    }
    
  }
  void analyze() override {
    // bool isqq = events->score > 0.9 && (events->type == 0);
    // bool isgg = events->score < 0.1 && (events->type == 0);
    // isqq = events->score > 0.8 && (events->type == 0);
    // isgg = events->score < 0.2 && (events->type == 0);

    // double score1 = events->score1/(events->score1+events->score0);
    // double score2 =events->score2/(events->score2+events->score0);
    double likelihoods[4] = {events->score0, events->score1, events->score2, events->score3};
    //double priors[4] = {0.02, 0.03, 0.15, 0.8};
    double priors[4] = {0.004, 0.09, 0.004, 0.86};
    //double priors[4] = {1, 1, 1, 1};

    //double priors[4] = {1,8, 1,8};
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

    // if(events->score1>events->score0 && events->score1>events->score2  && events->score1>events->score3 )
    //   score1 = events->score1/(events->score1+events->score3);
    // if(events->score2>events->score0 && events->score2>events->score1  && events->score2>events->score3 )
    //    score2 = events->score2/(events->score0+events->score1+events->score2+events->score3);;
    // bool isqq = score2>= 0.5 && events->kt>4;    
    // bool isgg = score1>= 0.5 && events->kt>4; 
    double score2_weight[4] = {1,1,1,1};
    score2 = events->score2*score2_weight[2]/(events->score0*score2_weight[0]+events->score1*score2_weight[1]+events->score2*score2_weight[2]+events->score3*score2_weight[3]);
    double score1_weight[4] = {100,1,1,100};
    score1 = events->score1*score1_weight[1]*10/(events->score0*score1_weight[0]+events->score1*score1_weight[1]+events->score2*score1_weight[2]+events->score3*score1_weight[3]);
    
    bool isqq =  score2 > 0.5 ;
    bool isgg =  score1 > 0.4 ;   
    
    bool z1cut01 = events->z1 > 0.0 && events->z1 < 0.1;
    bool z1cut12 = events->z1 > 0.1 && events->z1 < 0.2;
    bool z1cut23 = events->z1 > 0.2 && events->z1 < 0.3;
    bool z1cut34 = events->z1 > 0.3 && events->z1 < 0.4;
    bool z1cut45 = events->z1 > 0.4 && events->z1 < 0.5;

    bool z2cut01 = events->z2 > 0.0 && events->z2 < 0.1;
    bool z2cut12 = events->z2 > 0.1 && events->z2 < 0.2;
    bool z2cut23 = events->z2 > 0.2 && events->z2 < 0.3;
    bool z2cut34 = events->z2 > 0.3 && events->z2 < 0.4;
    bool z2cut45 = events->z2 > 0.4 && events->z2 < 0.5;
    // bool isgg =  events->score1>= 0.9  ;   
    // bool isqq =  events->score2>= 0.1   ;   
    // bool isgg =  events->score0>= 0.95 ;   
    // bool isqq =  events->score0>= 0.96  ;   
    // bool isgg = score1>= 0.7 && events->validate!=0;  

    // bool isqq = events->type == 2 && events->kt>4;  
    // bool isgg = events->type == 1; 

    bool isrest = !(isqq || isgg);
    double phi = events->Phi;
    for (auto cut_str : cut_strs) {
      double weight=1;
      if(cut_str=="_z1cut01"&&!z1cut12) weight=0;
      if(cut_str=="_z1cut12"&&!z1cut12) weight=0;
      if(cut_str=="_z1cut23"&&!z1cut23) weight=0;
      if(cut_str=="_z1cut34"&&!z1cut34) weight=0;
      if(cut_str=="_z1cut45"&&!z1cut45) weight=0;
      if(cut_str=="_z2cut01"&&!z2cut12) weight=0;
      if(cut_str=="_z2cut12"&&!z2cut12) weight=0;
      if(cut_str=="_z2cut23"&&!z2cut23) weight=0;
      if(cut_str=="_z2cut34"&&!z2cut34) weight=0;
      if(cut_str=="_z2cut45"&&!z2cut45) weight=0;
      if (events->spin == 1) {
        if (isqq) {
          hists["phi_qq_spinon"+cut_str]->Fill(phi,weight);
          if (events->type == 0 && events->match >= 0)
            hists["phi_qq_rest_spinon"+cut_str]->Fill(phi,weight);
          if (events->type == 0 && events->match < 0)
            hists["phi_qq_unmatched_spinon"+cut_str]->Fill(phi,weight);
          if (events->type == 1)
            hists["phi_qq_gg_spinon"+cut_str]->Fill(phi,weight);
          if (events->type == 2)
            hists["phi_qq_qq_spinon"+cut_str]->Fill(phi,weight);
        } else if (isgg) {
          hists["phi_gg_spinon"+cut_str]->Fill(phi,weight);
          if (events->type == 0 && events->match >= 0)
            hists["phi_gg_rest_spinon"+cut_str]->Fill(phi,weight);
          if (events->type == 0 && events->match < 0)
            hists["phi_gg_unmatched_spinon"+cut_str]->Fill(phi,weight);
          if (events->type == 1)
            hists["phi_gg_gg_spinon"+cut_str]->Fill(phi,weight);
          if (events->type == 2)
            hists["phi_gg_qq_spinon"+cut_str]->Fill(phi,weight);
        } else if (isrest) {
          if (events->match >= 0)
            hists["phi_rest_spinon"+cut_str]->Fill(phi,weight);
          else
            hists["phi_unmatched_spinon"+cut_str]->Fill(phi,weight);
        }
        hists["phi_full_spinon"+cut_str]->Fill(phi,weight);
      } else if (events->spin == 0) {
        if (isqq) {
          hists["phi_qq_spinoff"+cut_str]->Fill(phi,weight);
          if (events->type == 0 && events->match >= 0)
            hists["phi_qq_rest_spinoff"+cut_str]->Fill(phi,weight);
          if (events->type == 0 && events->match < 0)
            hists["phi_qq_unmatched_spinoff"+cut_str]->Fill(phi,weight);
          if (events->type == 1)
            hists["phi_qq_gg_spinoff"+cut_str]->Fill(phi,weight);
          if (events->type == 2)
            hists["phi_qq_qq_spinoff"+cut_str]->Fill(phi,weight);
        } else if (isgg) {
          hists["phi_gg_spinoff"+cut_str]->Fill(phi,weight);
          if (events->type == 0 && events->match >= 0)
            hists["phi_gg_rest_spinoff"+cut_str]->Fill(phi,weight);
          if (events->type == 0 && events->match < 0)
            hists["phi_gg_unmatched_spinoff"+cut_str]->Fill(phi,weight);
          if (events->type == 1)
            hists["phi_gg_gg_spinoff"+cut_str]->Fill(phi,weight);
          if (events->type == 2)
            hists["phi_gg_qq_spinoff"+cut_str]->Fill(phi,weight);
        } else if (isrest) {
          if (events->match >= 0)
            hists["phi_rest_spinoff"+cut_str]->Fill(phi,weight);
          else
            hists["phi_unmatched_spinoff"+cut_str]->Fill(phi,weight);
        }
        hists["phi_full_spinoff"+cut_str]->Fill(phi,weight);
      }
    }
    for(auto spin_str:spin_strs){
      bool isspin = true;
      bool isqq = events->type == 2;
      bool isgg = events->type == 1;
      bool isrest = events->type ==0 && events->match>=0;
      bool isunmatched = events->type ==0 && events->match<0;
      double score0 = events->score0;
      double score3 = events->score3;
      if(spin_str=="_spinon") isspin=events->spin==1;
      if(spin_str=="_spinoff") isspin=events->spin==0;
      hists["score0_qq"+spin_str]->Fill(score0,isqq*isspin);
      hists["score0_gg"+spin_str]->Fill(score0,isgg*isspin);
      hists["score0_rest"+spin_str]->Fill(score0,isrest*isspin);
      hists["score0_unmatched"+spin_str]->Fill(score0,isunmatched*isspin);
      
      hists["score1_qq"+spin_str]->Fill(score1,isqq*isspin);
      hists["score1_gg"+spin_str]->Fill(score1,isgg*isspin);
      hists["score1_rest"+spin_str]->Fill(score1,isrest*isspin);
      hists["score1_unmatched"+spin_str]->Fill(score1,isunmatched*isspin);

      hists["score2_qq"+spin_str]->Fill(score2,isqq*isspin);
      hists["score2_gg"+spin_str]->Fill(score2,isgg*isspin);
      hists["score2_rest"+spin_str]->Fill(score2,isrest*isspin);
      hists["score2_unmatched"+spin_str]->Fill(score2,isunmatched*isspin);

      hists["score3_qq"+spin_str]->Fill(score3,isqq*isspin);
      hists["score3_gg"+spin_str]->Fill(score3,isgg*isspin);
      hists["score3_rest"+spin_str]->Fill(score3,isrest*isspin);
      hists["score3_unmatched"+spin_str]->Fill(score3,isunmatched*isspin);
    }
    
  }
};
// void Draw_plots_mini2(){
int main() {
  TH1D *accumulative(TH1D * hist, int direct = 1,bool normalize=true);
  EventsAnalyzer analyzerspinon;
  //analyzerspinon.run_frac_rand(0.1);
  analyzerspinon.run_frac(1);
  // analyzerspinon.run(10000);
  

  analyzerspinon.finalize("plots/ML_plot.root");

  vector<string> types = {"qq", "gg", "rest", "unmatched", "full","qq_qq","qq_gg","qq_unmatched","qq_rest","gg_qq","gg_gg","gg_unmatched","gg_rest"};
  vector<string> cut_strs=analyzerspinon.cut_strs;
    for(auto cut_str:cut_strs){
  for (auto &type : types) {
    TH1D *hist_spinon = (TH1D *)analyzerspinon.hists["phi_" + type + "_spinon"+cut_str];
    TH1D *hist_spinoff =
        (TH1D *)analyzerspinon.hists["phi_" + type + "_spinoff"+cut_str];
    hist_spinon->SetTitle("spin on");
    hist_spinoff->SetTitle("spin off");
    vector<TH1D *> hists_draw = {hist_spinoff, hist_spinon};
    Draw_Template::SymmetryTwoPads(hists_draw, "ML" + type + "_phi_onoff"+cut_str+".pdf",
                                   "plane type: " + type);
  }
    }
  vector<string> spins = {"", "_spinon", "_spinoff"};
  for (int i = 0; i <= 3; i++) {
    for (auto &spin : spins) {
      string score = "score"+std::to_string(i);
      TH1D *score_qq = (TH1D *)analyzerspinon.hists[score+"_qq" + spin];
      TH1D *score_gg = (TH1D *)analyzerspinon.hists[score+"_gg" + spin];
      TH1D *score_rest = (TH1D *)analyzerspinon.hists[score+"_rest" + spin];
      TH1D *score_unmatched = (TH1D *)analyzerspinon.hists[score+"_unmatched" + spin];
      Draw_Template::NorOnePad({score_qq, score_gg, score_rest, score_unmatched},
                               score+"" + spin + ".pdf");
      TH1D *score_qq_accuforward = accumulative(score_qq, 1);
      TH1D *score_gg_accuforward = accumulative(score_gg, 1);
      TH1D *score_rest_accuforward = accumulative(score_rest, 1);
      TH1D *score_unmatched_accuforward = accumulative(score_unmatched, 1);
      Draw_Template::TwoPads(
          {score_gg_accuforward, score_qq_accuforward, score_rest_accuforward, score_unmatched_accuforward},
          score+"_accuforward" + spin + ".pdf");
      TH1D *score_qq_accubackward = accumulative(score_qq, -1);
      TH1D *score_gg_accubackward = accumulative(score_gg, -1);
      TH1D *score_rest_accubackward = accumulative(score_rest, -1);
      TH1D *score_unmatched_accubackward = accumulative(score_unmatched, -1);
      Draw_Template::TwoPads({score_qq_accubackward, score_gg_accubackward,
                              score_rest_accubackward,score_unmatched_accubackward},
                             score+"_accubackward" + spin + ".pdf");
    }
  }
  for (int i = 0; i <= 3; i++) {
    for (auto &spin : spins) {
      string score = "score"+std::to_string(i);
      TH1D *score_qq = (TH1D *)analyzerspinon.hists[score+"_qq" + spin];
      TH1D *score_gg = (TH1D *)analyzerspinon.hists[score+"_gg" + spin];
      TH1D *score_rest = (TH1D *)analyzerspinon.hists[score+"_rest" + spin];
      TH1D *score_unmatched = (TH1D *)analyzerspinon.hists[score+"_unmatched" + spin];

      Draw_Template::NorOnePad_frac({score_qq, score_gg, score_rest, score_unmatched},
                               score+"" + spin + "_frac.pdf");
      TH1D *score_qq_accuforward = accumulative(score_qq, -1,false);
      TH1D *score_gg_accuforward = accumulative(score_gg, -1,false);
      TH1D *score_rest_accuforward = accumulative(score_rest, -1,false);
      TH1D *score_unmatched_accuforward = accumulative(score_unmatched, -1,false);
      Draw_Template::NorOnePad_frac(
          {score_qq_accuforward,score_gg_accuforward,  score_rest_accuforward,  score_unmatched_accuforward},
          score+"_accubackward" + spin + "_frac.pdf");
      
    }
  }

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
