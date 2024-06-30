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
void draw_pt(){
    TChain * tchain = new TChain();

    tchain->Add("/extdisk/zlin/Machine_learning/RecoPlanes/CMS_herwig_Pt-15to7000UL18/Chunk*.root/DataInfo");
    Hists hists;
    hists.addHist("JetPt",1500,0,1500);
    hists.addHist("Jet2Pt",1500,0,1500);

    tchain->Draw("Genjpt>>JetPt");
    tchain->Draw("Genpt2>>Jet2Pt","(Genjpt>=150)*(Genjpt<250)");

    hists.Write("output_200_250.root");
}
