#include "include/DataInfo.h"
#include "TFile.h"
#include "TH1D.h"
#include "TTree.h"
#include "TLorentzVector.h"
#include "include/Hists.h"
#include "include/Process_bar.h"
#include "include/SampleAnalyzer.h"
class EventsAnalyzer : public SampleAnalyzer<DataInfo> {
public:
    void initialize() override {
        t->Add("test/validation_data_CA_lundplane_parton10Mz00pt200IFN.root/DataInfo");
        hists.addHist("hard_deltaR",100,0,1);
        hists.addHist("soft_deltaR",100,0,1);
        hists.addHist("hard_deltaRRatio",1000,0,10);
        hists.addHist("soft_deltaRRatio",1000,0,10);
        hists.addHist("hard_deltaPt",1000,-500,500);
        hists.addHist("soft_deltaPt",1000,-500,500);
        hists.addHist("hard_delta",100,0,1,100,-500,500);
        hists.addHist("soft_delta",100,0,1,100,-500,500);
    }
    void analyze() override {
        TLorentzVector hard_parton,hard_hadron;
        TLorentzVector soft_parton,soft_hadron;

        hard_parton.SetPtEtaPhiE(events->pt3_Parton,events->eta3_Parton,events->phi3_Parton,events->e3_Parton);
        hard_hadron.SetPtEtaPhiE(events->pt3_Hadron,events->eta3_Hadron,events->phi3_Hadron,events->e3_Hadron);
        soft_parton.SetPtEtaPhiE(events->pt4_Parton,events->eta4_Parton,events->phi4_Parton,events->e4_Parton);
        soft_hadron.SetPtEtaPhiE(events->pt4_Hadron,events->eta4_Hadron,events->phi4_Hadron,events->e4_Hadron);
        hists["hard_deltaR"]->Fill(hard_parton.DeltaR(hard_hadron));
        hists["soft_deltaR"]->Fill(soft_parton.DeltaR(soft_hadron));
        hists["hard_deltaRRatio"]->Fill(hard_parton.DeltaR(hard_hadron)*1.0/(hard_hadron.DeltaR(soft_hadron)));
        hists["soft_deltaRRatio"]->Fill(soft_parton.DeltaR(soft_hadron)*1.0/(hard_hadron.DeltaR(soft_hadron)));
        hists["hard_deltaPt"]->Fill(hard_parton.Pt()-hard_hadron.Pt());
        hists["soft_deltaPt"]->Fill(soft_parton.Pt()-soft_hadron.Pt());
        hists["hard_delta"]->Fill(hard_parton.DeltaR(hard_hadron),hard_parton.Pt()-hard_hadron.Pt());
        hists["soft_delta"]->Fill(soft_parton.DeltaR(soft_hadron),soft_parton.Pt()-soft_hadron.Pt());
    }
};

int main0(){
    EventsAnalyzer analyzer;
    analyzer.run();
    analyzer.finalize("test.root");
    return 0;
}