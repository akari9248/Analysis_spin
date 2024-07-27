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
#include "TObjString.h"
#include "../include/MetaDataManager.h"
void TwoPads(vector<TH1D *> hists,TString filename,TString ExtraText="",vector<TString> legend_name={});
void draw_pt(){
    MetaDataManager manager;

    MetaData* md1 = manager.CreateMetaData("Sample12");
    md1->AddParameter("Param1", "Value1");
    md1->AddParameter("Param2", "Value2");

    MetaData* md2 = manager.CreateMetaData("Sample22");
    md2->AddParameter("ParamA", "A=2");
    md2->AddParameter("ParamB", "ValueB");

    manager.SaveToRootFile("example_with_metadata.root");

    MetaDataManager newManager;
    newManager.LoadFromRootFile("example_with_metadata.root");

    std::cout << newManager.GetMetaDataAsString() << std::endl;

    return 0;
}

