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
using namespace std;
class Hists {
private:
    std::map<std::string, TH1*> hists;

public:
    Hists(){}
    Hists(TString filename){
        Hists::Load(filename);
    }
    void addHist(const std::string& histName, int nbins, double binbegin, double binend) {
        TH1D *hist = new TH1D((TString)getUniqueName(histName), histName.c_str(), nbins, binbegin, binend);
        hists[histName] = hist;
    }
    void addHist(const std::string& histName, int nbinsX, double binbeginX, double binendX, int nbinsY, double binbeginY, double binendY) {
        TH2D *hist = new TH2D((TString)getUniqueName(histName), histName.c_str(), nbinsX, binbeginX, binendX, nbinsY, binbeginY, binendY);
        hists[histName] = hist;
    }
    TH1* operator[](const std::string& histName) {
        auto it = hists.find(histName);
        if (it != hists.end()) {
            return it->second;
        } else {
            std::cerr << "Error: Histogram not found: " << histName << std::endl;
            exit(0);
            return nullptr;
        }
    }
    int size(){
        return hists.size();
    }
    std::string getUniqueName(std::string baseName) {
        int suffix = 1; 
        std::string uniqueName = baseName ;  
        while (gDirectory->Get(uniqueName.c_str())) {
            suffix++; 
            uniqueName = baseName + std::to_string(suffix);  
        }
        return uniqueName;  
    }
    void list()
    {
        for (const auto &pair : hists)
        {
            const std::string &histName = pair.first;
            cout<<histName<<endl;
        }
    }
    void Add(Hists &histIn,double scale=1)
    {
        for (const auto &pair : hists)
        {
            const std::string &histName = pair.first;
            hists[histName]->Add(histIn[histName],scale);
        }
    }
    void Add(TString root_file,double scale=1)
    {
        Hists histIn(root_file);
        this->Add(histIn,scale);
    }
    void Scale(double scale){
        for (auto& pair : hists) {
            pair.second->Scale(scale);  
        }
    }
    void Write(const TString& filename = "output.root") {
        TFile file(filename, "RECREATE");  
        if (!file.IsOpen()) {
            std::cerr << "Failed to open file: " << filename << std::endl;
            return;
        }

        for (auto& pair : hists) {
            pair.second->Write(pair.second->GetTitle());  
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
        hists[hist->GetTitle()] = (TH1*)hist->Clone();
        hists[hist->GetTitle()]->SetDirectory(0); // 防止随文件关闭而被删除
      }
      file->Close();
      delete file;
    }
    // ~Hists() {
    //     for (auto& pair : hists) {
    //         delete pair.second;
    //     }
    //     hists.clear();
    // }
};