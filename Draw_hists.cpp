#include "include/DataInfo.h"
#include "TFile.h"
#include "TH1D.h"
#include "TTree.h"
#include "TLorentzVector.h"
#include "include/Hists.h"
#include "include/Process_bar.h"
#include "include/SampleAnalyzer.h"
#include "include/Draw_Template.h"

void Draw_hists(){
    Hists hists;
    hists.Load("test.root");
    std::vector<std::string> spinTypes = {"Spinon", "Spinoff"};
    std::vector<std::string> partonTypes = {"qq", "gg", "rest"};
    std::vector<std::string> partonStates = {"parton", "hadron"};
    std::vector<std::string> cuts = {"", "_ktcut", "_ktcut_zcut"};

    for (const auto &spinType : spinTypes) {
      for (const auto &cut : cuts) {
        for (const auto &partonState : partonStates) {
          double sum=0;
          std::string histNameqq = spinType + "_" + partonState + "_qq" + cut;
          std::string histNamegg = spinType + "_" + partonState + "_gg" + cut;
          std::string histNamerest =
              spinType + "_" + partonState + "_rest" + cut;
          TH1D *histqq = (TH1D *)hists[histNameqq];
          TH1D *histgg = (TH1D *)hists[histNamegg];
          TH1D *histrest = (TH1D *)hists[histNamerest];
          sum=histqq->Integral()+histgg->Integral()+histrest->Integral()+0.0;
          cout<<spinType<<" "<<cut<<" "<<partonState<<" "<<endl;
          cout<<"Event number : "<<" qq = "<<histqq->Integral()<<" gg = "<<histgg->Integral()<<" rest = "<<histrest->Integral()<<endl;
          cout<<"Event fraction : "<<" qq = "<<histqq->Integral()/sum<<" gg = "<<histgg->Integral()/sum<<" rest = "<<histrest->Integral()/sum<<endl;
        //   Draw_Template::SymmetryTwoPads(
        //       {histrest, histqq, histgg},
        //       "IFN/" + spinType + "_" + partonState + cut + ".pdf",
        //       spinType + " " + partonState + " " + cut);
        }
      }
    }
}