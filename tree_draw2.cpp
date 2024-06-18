//gInterpreter->AddIncludePath("/home/zlin/.local/include");
#include "TFile.h"
#include "TH1D.h"
#include "TTree.h"
#include "TChain.h"
#include "TLorentzVector.h"
#include "include/Hists.h"
#include "include/Process_bar.h"
#include "include/Draw_Template.h"
#include <getopt.h>
#include "TDirectory.h"
int main(){
    TChain * t_on = new TChain();
    TChain * t_off = new TChain();
    t_on->Add("test/features/Features_Spinon*.root/DataInfo");
    t_off->Add("test/features/Features_Spinoff*.root/DataInfo");
    cout<<t_on->GetEntries()<<endl;
    Hists hists;
    hists.addHist("phi_on",100,0,M_PI);
    hists.addHist("phi_off",100,0,M_PI);

    t_on->Draw("Phi>>phi_on","type==2","");
    t_off->Draw("Phi>>phi_off","type==2","");

    auto phi_on=(TH1D *)gDirectory->Get("phi_on");
    auto phi_off=(TH1D *)gDirectory->Get("phi_off");

    cout<<phi_on->Integral()<<endl;
    cout<<phi_off->Integral()<<endl;
    Draw_Template::SymmetryTwoPads({phi_off,phi_on},"tree_draw.pdf");
}