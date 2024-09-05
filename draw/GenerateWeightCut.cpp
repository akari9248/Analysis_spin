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
void GenerateWeightCut(){
    TChain * tchain = new TChain();

    //tchain->Add("/storage/shuangyuan/code/analysis_spin/dataset/QCD_Pt-15to7000_Flat_herwig7_RunIISummer20UL18/Chunk*.root/jetInfos/JetsAndDaughters");
    tchain->Add("/extdisk/zlin/Machine_learning/test_datasets/QCD_Pt-15to7000_Flat_pythia8-Run3Summer22/Chunk*.root/JetsAndDaughters");
    Hists hists;
    hists.addHist("GeneratorWeight",700,0,7000,400, -30, 10);
    tchain->Draw("log(GeneratorWeight):GenJetPt[0]>>GeneratorWeight");
    hists.Write("GeneratorWeight_pythia8.root");
}

