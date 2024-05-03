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
    TString prefix="";
    TString type="";
    EventsAnalyzer(TString _prefix,TString _type){prefix=_prefix;type=_type;}
    void initialize() override {
        t->Add("/home/zlin/Public/"+type+prefix+".root/DataInfo");
        hists.addHist("phi_qq",100,0,TMath::Pi());
        hists.addHist("phi_gg",100,0,TMath::Pi());
        hists.addHist("phi_rest",100,0,TMath::Pi());
        hists.addHist("phi_full",100,0,TMath::Pi());
        cout<<t->GetEntries()<<endl;
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
        if(events->type==2){
            hists["phi_qq"]->Fill(phi);
        }
        else if(events->type==1){
            hists["phi_gg"]->Fill(phi);
        }else{
            hists["phi_rest"]->Fill(phi);
        }
        hists["phi_full"]->Fill(phi);
    }
};

int main(){
    
    string partontype="Parton";
    EventsAnalyzer analyzerspinon("spin_on",partontype);
    analyzerspinon.run();
    analyzerspinon.finalize("spin_on_"+partontype+"_3.root");
    EventsAnalyzer analyzerspinoff("spin_off",partontype);
    analyzerspinoff.run();
    analyzerspinoff.finalize("spin_off_"+partontype+"_3.root");
    vector<string> types={"qq","gg","rest","full"};
    for(const auto &type : types){
        string histname= "phi_"+type;
        TH1D *histon = (TH1D *)analyzerspinon.hists[histname];
        TH1D *histoff = (TH1D *)analyzerspinoff.hists[histname];
        histon->SetTitle("spin on");
        histoff->SetTitle("spin off");
        vector<TH1D *> hists_draw = {histoff, histon};
        Draw_Template::SymmetryTwoPads(hists_draw,partontype+type+"_3.pdf");
    }
    

    return 0;
}