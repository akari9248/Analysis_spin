#include <iostream>
#include <iomanip>
#include <vector>
#include <string>
#include "../include/Hists.h"
#include "../include/common_tool.h"
#include "TChain.h"
#include <TSystemDirectory.h>
#include <TList.h>
#include <TSystemFile.h>
using namespace std;
void print_help(char *argv[])
{
    std::cerr << "Usage: " << argv[0]
              << " --lumi <lumi_val> --root_file <path_to_root_file> --xsection_file <path_to_xsection_file> --output_file <output_file>\n"
              << "\n"
              << "Arguments:\n"
              << "  --lumi <lumi_val>         Integrated luminosity value. Default is 1.\n"
              << "  --root_file <path>        Path to a text file containing a list of ROOT files and the path to the original datasets (one per line).\n"
              << "  --xsection_file <path>    Path to a text file containing cross-sections. The second column of this file should\n"
              << "                            correspond to the cross-sections of the ROOT files listed in the root_file.\n"
              << "  --output_file <path>      Path to the output file.\n"
              << "\n"
              << "All arguments are required except for --lumi, which defaults to 1 if not specified.\n"
              << std::endl;
}
std::string FindTreePath(TDirectory *dir, const std::string& path = "") {
    TIter next(dir->GetListOfKeys());
    TKey *key;
    TObject *obj = nullptr;
    std::string treePath;

    while ((key = (TKey*)next())) {
        obj = key->ReadObj();
        std::string currentPath = path.empty() ? key->GetName() : path + "/" + key->GetName();
        if (obj->InheritsFrom(TTree::Class())) {
            treePath = currentPath;
            break;
        } else if (obj->InheritsFrom(TDirectory::Class())) {
            treePath = FindTreePath((TDirectory*)obj, currentPath);
            if (!treePath.empty()) {
                break;
            }
        }
    }

    return treePath;
}
void GetNumberOfEvents(string datasets,TH1 *hist){
    TSystemDirectory dir(datasets.c_str(), datasets.c_str());
    TList *files = dir.GetListOfFiles();
    if (!files) {
        std::cerr << "Error: Cannot open directory to list files." << std::endl;
        return;
    }

    // Find the first .root file in the directory
    TSystemFile *file;
    TString fileName;
    TIter next(files);
    while ((file = (TSystemFile*)next())) {
        fileName = file->GetName();
        if (!file->IsDirectory() && fileName.EndsWith(".root")) {
            fileName = datasets + "/" + fileName;
            break;
        }
    }

    if (fileName.IsNull()) {
        std::cerr << "Error: No .root files found in the provided directory." << std::endl;
        return;
    }

    TFile *rootFile = TFile::Open(fileName);
    if (!rootFile || rootFile->IsZombie()) {
        std::cerr << "Error: Cannot open .root file to determine tree name." << std::endl;
        return;
    }

    std::string treeName = FindTreePath(rootFile);

    rootFile->Close();
    delete rootFile;

    if (treeName.empty()) {
        std::cerr << "Error: No TTree found in the provided .root files." << std::endl;
        return;
    }
    TChain *t = new TChain();
    t->Add((TString)datasets+"/*.root/"+treeName);
    if (t->GetListOfBranches()->FindObject("NextPassedNumber")) {
        t->Draw("1 >> "+(TString)hist->GetName(),"NextPassedNumber");
    }else{
        hist->SetBinContent(2,t->GetEntries());
    }
    hist->SetBinContent(1,t->GetEntries());
}


int main(int argc, char *argv[])
{
    CommonTool::Options options = CommonTool::parseArguments(argc, argv,false);
    if(options.printhelp) {print_help(argv);return 0;};
    auto root_files = CommonTool::readFirstColumn(options.root_file);
    vector<string> origin_datasets= CommonTool::readSecondColumnAsString(options.root_file);
    bool fixed_scale=true;
    vector<double> xsections;
    if(!options.xsection_file.empty()){
        xsections = CommonTool::readSecondColumnAsDouble(options.xsection_file);
        fixed_scale=false;
    }
    
    auto output_file = options.output_file;
    std::string dir_path = output_file.substr(0, output_file.find_last_of('/'));
    if ( output_file.find_last_of('/') != std::string::npos) {
        CommonTool::createDirectoryIfNotExists(dir_path);
    }
    double lumi = options.lumi;

    vector<Hists> hists;
    vector<double> scales;
    vector<double> mc_numbers;
    vector<double> generate_numbers;
    for(int i=0;i<root_files.size();i++){
        Hists hist(root_files.at(i));
        hist.addHist("MCNumber",2,0,2);
        GetNumberOfEvents(origin_datasets.at(i),hist["MCNumber"]);
        double mc_number = hist["MCNumber"]->GetBinContent(1);
        double generate_number = hist["MCNumber"]->GetBinContent(2);
        double scale = 1;
        if(!fixed_scale){
            scale = xsections.at(i)*lumi*1.0/generate_number;
        }else{
            xsections.push_back(scale*1.0/lumi*generate_number);
        }
        scales.push_back(scale);
        hist.Scale(scale);
        hists.push_back(hist);
        mc_numbers.push_back(mc_number);
        generate_numbers.push_back(generate_number);
    }
    for(int i=1;i<hists.size();i++){
        hists[0].Add(hists[i]);
    }
    hists[0].Write((TString)output_file);
    cout << "Completed hadd of ROOT files into: " << output_file << ". Luminosity: " << lumi << " pb^-1" << endl;
    cout << "Corresponding cross-section, scale, event count, and generated count for each file:" << endl;
    cout << "+--------------------------------+------------+----------+---------------+----------------+" << endl;
    cout << "| Root File Name                 | Xsection   | Scale    | Event Count   | Generated Count|" << endl;
    cout << "+--------------------------------+------------+----------+---------------+----------------+" << endl;

    // 输出每个文件的信息
    for (size_t i = 0; i < hists.size(); i++)
    {
        cout << "| " << setw(30) << left << root_files.at(i)
             << " | " << setw(10) << left << xsections.at(i)
             << " | " << setw(8) << left << scales.at(i)
             << " | " << setw(13) << left << mc_numbers.at(i)
             << " | " << setw(15) << left << generate_numbers.at(i)
             << " |" << endl;
    }
    cout << "+--------------------------------+------------+----------+---------------+----------------+" << endl;

    return 0;
}

   