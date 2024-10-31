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
void pileup_reweighting_data(){
    Hists hist("../table/Pileup_reweighting/pileup_weight.root");
    Hists hist_datadn("../table/Pileup_reweighting/pileupHistogram-Cert_Collisions2022_355100_362760_GoldenJson-13p6TeV-66000ub-99bins.root");
    Hists hist_data("../table/Pileup_reweighting/pileupHistogram-Cert_Collisions2022_355100_362760_GoldenJson-13p6TeV-69200ub-99bins.root");
    Hists hist_dataup("../table/Pileup_reweighting/pileupHistogram-Cert_Collisions2022_355100_362760_GoldenJson-13p6TeV-72400ub-99bins.root");

    Hists hist_out;
    hist_out.addHist("Nominal",99,0,99);
    hist_out.addHist("data",99,0,99);
    hist_out.addHist("dataup",99,0,99);
    hist_out.addHist("datadn",99,0,99);
    hist_out.addHist("NominalWeight",99,0,99);
    hist_out.addHist("UpWeight",99,0,99);
    hist_out.addHist("DnWeight",99,0,99);

    for(int i=0;i<=100;i++){
        hist_out["Nominal"]->SetBinContent(i,hist["NumberTruePileup_herwig"]->GetBinContent(i));
        hist_out["datadn"]->SetBinContent(i,hist_datadn["pileup"]->GetBinContent(i));
        hist_out["dataup"]->SetBinContent(i,hist_dataup["pileup"]->GetBinContent(i));
        hist_out["data"]->SetBinContent(i,hist_data["pileup"]->GetBinContent(i));
    }
    TH1D *NominalWeight = (TH1D *)hist_out["data"]->Clone("NominalWeight");
    NominalWeight->SetTitle("NominalWeight");
    hist_out.hists["NominalWeight"]  = NominalWeight;
    TH1D *UpWeight = (TH1D *)hist_out["dataup"]->Clone("UpWeight");
    UpWeight->SetTitle("UpWeight");
    hist_out.hists["UpWeight"]  = UpWeight;
    TH1D *DnWeight = (TH1D *)hist_out["datadn"]->Clone("DnWeight");
    DnWeight->SetTitle("DnWeight");
    hist_out.hists["DnWeight"]  = DnWeight;


    TH1D *Nominal2 = (TH1D *)hist_out["Nominal"]->Clone("Nominal2");

    hist_out.hists["NominalWeight"]->Scale(1.0/hist_out.hists["NominalWeight"]->Integral());
    hist_out.hists["UpWeight"]->Scale(1.0/hist_out.hists["UpWeight"] ->Integral());
    hist_out.hists["DnWeight"]->Scale(1.0/hist_out.hists["DnWeight"]->Integral());
    Nominal2->Scale(1.0/Nominal2->Integral());

    hist_out.hists["NominalWeight"]->Divide(Nominal2);
    hist_out.hists["UpWeight"]->Divide(Nominal2);
    hist_out.hists["DnWeight"]->Divide(Nominal2);

    hist_out.Write("pileup_weight_herwig.root");
}

