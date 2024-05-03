#include "include/AdvancedDataInfo.h"
#include "TFile.h"
#include "TH1D.h"
#include "TTree.h"
#include "TLorentzVector.h"
#include "include/Hists.h"
#include "include/Process_bar.h"
#include "include/SampleAnalyzer.h"
#include "include/Draw_Template.h"
#include "TString.h"
class EventsAnalyzer : public SampleAnalyzer<AdvancedDataInfo> {
public:
    void initialize() override {
        for(int i=0;i<1;i++)
            t->Add(TString::Format("test/validation_data_CA_lundplane_partonz00pt200IFN_matchsecond/Chunk%d.root/DataInfo",i));

        hists.addHist("Spinon_parton_qq",100,0,TMath::Pi());
        hists.addHist("Spinon_parton_gg",100,0,TMath::Pi());
        hists.addHist("Spinon_parton_rest",100,0,TMath::Pi());

        hists.addHist("Spinon_hadron_qq",100,0,TMath::Pi());
        hists.addHist("Spinon_hadron_gg",100,0,TMath::Pi());
        hists.addHist("Spinon_hadron_rest",100,0,TMath::Pi());

        hists.addHist("Spinoff_parton_qq",100,0,TMath::Pi());
        hists.addHist("Spinoff_parton_gg",100,0,TMath::Pi());
        hists.addHist("Spinoff_parton_rest",100,0,TMath::Pi());

        hists.addHist("Spinoff_hadron_qq",100,0,TMath::Pi());
        hists.addHist("Spinoff_hadron_gg",100,0,TMath::Pi());
        hists.addHist("Spinoff_hadron_rest",100,0,TMath::Pi());
        /*                  KT CUT                          */
        hists.addHist("Spinon_parton_qq_ktcut",100,0,TMath::Pi());
        hists.addHist("Spinon_parton_gg_ktcut",100,0,TMath::Pi());
        hists.addHist("Spinon_parton_rest_ktcut",100,0,TMath::Pi());

        hists.addHist("Spinon_hadron_qq_ktcut",100,0,TMath::Pi());
        hists.addHist("Spinon_hadron_gg_ktcut",100,0,TMath::Pi());
        hists.addHist("Spinon_hadron_rest_ktcut",100,0,TMath::Pi());

        hists.addHist("Spinoff_parton_qq_ktcut",100,0,TMath::Pi());
        hists.addHist("Spinoff_parton_gg_ktcut",100,0,TMath::Pi());
        hists.addHist("Spinoff_parton_rest_ktcut",100,0,TMath::Pi());

        hists.addHist("Spinoff_hadron_qq_ktcut",100,0,TMath::Pi());
        hists.addHist("Spinoff_hadron_gg_ktcut",100,0,TMath::Pi());
        hists.addHist("Spinoff_hadron_rest_ktcut",100,0,TMath::Pi());
        /*                  KT CUT  + Z CUT                        */
        hists.addHist("Spinon_parton_qq_ktcut_zcut",100,0,TMath::Pi());
        hists.addHist("Spinon_parton_gg_ktcut_zcut",100,0,TMath::Pi());
        hists.addHist("Spinon_parton_rest_ktcut_zcut",100,0,TMath::Pi());

        hists.addHist("Spinon_hadron_qq_ktcut_zcut",100,0,TMath::Pi());
        hists.addHist("Spinon_hadron_gg_ktcut_zcut",100,0,TMath::Pi());
        hists.addHist("Spinon_hadron_rest_ktcut_zcut",100,0,TMath::Pi());

        hists.addHist("Spinoff_parton_qq_ktcut_zcut",100,0,TMath::Pi());
        hists.addHist("Spinoff_parton_gg_ktcut_zcut",100,0,TMath::Pi());
        hists.addHist("Spinoff_parton_rest_ktcut_zcut",100,0,TMath::Pi());

        hists.addHist("Spinoff_hadron_qq_ktcut_zcut",100,0,TMath::Pi());
        hists.addHist("Spinoff_hadron_gg_ktcut_zcut",100,0,TMath::Pi());
        hists.addHist("Spinoff_hadron_rest_ktcut_zcut",100,0,TMath::Pi());

    }
    void analyze() override {
        bool spinon = events->spin==1;
        bool spinoff = events->spin==0;
        for (int i = 0; i < events->isqq_Parton->size(); i++)
        {   
            
            bool isqq_Parton = events->isqq_Parton->at(i);
            bool isgg_Parton = events->isgg_Parton->at(i);
            bool isrest_Parton = (events->isgg_Parton->at(i) + events->isqq_Parton->at(i)) == 0;
            bool ktcut_Parton = events->kt2_Parton->at(i) > 4;
            bool zcutktcut_Parton = ktcut_Parton * (events->z1_Parton->at(i) > 0.2) * (events->z2_Parton->at(i) > 0.4);
            double phi_Parton = events->phi_Parton->at(i);
            

            hists["Spinon_parton_qq"]->Fill(phi_Parton, spinon * isqq_Parton);
            hists["Spinon_parton_gg"]->Fill(phi_Parton, spinon * isgg_Parton);
            hists["Spinon_parton_rest"]->Fill(phi_Parton, spinon * isrest_Parton);
            hists["Spinon_parton_qq_ktcut"]->Fill(phi_Parton, spinon * isqq_Parton * ktcut_Parton);
            hists["Spinon_parton_gg_ktcut"]->Fill(phi_Parton, spinon * isgg_Parton * ktcut_Parton);
            hists["Spinon_parton_rest_ktcut"]->Fill(phi_Parton, spinon * isrest_Parton * ktcut_Parton);
            hists["Spinon_parton_qq_ktcut_zcut"]->Fill(phi_Parton, spinon * isqq_Parton * zcutktcut_Parton);
            hists["Spinon_parton_gg_ktcut_zcut"]->Fill(phi_Parton, spinon * isgg_Parton * zcutktcut_Parton);
            hists["Spinon_parton_rest_ktcut_zcut"]->Fill(phi_Parton, spinon * isrest_Parton * zcutktcut_Parton);
        
            hists["Spinoff_parton_qq"]->Fill(phi_Parton, spinoff * isqq_Parton);
            hists["Spinoff_parton_gg"]->Fill(phi_Parton, spinoff * isgg_Parton);
            hists["Spinoff_parton_rest"]->Fill(phi_Parton, spinoff * isrest_Parton);
            hists["Spinoff_parton_qq_ktcut"]->Fill(phi_Parton, spinoff * isqq_Parton * ktcut_Parton);
            hists["Spinoff_parton_gg_ktcut"]->Fill(phi_Parton, spinoff * isgg_Parton * ktcut_Parton);
            hists["Spinoff_parton_rest_ktcut"]->Fill(phi_Parton, spinoff * isrest_Parton * ktcut_Parton);
            hists["Spinoff_parton_qq_ktcut_zcut"]->Fill(phi_Parton, spinoff * isqq_Parton * zcutktcut_Parton);
            hists["Spinoff_parton_gg_ktcut_zcut"]->Fill(phi_Parton, spinoff * isgg_Parton * zcutktcut_Parton);
            hists["Spinoff_parton_rest_ktcut_zcut"]->Fill(phi_Parton, spinoff * isrest_Parton * zcutktcut_Parton);
        }
        for (int i = 0; i < events->isqq_Hadron->size(); i++)
        {
        bool isqq_Hadron = events->isqq_Hadron->at(i);
        bool isgg_Hadron = events->isgg_Hadron->at(i);
        bool isrest_Hadron = (events->isgg_Hadron->at(i) + events->isqq_Hadron->at(i))==0;
        bool ktcut_Hadron = events->kt2_Hadron->at(i) > 4;
        bool zcutktcut_Hadron = ktcut_Hadron * (events->z1_Hadron->at(i)>0.2)*(events->z2_Hadron->at(i)>0.4);
        double phi_Hadron = events->phi_Hadron->at(i);

        hists["Spinon_hadron_qq"]->Fill(phi_Hadron, spinon * isqq_Hadron);
        hists["Spinon_hadron_gg"]->Fill(phi_Hadron, spinon * isgg_Hadron);
        hists["Spinon_hadron_rest"]->Fill(phi_Hadron, spinon * isrest_Hadron);
        hists["Spinon_hadron_qq_ktcut"]->Fill(phi_Hadron, spinon * isqq_Hadron * ktcut_Hadron);
        hists["Spinon_hadron_gg_ktcut"]->Fill(phi_Hadron, spinon * isgg_Hadron * ktcut_Hadron);
        hists["Spinon_hadron_rest_ktcut"]->Fill(phi_Hadron, spinon * isrest_Hadron * ktcut_Hadron);
        hists["Spinon_hadron_qq_ktcut_zcut"]->Fill(phi_Hadron, spinon * isqq_Hadron * zcutktcut_Hadron);
        hists["Spinon_hadron_gg_ktcut_zcut"]->Fill(phi_Hadron, spinon * isgg_Hadron * zcutktcut_Hadron);
        hists["Spinon_hadron_rest_ktcut_zcut"]->Fill(phi_Hadron, spinon * isrest_Hadron * zcutktcut_Hadron);

        
        hists["Spinoff_hadron_qq"]->Fill(phi_Hadron, spinoff * isqq_Hadron);
        hists["Spinoff_hadron_gg"]->Fill(phi_Hadron, spinoff * isgg_Hadron);
        hists["Spinoff_hadron_rest"]->Fill(phi_Hadron, spinoff * isrest_Hadron);
        hists["Spinoff_hadron_qq_ktcut"]->Fill(phi_Hadron, spinoff * isqq_Hadron * ktcut_Hadron);
        hists["Spinoff_hadron_gg_ktcut"]->Fill(phi_Hadron, spinoff * isgg_Hadron * ktcut_Hadron);
        hists["Spinoff_hadron_rest_ktcut"]->Fill(phi_Hadron, spinoff * isrest_Hadron * ktcut_Hadron);
        hists["Spinoff_hadron_qq_ktcut_zcut"]->Fill(phi_Hadron, spinoff * isqq_Hadron * zcutktcut_Hadron);
        hists["Spinoff_hadron_gg_ktcut_zcut"]->Fill(phi_Hadron, spinoff * isgg_Hadron * zcutktcut_Hadron);
        hists["Spinoff_hadron_rest_ktcut_zcut"]->Fill(phi_Hadron, spinoff * isrest_Hadron * zcutktcut_Hadron);

        }
    }
};

int Draw_plots_Advanced(){
    EventsAnalyzer analyzer;
    analyzer.run();
    analyzer.finalize("test.root");

    std::vector<std::string> partonTypes = {"qq", "gg", "rest"};
    std::vector<std::string> partonStates = {"parton", "hadron"};
    std::vector<std::string> cuts = {"", "_ktcut", "_ktcut_zcut"};

    for (const auto &partonType : partonTypes) {
      for (const auto &partonState : partonStates) {
        for (const auto &cut : cuts) {
          std::string histNameOn =
              "Spinon_" + partonState + "_" + partonType + cut;
          std::string histNameOff =
              "Spinoff_" + partonState + "_" + partonType + cut;
          TH1D *histon = (TH1D *)analyzer.hists[histNameOn];
          TH1D *histoff = (TH1D *)analyzer.hists[histNameOff];
          histon->SetTitle("spin on");
          histoff->SetTitle("spin off");
          vector<TH1D *> hists_draw = {histoff, histon};
          Draw_Template::SymmetryTwoPads(hists_draw,
                                         "NetFlavour/"+partonState + "_" + partonType + cut+".pdf",partonState + " " + partonType +" "+ cut);
        }
      }
    }
    return 0;
}