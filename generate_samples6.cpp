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
// 使用FastJet的命名空间
using namespace fastjet;
using namespace std;
//g++ generate_samples5.cpp -L/home/zlin/.local/lib -lRecursiveTools `root-config --cflags --ldflags --glibs` `fastjet-config --cxxflags --libs --plugins`  -o generate_samples5
int main() {
  // 创建TChain
  TChain chain_on("on");
  TChain chain_off("off");

  // 添加ROOT文件到TChain
  for (int i = 1; i <= 100; ++i) {
    chain_on.Add(Form("/storage/xiaoxue/code/git_file/QCDAnalysis/"
                      "OfflineExamples/data/herwig/Parton_1_spinon_450/"
                      "chunk%i/Parton_1_spinon_450.root/JetsAndDaughters",
                      i));
    chain_off.Add(Form("/storage/xiaoxue/code/git_file/QCDAnalysis/"
                       "OfflineExamples/data/herwig/Parton_1_spinoff_450/"
                       "chunk%i/Parton_1_spinoff_450.root/JetsAndDaughters",
                       i));
  }
  std::vector<std::vector<double>> xdata_on, xdata_off;
  std::vector<int> ydata_on, ydata_off;
  // 初始化空的列表来存储数据和标签
  auto data_on = LoadData::opt1(chain_on, 1, 2000000);
  auto data_off = LoadData::opt1(chain_off, 0, 2000000);
  xdata_on = data_on.xdata;
  ydata_on = data_on.ydata;
  xdata_off = data_off.xdata;
  ydata_off = data_off.ydata;
  std::vector<std::vector<double>> xdata_combined = xdata_on;
  xdata_combined.insert(xdata_combined.end(), xdata_off.begin(),
                        xdata_off.end());
  std::vector<int> ydata_combined = ydata_on;
  ydata_combined.insert(ydata_combined.end(), ydata_off.begin(),
                        ydata_off.end());
  //SaveData::saveToCSV(xdata_combined,ydata_combined,data_on.label,"test.csv",true,"spin");
  SaveData::saveToROOT(xdata_combined,ydata_combined,data_on.label,"test/validation_data_CA_lundplane_parton.root",true,"spin");
  
  return 0;
}