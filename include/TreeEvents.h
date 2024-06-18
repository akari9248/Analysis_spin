#pragma once
#include <boost/variant.hpp>
#include <iostream>
#include <map>
#include <string>
#include <vector>

using namespace std;

// 定义 DataVariant 作为 variant，它可以存储不同类型的 vector 或单个值。
using DataVariant = boost::variant<vector<int>, vector<double>, int, double>;

class TreeEvents {
public:
  class TreeEvent {
  public:
    std::map<std::string, DataVariant> branches;
    void addData(const std::string &key, const DataVariant &value) {
      branches[key] = value;
    }
    DataVariant &operator[](const std::string &key) {
      // 使用 boost::get 时需要注意，它会抛出 boost::bad_get
      // 异常，如果类型不匹配
      return branches.at(key); // 使用 at 以确保抛出异常，如果 key 不存在
    }
    template <typename T>
    bool push_back(const std::string &key, const T &value) {
      auto &vec = boost::get<vector<T>>(branches[key]);
      vec.push_back(value);
      return true;
    }
    template <typename T> bool assign(const std::string &key, const T &value) {
      try {
        // 尝试获取对应类型的引用
        T &stored_value = boost::get<T>(branches[key]);
        stored_value = value;
        return true;
      } catch (const boost::bad_get &bg) {
        // 类型不匹配，处理错误或静默失败
        std::cerr << "Type mismatch error: " << bg.what() << std::endl;
        return false;
      }
    }
    TreeEvent operator+(const TreeEvent &other) const {
      TreeEvent result = *this; // Start with a copy of the current TreeEvent
      for (const auto &kv : other.branches) {
        result.branches[kv.first] =
            kv.second; // This will overwrite if key exists
      }
      return result;
    }
    void addBranches(const std::string &input) {
      size_t pos = input.find('/');
      std::string name, type;
      if (pos != std::string::npos) {
        name = input.substr(0, pos);
        type = input.substr(pos + 1);
      }
      if (type == "vD") {
        vector<double> branch = {};
        branches[name] = branch;
      } else if (type == "vI") {
        vector<int> branch = {};
        branches[name] = branch;
      } else if (type == "D") {
        double branch = -1;
        branches[name] = branch;
      } else if (type == "I") {
        int branch = -1;
        branches[name] = branch;
      }
    }
    void printBranchName() {
      for (const auto &pair : branches) {
        std::cout << "Key: " << pair.first << std::endl;
      }
    }
  };
  vector<TreeEvent> treeEvents;
  TreeEvent treeEvent;
  TreeEvent treeEvent_backup;
  TreeEvents() {}
  void addBranches(const std::string &input) {
    size_t pos = input.find('/');
    std::string name, type;
    if (pos != std::string::npos) {
      name = input.substr(0, pos);
      type = input.substr(pos + 1);
    }
    if (type == "vD") {
      vector<double> branch = {};
      treeEvent_backup.addData(name, branch);
    } else if (type == "vI") {
      vector<int> branch = {};
      treeEvent_backup.addData(name, branch);
    } else if (type == "D") {
      double branch = -1;
      treeEvent_backup.addData(name, branch);
    } else if (type == "I") {
      int branch = -1;
      treeEvent_backup.addData(name, branch);
    }
  }
  DataVariant &operator[](const std::string &key) { return treeEvent[key]; }
  TreeEvents operator+(const TreeEvents &other) const {
    TreeEvents out;
    int i = 0;
    for (auto event : treeEvents) {
      event = event + other.treeEvents.at(i);
      out.treeEvents.push_back(event);
      i++;
    }
    return out;
  }
  void BeginEvent() {
    auto emptyevent = treeEvent_backup;
    treeEvents.push_back(emptyevent);
    }
  template <typename T> bool assign(const std::string &key, const T &value) {
    if (treeEvents.empty()) {
      return false; // 如果 treeEvents 为空，无法进行赋值
    }
    return treeEvents.back().assign(key, value);
  }

  template <typename T> bool push_back(const std::string &key, const T &value) {
    if (treeEvents.empty()) {
      return false; // 如果 treeEvents 为空，无法进行赋值
    }
    return treeEvents.back().push_back(key, value);
  }
  void clear(){
    treeEvents.clear();
  }
};