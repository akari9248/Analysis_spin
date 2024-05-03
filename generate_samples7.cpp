#include "/home/zlin/higgs/include/Process_bar.h"
#include <TChain.h>
#include <TFile.h>
#include <TLorentzVector.h>
#include <TTree.h>
#include <cassert>
#include <fastjet/ClusterSequence.hh>
#include <fastjet/PseudoJet.hh>
#include <fstream>
#include <iostream>
#include <tuple>
#include <vector>
#include <algorithm>
#include <random>
#include "include/LoadData.h"
#include "include/SaveData.h"
#include "include/common_tool.h"
#include "include/Matching.cc"
// 使用FastJet的命名空间
using namespace fastjet;
using namespace std;
//g++ generate_samples5.cpp -L/home/zlin/.local/lib -lRecursiveTools `root-config --cflags --ldflags --glibs` `fastjet-config --cxxflags --libs --plugins`  -o generate_samples5
int main() {
  // 创建TChain
  TChain chain_on("on");
  TChain chain_off("off");

  // 添加ROOT文件到TChain
  for (int i = 1; i <= 19; ++i) {
    chain_on.Add(Form("/storage/xiaoxue/code/git_file/QCDAnalysis/OfflineExamples/data/herwig/Hadron_1_spinon_450_forai/chunk%d/Hadron_1_spinon_450_forai.root/JetsAndDaughters",
                      i));
    chain_off.Add(Form("/storage/xiaoxue/code/git_file/QCDAnalysis/OfflineExamples/data/herwig/Hadron_1_spinoff_450_forai/chunk%d/Hadron_1_spinoff_450_forai.root/JetsAndDaughters",
                      i));
  }
  std::vector<std::vector<double>> xdata_on, xdata_off;
  std::vector<int> ydata_on, ydata_off;
  // 初始化空的列表来存储数据和标签
  LoadData LoadData_on(chain_on);
  LoadData_on.setzkcut(0.0,0.0,1,0);
  LoadData_on.setptcut(200);
  LoadData_on.setminflavourpt(5);
  //LoadData_on.setsecondhard();
  LoadData_on.AddProcessor("_Parton");
  LoadData_on.AddProcessor("_Hadron");
  auto data_on_vec=LoadData_on.processData(10000000);
  auto data_on_parton = data_on_vec.at(0);
  auto data_on_hadron = data_on_vec.at(1);
  LoadData LoadData_off(chain_off);
  LoadData_off.setzkcut(0.0,0.0,1,0);
  LoadData_off.setptcut(200);
  LoadData_off.setminflavourpt(5);
  //LoadData_off.setsecondhard();
  LoadData_off.AddProcessor("_Parton");
  LoadData_off.AddProcessor("_Hadron");
  auto data_off_vec=LoadData_off.processData(10000000);
  auto data_off_parton = data_off_vec.at(0);
  auto data_off_hadron = data_off_vec.at(1);

  auto match_on = JetBranch::matchPlanes(data_on_hadron.twoplanes,data_on_parton.twoplanes,"second");
  auto match_off =JetBranch::matchPlanes(data_off_hadron.twoplanes,data_off_parton.twoplanes,"second");
  
  auto data_on_hadron_matched = LoadData::ExtractFeatures(data_on_hadron.twoplanes,"_Hadron");
  auto data_off_hadron_matched = LoadData::ExtractFeatures(data_off_hadron.twoplanes,"_Hadron");

  auto data_on = LoadData::concatenateDataColumn(data_on_parton,data_on_hadron_matched);
  LoadData::AddFeature(data_on,"match",match_on);
  LoadData::AddFeature(data_on,"spin",1);
  auto data_off = LoadData::concatenateDataColumn(data_off_parton,data_off_hadron_matched);
  LoadData::AddFeature(data_off,"match",match_off);
  LoadData::AddFeature(data_off,"spin",0);
  auto combined_data = LoadData::concatenateDataRow(data_on,data_off);
  
  SaveData::saveToCSV(combined_data.xdata,combined_data.label,"test/validation_data_CA_lundplane_parton10Mz00pt200flav5.csv",true);
  SaveData::saveToROOT(combined_data.xdata,combined_data.label,"test/validation_data_CA_lundplane_parton10Mz00pt200flav5.root",true);

  // SaveData::saveToCSV(combined_data.xdata,combined_data.label,"test.csv",true);
  // SaveData::saveToROOT(combined_data.xdata,combined_data.label,"test.root",true);
  return 0;
}