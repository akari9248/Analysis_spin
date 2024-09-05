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
void TwoPads(vector<TH1D *> hists,TString filename,TString ExtraText="",vector<TString> legend_name={});
void pileup_reweighting(){
    TChain * tchain_herwig = new TChain();
     TChain * tchain_pythia = new TChain();
    tchain_herwig->Add("/storage/shuangyuan/code/analysis_spin/dataset/QCD_Pt-15to7000_Flat_herwig7_RunIISummer20UL18/Chunk*.root/jetInfos/JetsAndDaughters");
    tchain_pythia->Add("/extdisk/zlin/Machine_learning/test_datasets/QCD_Pt-15to7000_Flat_pythia8-Run3Summer22/Chunk*.root/JetsAndDaughters");
    Hists hists;
    hists.addHist("NumberTruePileup_herwig",100,0,100);
    hists.addHist("NumberTruePileup_pythia",100,0,100);
    tchain_herwig->Draw("NumberTruePileup>>NumberTruePileup_herwig");
    tchain_pythia->Draw("NumberTruePileup>>NumberTruePileup_pythia");
    TH1D *weight = (TH1D*)hists["NumberTruePileup_herwig"]->Clone("PileupReweight");
    weight->SetTitle("PileupReweight");
    TH1D *weight_temp = (TH1D*)hists["NumberTruePileup_pythia"]->Clone("PileupReweight_temp");
    weight->Scale(1.0/weight->Integral());
    weight_temp->Scale(1.0/weight_temp->Integral());
    weight->Divide(weight_temp);
    hists.hists["PileupReweight"] = weight;
    hists.Write("pileup_weight.root");
}

