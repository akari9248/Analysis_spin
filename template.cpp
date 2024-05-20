//gInterpreter->AddIncludePath("/home/zlin/.local/include");
#include "include/miniDataInfo.h"
#include "TFile.h"
#include "TH1D.h"
#include "TTree.h"
#include "TLorentzVector.h"
#include "include/Hists.h"
#include "include/Process_bar.h"
#include "include/SampleAnalyzer.h"
#include "include/Draw_Template.h"
#include "include/JetBranch.h"
class EventsAnalyzer : public SampleAnalyzer<miniDataInfo> {
public:
    void initialize() override {
        t->Add("test.root/DataInfo");
        hists.addHist("phi",100,0,TMath::Pi());
    }
    void analyze() override {
        TLorentzVector p1,p2,p3;
        p1.SetPtEtaPhiE(events->pt1,events->eta1,events->phi1,events->e1);
        p2.SetPtEtaPhiE(events->pt2,events->eta2,events->phi2,events->e2);
        p3.SetPtEtaPhiE(events->pt3,events->eta3,events->phi3,events->e3);
        JetBranch::PlaneVariables plane1,plane2;
        plane1.harder_vect = p1;
        plane1.softer_vect = p2+p3;
        plane2.harder_vect = p2;
        plane2.softer_vect = p3;
        plane1.GetPlaneVector();
        plane2.GetPlaneVector();
        double phi=JetBranch::DeltaPhi(plane1,plane2);
        phi = events->phi;

        hists["phi"]->Fill(phi);
    }
};
// void Draw_plots_mini2(){
int main(){
    EventsAnalyzer analyzerspinon();
    analyzerspinon.run();
    analyzerspinon.finalize("test_out.root");
    return 0;
}