#pragma once
#include "TFile.h"
#include "TH1D.h"
#include "TTree.h"
#include "TLorentzVector.h"
#include "Hists.h"
#include "Process_bar.h"
#include "TString.h"
#include <numeric>
#include <random>
template <typename T>
class SampleAnalyzer
{
protected:
  TChain *t;
  T *events;
  bool isinitialized= false;
  int entries;

public:
  Hists hists;
  int entryi;
  SampleAnalyzer()
  {
    t = new TChain();
    events = new T(t);
  }
  ~SampleAnalyzer()
  {
    delete t;
    delete events;
  }
  virtual void initialize() = 0;
  virtual void analyze() = 0;
  void finalize(const std::string &outfile = "out.root")
  {
    hists.Write(outfile.c_str());
  }
  void check_init()
  {
    if (!isinitialized)
    {
      initialize();
      isinitialized = true;
    }
  }
  void run(int _entries = -1, int _entrybegin = 0)
  {
    check_init();
    int entry0 = t->GetEntries();
    entries = t->GetEntries();
    if (_entries != -1 && _entries < entries)
    {
      entries = _entries;
    }
    ProcessBar ProcessBar(entries, 100);
    for (entryi = _entrybegin; entryi < _entrybegin + entries; entryi++)
    {
      ProcessBar.show2(entryi - _entrybegin, TString::Format("Analyzing entries %d - %d, now %d , sum entries = %d", _entrybegin, _entrybegin + entries, entryi, entry0));
      t->GetEntry(entryi);
      analyze();
    }
  }
  void run_frac(double _entries_frac = 0.5, double _entrybegin_frac = 0)
  {
    check_init();
    entries = t->GetEntries();
    int _entries = entries * _entries_frac;
    int _entrybegin = entries * _entrybegin_frac;
    if(_entrybegin_frac>=1) {
      cout<< " Run out of entries " <<endl;
      return;}
    run(_entries, _entrybegin);
  }
  void run_frac_rand(double _entries_frac = 0.5)
  {
    check_init();
    entries = t->GetEntries();
    int _entries = entries * _entries_frac;

    std::vector<int> indices(entries);
    std::iota(indices.begin(), indices.end(), 0);
    unsigned seed = std::chrono::system_clock::now().time_since_epoch().count();
    std::shuffle(indices.begin(), indices.end(), std::default_random_engine(seed));
    std::vector<int> selected_indices(indices.begin(), indices.begin() + _entries);
    std::sort(selected_indices.begin(), selected_indices.end());

    ProcessBar ProcessBar(_entries, 100);
    for (int i = 0; i < _entries; i++)
    {
      int sorted_index = selected_indices[i];
      ProcessBar.show2(i, TString::Format("Analyzing entry %d", sorted_index));
      t->GetEntry(sorted_index);
      analyze();
    }
  }

};
class EmptyTree
{
public:
  EmptyTree(TChain *t){};
};
