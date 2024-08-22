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
void JetPt(){
    TChain * tchain = new TChain();
    tchain->Add("/storage/shuangyuan/code/analysis_spin/dataset/QCD_Pt-15to7000_Flat_herwig7_RunIISummer20UL18/Chunk*.root/jetInfos/JetsAndDaughters");
    Hists hists;
    hists.addHist("JetPt",700,0,7000);
    hists.addHist("JetPtcut",700,0,7000);
    double GeneratorWeight;
    vector<double> *GenJetPt = new vector<double>;
    tchain->SetBranchAddress("GenJetPt",&GenJetPt);
    tchain->SetBranchAddress("GeneratorWeight",&GeneratorWeight);
    Hists weightcut("../tabel/OverWeightedEventRemoval/GeneratorWeightcut.root");
    ProcessBar processBar(tchain->GetEntries());
    for(int i=0;i<tchain->GetEntries();i++){
        processBar.show2(i);
        tchain->GetEntry(i);
        if(GenJetPt->size()>0){
            hists["JetPt"]->Fill(GenJetPt->at(0),GeneratorWeight);
             if(GeneratorWeight>weightcut["GeneratorWeightCutSmoothHist"]->GetBinContent(weightcut["GeneratorWeightCutSmoothHist"]->FindBin(GenJetPt->at(0)))) {
                continue;
             }
             hists["JetPtcut"]->Fill(GenJetPt->at(0),GeneratorWeight);
        }
    }
    hists.Write("pt.root");
}

