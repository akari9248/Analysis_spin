#pragma once

#include <map>
#include <string>
#include "TH1.h" 
#include "TString.h"
#include "TFile.h"  
#include "TH2D.h"
#include "TH1D.h"
#include "TH3D.h"
#include <iostream>
#include "TKey.h"
class Hists {
private:
    std::map<std::string, TH1*> hists;

public:
    void addHist(const std::string& histName, int nbins, double binbegin, double binend) {
        TH1D *hist = new TH1D(histName.c_str(), histName.c_str(), nbins, binbegin, binend);
        hists[histName] = hist;
    }
    void addHist(const std::string& histName, int nbinsX, double binbeginX, double binendX, int nbinsY, double binbeginY, double binendY) {
        TH2D *hist = new TH2D(histName.c_str(), histName.c_str(), nbinsX, binbeginX, binendX, nbinsY, binbeginY, binendY);
        hists[histName] = hist;
    }
    TH1* operator[](const std::string& histName) {
        return hists[histName];
    }
    int size(){
        return hists.size();
    }

    // 将所有直方图写入指定的 ROOT 文件
    void Write(const TString& filename = "output.root") {
        TFile file(filename, "RECREATE");  
        if (!file.IsOpen()) {
            std::cerr << "Failed to open file: " << filename << std::endl;
            return;
        }

        for (auto& pair : hists) {
            pair.second->Write();  
        }

        file.Close(); 
    }
    void Load(TString filename) {
      // 打开ROOT文件
      TFile *file = TFile::Open(filename);
      if (!file || file->IsZombie()) {
        std::cerr << "Error opening file: " << filename << std::endl;
        return;
      }
      TKey *key;
      TIter nextkey(file->GetListOfKeys());
      while ((key = (TKey *)nextkey())) {
        auto hist = (TH1 *)key->ReadObj();
        hists[hist->GetName()] = (TH1*)hist->Clone();
        hists[hist->GetName()]->SetDirectory(0); // 防止随文件关闭而被删除
      }
      file->Close();
      delete file;
    }
    ~Hists() {
        for (auto& pair : hists) {
            delete pair.second;
        }
        hists.clear();
    }
};