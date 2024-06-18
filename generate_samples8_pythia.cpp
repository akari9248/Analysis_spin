#include "include/LoadData.h"
#include "include/Matching.cc"
#include "include/Process_bar.h"
#include "include/SaveData.h"
#include "include/common_tool.h"
#include <TChain.h>
#include <TFile.h>
#include <TLorentzVector.h>
#include <TTree.h>
#include <algorithm>
#include <cassert>
#include <fastjet/ClusterSequence.hh>
#include <fastjet/PseudoJet.hh>
#include <fstream>
#include <getopt.h>
#include <iostream>
#include <random>
#include <tuple>
#include <vector>

// 使用FastJet的命名空间
using namespace fastjet;
using namespace std;
// g++ generate_samples8_pythia.cpp $(root-config --cflags --evelibs)
// $(fastjet-config --cxxflags --libs --plugins) -I/home/zlin/.local/include
// -L/home/zlin/.local/lib -lRecursiveTools -lIFNPlugin -o
// generate_samples8_pythia
int main(int argc, char *argv[]) {
  int opt;
  TString flavour = "IFN";
  int chunk_part = -1; // 新增变量，用于存储 -i 参数的值
  while ((opt = getopt(argc, argv, "f:i:")) != -1) {
    switch (opt) {
    case 'f':
      flavour = optarg;
      break;
    case 'i':
      chunk_part = atoi(optarg); // 将参数转换为整数
      break;
    default:
      cerr << "Usage: " << argv[0] << " [-f flavour] [-i inputInt]" << endl;
      return 1;
    }
  }

  // 创建TChain
  TChain chain_on("on");
  TChain chain_off("off");

  // 添加ROOT文件到TChain
  for (int i = 0; i <= 80; ++i) {
    chain_on.Add(Form(
        "/storage/shuangyuan/code/analysis_qq_qcd/event/particle_pp_pythia_on/"
        "Chunk%d/Part_pt450_-1_Ak8.root/JetsAndDaughters",
        i));
    chain_off.Add(Form(
        "/storage/shuangyuan/code/analysis_qq_qcd/event/particle_pp_pythia_off/"
        "Chunk%d/Part_pt450_-1_Ak8.root/JetsAndDaughters",
        i));
  }
  cout << "using Flavour tagger :" << flavour << endl;
  int chunknum=50;
  // TString flavour = "Net";
  // TString flavour = "Netcustomed";
  int chunkentries = chain_on.GetEntries() / chunknum;
  int partnum = 100;
  for (int chunki = 0; chunki < chunknum; chunki++) {
    if (chunki != chunk_part && chunk_part != -1)
      continue;
    int partentries = chunkentries/partnum;
    for (int part = 0; part < partnum; part++) {
      int part_begin=chunki * chunkentries+part*partentries;
      std::vector<std::vector<double>> xdata_on, xdata_off;
      std::vector<int> ydata_on, ydata_off;
      // 初始化空的列表来存储数据和标签
      LoadData LoadData_on(chain_on);
      LoadData_on.setzkcut(0.0, 0.0, 1, 0);
      LoadData_on.setptcut(450);
      // LoadData_on.setminflavourpt(5);
      // LoadData_on.setsecondhard();
      LoadData_on.setFlavourAlgorithm(flavour);
      LoadData_on.AddProcessor("_Parton");
      LoadData_on.AddProcessor("_Hadron");
      auto data_on_vec =
          LoadData_on.processData(partentries, "opt1", part_begin);

      auto data_on_parton = data_on_vec.at(0);
      auto data_on_hadron = data_on_vec.at(1);
      LoadData LoadData_off(chain_off);
      LoadData_off.setzkcut(0.0, 0.0, 1, 0);
      LoadData_off.setptcut(450);
      // LoadData_off.setminflavourpt(5);
      // LoadData_off.setsecondhard();
      LoadData_off.setFlavourAlgorithm(flavour);
      LoadData_off.AddProcessor("_Parton");
      LoadData_off.AddProcessor("_Hadron");

      auto data_off_vec =
          LoadData_off.processData(partentries, "opt1", part_begin);
      auto data_off_parton = data_off_vec.at(0);
      auto data_off_hadron = data_off_vec.at(1);
      auto match_on = JetBranch::matchPlanes(
          data_on_hadron.twoplanes, data_on_parton.twoplanes, "second", 0.5);
      auto match_off = JetBranch::matchPlanes(
          data_off_hadron.twoplanes, data_off_parton.twoplanes, "second", 0.5);
      // data_on_hadron.treeEvents.treeEvent_backup.printBranchName();
      auto data_on_hadron_matched =
          LoadData::ExtractFeaturesFromPlanes(data_on_hadron, "_Hadron");
      auto data_off_hadron_matched =
          LoadData::ExtractFeaturesFromPlanes(data_off_hadron, "_Hadron");
      auto data_on = LoadData::concatenateDataColumn(data_on_parton,
                                                     data_on_hadron_matched);
      LoadData::AddFeature(data_on, "match", match_on);
      LoadData::AddFeature(data_on, "spin", 1);
      auto data_off = LoadData::concatenateDataColumn(data_off_parton,
                                                      data_off_hadron_matched);
      LoadData::AddFeature(data_off, "match", match_off);
      LoadData::AddFeature(data_off, "spin", 0);

      auto combined_data = LoadData::concatenateDataRow(data_on, data_off);
      // SaveData::saveToCSV(combined_data.xdata,combined_data.label,"test/validation_data_CA_lundplane_parton10Mz00pt200IFN_matchfull.csv",true);
      SaveData::writeTreeEventsToRoot(
          combined_data.treeEvents,
          "test/pythia_pt450_" + (string)flavour + "_May28/Chunk" +
              std::to_string(chunki) + "_" + std::to_string(part) + ".root",
          true);
      // SaveData::writeTreeEventsToRoot(
      //     combined_data.treeEvents,
      //     "test/test/Chunk" +
      //         std::to_string(chunki) + ".root",
      //     true);
    }
  }

  // SaveData::saveToCSV(combined_data.xdata,combined_data.label,"test.csv",true);
  // SaveData::saveToROOT(combined_data.xdata,combined_data.label,"test.root",true);
  return 0;
}