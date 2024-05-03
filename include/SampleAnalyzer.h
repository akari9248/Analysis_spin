#pragma once
#include "TFile.h"
#include "TH1D.h"
#include "TTree.h"
#include "TLorentzVector.h"
#include "Hists.h"
#include "Process_bar.h"

template <typename T>
class SampleAnalyzer {
protected:
    TChain *t;
    T *events;
    
    int entries;

public:
    Hists hists;
    SampleAnalyzer() {
        t = new TChain();
        events = new T(t);
    }
    ~SampleAnalyzer() {
        delete t;
        delete events;
    }
    virtual void initialize()=0;
    virtual void analyze()=0;
    void finalize(const std::string& outfile="out.root") {
        hists.Write(outfile.c_str());
    }
    void run(int _entries = -1) {
      initialize();
      entries = t->GetEntries();
      if (_entries != -1 && _entries < entries) {
        entries = _entries;
      }
      cout<<entries<<endl;
      ProcessBar ProcessBar(entries);
      for (int i = 0; i < entries; i++) {
        ProcessBar.show2(i);
        t->GetEntry(i);
        analyze();
      }
    }
};

