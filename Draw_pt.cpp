// gInterpreter->AddIncludePath("/home/zlin/.local/include");
#include "TFile.h"
#include "TH1D.h"
#include "TLorentzVector.h"
#include "TTree.h"
#include "include/DNNTrainTree.h"
#include "include/Draw_Template.h"
#include "include/Hists.h"
#include "include/JetBranch.h"
#include "include/Process_bar.h"
#include "include/SampleAnalyzer.h"
#include <iostream>
#include <iomanip>
#include <cmath>
#include "include/common_tool.h"
#include "include/Draw_Template.h"
#include "include/chiscan.h"
class EventsAnalyzer : public SampleAnalyzer<DNNTrainTree> {
public:
  vector<string> spin_strs;
  vector<string> cut_strs;
  int count;
  CommonTool::Options options;
  EventsAnalyzer(CommonTool::Options _options){
    options=_options;
  }
  void initialize() override {
    t->Add((TString)options.inputFolder+"/Chunk*.root/DNNTrainTree");
    hists.addHist("pt", 7000 , 0, 7000);
  }
  void analyze() override {
    cout<<events->Recojpt->size()<<endl;
    for(auto &jpt:*events->Recojpt){
      hists["pt"]->Fill(jpt,events->GeneratorWeight);
    }
  }
};

int main(int argc, char *argv[])
{
  CommonTool::Options options;
  options.inputFolder = "/home/zlin/Machine_learning/ML/Datasets/Prediction/CMS_herwig_Pt-15to7000jinitpt6007000j2pt1307000_FourLabel_unmatched";
  EventsAnalyzer spinon_sample(options);
  spinon_sample.run_frac(1);
  spinon_sample.hists.Write("pt.root");
  return 0;
}

