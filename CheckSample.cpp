#include "include/DataInfo.h"
#include "TFile.h"
#include "TH1D.h"
#include "TTree.h"
#include "TLorentzVector.h"
#include "include/Hists.h"
#include "include/Process_bar.h"
void CheckSample(){
    TFile *f = new TFile("test/validation_data_CA_lundplane_parton10Mz00pt200IFN.root");
    TTree *t = (TTree *)f->Get("DataInfo");
    DataInfo events(t);
    Hists Hists;
    Hists.addHist("hard_deltaR",100,0,1);
    Hists.addHist("soft_deltaR",100,0,1);
    Hists.addHist("hard_deltaRRatio",1000,0,10);
    Hists.addHist("soft_deltaRRatio",1000,0,10);
    Hists.addHist("hard_deltaPt",1000,-500,500);
    Hists.addHist("soft_deltaPt",1000,-500,500);

    Hists.addHist("hard_delta",100,0,1,100,-500,500);
    Hists.addHist("soft_delta",100,0,1,100,-500,500);
    int entries = t->GetEntries();
    ProcessBar ProcessBar(entries);
    for(int i=0;i<t->GetEntries();i++){
        ProcessBar.show2(i);
        events.GetEntry(i);
        TLorentzVector hard_parton,hard_hadron;
        TLorentzVector soft_parton,soft_hadron;
        hard_parton.SetPtEtaPhiE(events.pt3_Parton,events.eta3_Parton,events.phi3_Parton,events.e3_Parton);
        hard_hadron.SetPtEtaPhiE(events.pt3_Hadron,events.eta3_Hadron,events.phi3_Hadron,events.e3_Hadron);
        soft_parton.SetPtEtaPhiE(events.pt4_Parton,events.eta4_Parton,events.phi4_Parton,events.e4_Parton);
        soft_hadron.SetPtEtaPhiE(events.pt4_Hadron,events.eta4_Hadron,events.phi4_Hadron,events.e4_Hadron);

        Hists["hard_deltaR"]->Fill(hard_parton.DeltaR(hard_hadron));
        Hists["soft_deltaR"]->Fill(soft_parton.DeltaR(soft_hadron));
        Hists["hard_deltaRRatio"]->Fill(hard_parton.DeltaR(hard_hadron)*1.0/(hard_hadron.DeltaR(soft_hadron)));
        Hists["soft_deltaRRatio"]->Fill(soft_parton.DeltaR(soft_hadron)*1.0/(hard_hadron.DeltaR(soft_hadron)));

        Hists["hard_deltaPt"]->Fill(hard_parton.Pt()-hard_hadron.Pt());
        Hists["soft_deltaPt"]->Fill(soft_parton.Pt()-soft_hadron.Pt());

        Hists["hard_delta"]->Fill(hard_parton.DeltaR(hard_hadron),hard_parton.Pt()-hard_hadron.Pt());
        Hists["soft_delta"]->Fill(soft_parton.DeltaR(soft_hadron),soft_parton.Pt()-soft_hadron.Pt());
    }
    Hists.Write("Out.root");
}