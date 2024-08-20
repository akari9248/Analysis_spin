#pragma once
#include "TString.h"
#include <TFile.h>
#include <TTree.h>
#include <algorithm>
#include <fstream>
#include <iostream>
#include <numeric>
#include <random>
#include <string>
#include <vector>
#include <boost/variant.hpp>
#include "TreeEvents.h"
#include "Process_bar.h"
class DataVisitor : public boost::static_visitor<> {
public:
  template <typename T> void operator()(T &value) const {
  }

  void operator()(std::vector<int> &vi) const {
  }

  void operator()(std::vector<double> &vd) const {
  }
};
class SaveData {
public:
  static bool saveToCSV(const std::vector<std::vector<double>> &xdata_combined,
                        const std::vector<int> &ydata_combined,
                        const std::vector<TString> &labels,
                        const std::string &filename, bool shuffle,
                        TString final_label = "Label") {
    std::ofstream csv_file(filename);
    if (!csv_file.is_open()) {
      std::cerr << "Error: Unable to open file." << std::endl;
      return false;
    }

    for (const auto &label : labels) {
      csv_file << label << ",";
    }
    csv_file << final_label << "\n";

    std::vector<size_t> indices(xdata_combined.size());
    std::iota(indices.begin(), indices.end(), 0);

    if (shuffle) {
      std::random_device rd;
      std::mt19937 g(rd());
      std::shuffle(indices.begin(), indices.end(), g);
    }

    for (auto idx : indices) {
      for (const auto &val : xdata_combined[idx]) {
        csv_file << val << ",";
      }
      csv_file << ydata_combined[idx] << "\n";
    }
    std::cout << " Complete write to csv file : " << filename << std::endl;
    return true;
  }


  static void writeTreeEventsToRoot(const TreeEvents &events,
                                    const std::string &filename, bool shuffle) {
    TFile file(filename.c_str(), "RECREATE");
    TTree tree("DataInfo", "DataInfo");

    std::map<std::string, boost::variant<double *, int *, std::vector<double> *,
                                         std::vector<int> *>>
        buffers;

    if(events.treeEvents.size()==0) {
      cout<<" None of Events can be stored. "<<endl;
      return;
    }
    for (const auto &kv : events.treeEvents.at(0).branches) {
      boost::apply_visitor(
          [&](auto &&arg) {
            using T = std::decay_t<decltype(arg)>;
            if (std::is_same<T, std::vector<double>>::value) {
              buffers[kv.first] = new std::vector<double>;
              tree.Branch(
                  kv.first.c_str(),
                  static_cast<std::vector<double> *>(
                      boost::get<std::vector<double> *>(buffers[kv.first])));
            } else if (std::is_same<T, std::vector<int>>::value) {
              buffers[kv.first] = new std::vector<int>;
              tree.Branch(kv.first.c_str(), static_cast<std::vector<int> *>(
                                                boost::get<std::vector<int> *>(
                                                    buffers[kv.first])));
            } else if (std::is_same<T, double>::value) {
              buffers[kv.first] = new double;
              tree.Branch(kv.first.c_str(),
                          static_cast<double *>(
                              boost::get<double *>(buffers[kv.first])));
            } else if (std::is_same<T, int>::value) {
              buffers[kv.first] = new int;
              tree.Branch(
                  kv.first.c_str(),
                  static_cast<int *>(boost::get<int *>(buffers[kv.first])));
            }
          },
          kv.second);
    }
    std::vector<size_t> indices(events.treeEvents.size());
    std::iota(indices.begin(), indices.end(), 0);

    if (shuffle) {
      std::random_device rd;
      std::mt19937 g(rd());
      std::shuffle(indices.begin(), indices.end(), g);
    }

    ProcessBar processbar(indices.size(),10);
    int k=0;
    for (auto idx : indices) {
      processbar.show2(++k,"Save to RootFile "+TString(filename));
      const auto &event = events.treeEvents[idx];
      for (const auto &kv : event.branches) {
        boost::apply_visitor(
            [&](auto &&arg) {
              using T = std::decay_t<decltype(arg)>;
              *boost::get<T *>(buffers[kv.first]) = arg;
            },
            kv.second);
      }
      tree.Fill();
    }

    tree.Write();
    file.Close();
  }
};