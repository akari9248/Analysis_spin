#include "TFile.h"
#include "TH1D.h"
#include "TLorentzVector.h"
#include "TString.h"
#include "TTree.h"
#include "include/AdvancedDataInfo.h"
#include "include/Draw_Template.h"
#include "include/Hists.h"
#include "include/Process_bar.h"
#include "include/SampleAnalyzer.h"
#include "include/SaveData.h"
#include "include/TreeEvents.h"
class EventsAnalyzer : public SampleAnalyzer<AdvancedDataInfo> {
public:
  TreeEvents treeEvents_spinon, treeEvents_spinoff;
  TString partontype;
  EventsAnalyzer( TString _partontype)
      : partontype(_partontype) {
    treeEvents_spinon.addBranches("pt1/D");
    treeEvents_spinon.addBranches("eta1/D");
    treeEvents_spinon.addBranches("phi1/D");
    treeEvents_spinon.addBranches("e1/D");
    treeEvents_spinon.addBranches("pt2/D");
    treeEvents_spinon.addBranches("eta2/D");
    treeEvents_spinon.addBranches("phi2/D");
    treeEvents_spinon.addBranches("e2/D");
    treeEvents_spinon.addBranches("pt3/D");
    treeEvents_spinon.addBranches("eta3/D");
    treeEvents_spinon.addBranches("phi3/D");
    treeEvents_spinon.addBranches("e3/D");

    treeEvents_spinon.addBranches("z1/D");
    treeEvents_spinon.addBranches("kt1/D");
    treeEvents_spinon.addBranches("deltaR1/D");
    treeEvents_spinon.addBranches("eec1/D");

    treeEvents_spinon.addBranches("z2/D");
    treeEvents_spinon.addBranches("kt2/D");
    treeEvents_spinon.addBranches("deltaR2/D");
    treeEvents_spinon.addBranches("eec2/D");

    treeEvents_spinon.addBranches("phi/D");
    treeEvents_spinon.addBranches("type/I");

    treeEvents_spinoff.addBranches("pt1/D");
    treeEvents_spinoff.addBranches("eta1/D");
    treeEvents_spinoff.addBranches("phi1/D");
    treeEvents_spinoff.addBranches("e1/D");
    treeEvents_spinoff.addBranches("pt2/D");
    treeEvents_spinoff.addBranches("eta2/D");
    treeEvents_spinoff.addBranches("phi2/D");
    treeEvents_spinoff.addBranches("e2/D");
    treeEvents_spinoff.addBranches("pt3/D");
    treeEvents_spinoff.addBranches("eta3/D");
    treeEvents_spinoff.addBranches("phi3/D");
    treeEvents_spinoff.addBranches("e3/D");

    treeEvents_spinoff.addBranches("z1/D");
    treeEvents_spinoff.addBranches("kt1/D");
    treeEvents_spinoff.addBranches("deltaR1/D");
    treeEvents_spinoff.addBranches("eec1/D");

    treeEvents_spinoff.addBranches("z2/D");
    treeEvents_spinoff.addBranches("kt2/D");
    treeEvents_spinoff.addBranches("deltaR2/D");
    treeEvents_spinoff.addBranches("eec2/D");

    treeEvents_spinoff.addBranches("phi/D");
    treeEvents_spinoff.addBranches("type/I");
  }
  void initialize() override {
    for (int i = 0; i < 5; i++)
      for(int i=0;i<1;i++)
            t->Add(TString::Format("test/validation_data_CA_lundplane_partonz00pt200IFN_matchsecond/Chunk%d.root/DataInfo",i));
  }
  void analyze() override {
    double ktcut = 4;
    bool spinon = events->spin == 1;
    bool spinoff = events->spin == 0;
    if (partontype == "Parton") {
      for (int i = 0; i < events->kt2_Parton->size(); i++) {
        if (events->kt2_Parton->at(i) <= ktcut)
          continue;
        TreeEvents::TreeEvent treeEvent;
        if (spinon)
          treeEvent = treeEvents_spinon.treeEvent_backup;
        if (spinoff)
          treeEvent = treeEvents_spinoff.treeEvent_backup;
        
        treeEvent.assign("pt1", events->pt1_Parton->at(i));
        treeEvent.assign("eta1", events->eta1_Parton->at(i));
        treeEvent.assign("phi1", events->phi1_Parton->at(i));
        treeEvent.assign("e1", events->e1_Parton->at(i));
        treeEvent.assign("pt2", events->pt3_Parton->at(i));
        treeEvent.assign("eta2", events->eta3_Parton->at(i));
        treeEvent.assign("phi2", events->phi3_Parton->at(i));
        treeEvent.assign("e2", events->e3_Parton->at(i));
        treeEvent.assign("pt3", events->pt4_Parton->at(i));
        treeEvent.assign("eta3", events->eta4_Parton->at(i));
        treeEvent.assign("phi3", events->phi4_Parton->at(i));
        treeEvent.assign("e3", events->e4_Parton->at(i));

        treeEvent.assign("z1", events->z1_Parton->at(i));
        treeEvent.assign("kt1", events->kt1_Parton->at(i));
        treeEvent.assign("deltaR1", events->deltaR1_Parton->at(i));
        treeEvent.assign("eec1", events->eec1_Parton->at(i));

        treeEvent.assign("z2", events->z2_Parton->at(i));
        treeEvent.assign("kt2", events->kt2_Parton->at(i));
        treeEvent.assign("deltaR2", events->deltaR2_Parton->at(i));
        treeEvent.assign("eec2", events->eec2_Parton->at(i));

        treeEvent.assign("phi", events->phi_Parton->at(i));
        treeEvent.assign("type", events->isqq_Parton->at(i) * 2 +
                                     events->isgg_Parton->at(i));
        if (spinon)
          treeEvents_spinon.treeEvents.push_back(treeEvent);
        if (spinoff)
          treeEvents_spinoff.treeEvents.push_back(treeEvent);

      }
    }
    if (partontype == "Hadron") {
      for (int i = 0; i < events->kt2_Hadron->size(); i++) {
        if (events->kt2_Hadron->at(i) <= ktcut)
          continue;
        TreeEvents::TreeEvent treeEvent;
        if (spinon)
          treeEvent = treeEvents_spinon.treeEvent_backup;
        if (spinoff)
          treeEvent = treeEvents_spinoff.treeEvent_backup;
        treeEvent.assign("pt1", events->pt1_Hadron->at(i));
        treeEvent.assign("eta1", events->eta1_Hadron->at(i));
        treeEvent.assign("phi1", events->phi1_Hadron->at(i));
        treeEvent.assign("e1", events->e1_Hadron->at(i));
        treeEvent.assign("pt2", events->pt3_Hadron->at(i));
        treeEvent.assign("eta2", events->eta3_Hadron->at(i));
        treeEvent.assign("phi2", events->phi3_Hadron->at(i));
        treeEvent.assign("e2", events->e3_Hadron->at(i));
        treeEvent.assign("pt3", events->pt4_Hadron->at(i));
        treeEvent.assign("eta3", events->eta4_Hadron->at(i));
        treeEvent.assign("phi3", events->phi4_Hadron->at(i));
        treeEvent.assign("e3", events->e4_Hadron->at(i));

        treeEvent.assign("z1", events->z1_Hadron->at(i));
        treeEvent.assign("kt1", events->kt1_Hadron->at(i));
        treeEvent.assign("deltaR1", events->deltaR1_Hadron->at(i));
        treeEvent.assign("eec1", events->eec1_Hadron->at(i));

        treeEvent.assign("z2", events->z2_Hadron->at(i));
        treeEvent.assign("kt2", events->kt2_Hadron->at(i));
        treeEvent.assign("deltaR2", events->deltaR2_Hadron->at(i));
        treeEvent.assign("eec2", events->eec2_Hadron->at(i));

        treeEvent.assign("phi", events->phi_Hadron->at(i));
        treeEvent.assign("type", events->isqq_Hadron->at(i) * 2 +
                                     events->isgg_Hadron->at(i));
        if (spinon)
          treeEvents_spinon.treeEvents.push_back(treeEvent);
        if (spinoff)
          treeEvents_spinoff.treeEvents.push_back(treeEvent);
      }
    }
  }
};

// int GenerateMini() {
int main() {
  EventsAnalyzer analyzerParton("Parton");
  analyzerParton.run();
  SaveData::writeTreeEventsToRoot(analyzerParton.treeEvents_spinon,
                                  "Parton_Spinon.root", true);
  SaveData::writeTreeEventsToRoot(analyzerParton.treeEvents_spinoff,
                                  "Parton_Spinoff.root", true);
  EventsAnalyzer analyzerHadron("Hadron");
  analyzerHadron.run();
  SaveData::writeTreeEventsToRoot(analyzerHadron.treeEvents_spinon,
                                  "Hadron_Spinon.root", true);
  SaveData::writeTreeEventsToRoot(analyzerHadron.treeEvents_spinoff,
                                  "Hadron_Spinoff.root", true);

  return 0;
}