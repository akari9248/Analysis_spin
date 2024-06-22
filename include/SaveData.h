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
    // 这里可以根据 `T` 的类型进行处理
  }

  void operator()(std::vector<int> &vi) const {
    // 处理整数向量
  }

  void operator()(std::vector<double> &vd) const {
    // 处理浮点向量
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

    // 写入列标签
    for (const auto &label : labels) {
      csv_file << label << ",";
    }
    csv_file << final_label << "\n";

    // 创建索引数组
    std::vector<size_t> indices(xdata_combined.size());
    std::iota(indices.begin(), indices.end(), 0);

    if (shuffle) {
      // 创建随机数生成器
      std::random_device rd;
      std::mt19937 g(rd());
      // 打乱索引
      std::shuffle(indices.begin(), indices.end(), g);
    }

    // 按照索引写入数据
    for (auto idx : indices) {
      for (const auto &val : xdata_combined[idx]) {
        csv_file << val << ",";
      }
      csv_file << ydata_combined[idx] << "\n";
    }
    std::cout << " Complete write to csv file : " << filename << std::endl;
    return true;
  }
  // static bool saveToCSV(const vector<std::vector<std::vector<double>>>
  // &xdata_combined,
  //                       const std::vector<TString> &labels,
  //                       const std::string &filename, bool shuffle) {
  //   std::ofstream csv_file(filename);
  //   if (!csv_file.is_open()) {
  //     std::cerr << "Error: Unable to open file." << std::endl;
  //     return false;
  //   }
  //   for (size_t i = 0; i < labels.size(); ++i) {
  //     csv_file << labels[i];
  //     if (i != labels.size() - 1) {
  //       csv_file << ",";
  //     }
  //   }
  //   csv_file << endl;
  //   std::vector<size_t> indices(xdata_combined.size());
  //   std::iota(indices.begin(), indices.end(), 0);

  //   if (shuffle) {
  //     // 创建随机数生成器
  //     std::random_device rd;
  //     std::mt19937 g(rd());
  //     // 打乱索引
  //     std::shuffle(indices.begin(), indices.end(), g);
  //   }

  //   // 按照索引写入数据
  //   for (auto idx : indices) {
  //     for (size_t row = 0; row < xdata_combined[idx].size(); ++row) {
  //       for (size_t column = 0; column < xdata_combined[idx][row].size();
  //            ++column) {
  //         csv_file << xdata_combined[idx][row][column];
  //         if (row != xdata_combined[idx].size() - 1) {
  //           csv_file << ",";
  //         }
  //       }
  //     }
  //     csv_file << endl;
  //   }
  //   std::cout << " Complete write to csv file : " << filename << std::endl;
  //   return true;
  // }

  static void writeTreeEventsToRoot(const TreeEvents &events,
                                    const std::string &filename, bool shuffle) {
    TFile file(filename.c_str(), "RECREATE");
    TTree tree("DataInfo", "DataInfo");

    std::map<std::string, boost::variant<double *, int *, std::vector<double> *,
                                         std::vector<int> *>>
        buffers;

    // 初始化所有 branches 和 buffers
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

    // 填充数据
    ProcessBar processbar(indices.size());
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

    // 清理向量类型的 buffer
    // for (auto& kv : buffers) {
    //     boost::apply_visitor([](auto&& arg) {
    //         using T = std::decay_t<decltype(arg)>;
    //         delete boost::get<T>(arg);
    //     }, kv.second);
    // }

    // 写入文件并关闭
    tree.Write();
    file.Close();
  }
};