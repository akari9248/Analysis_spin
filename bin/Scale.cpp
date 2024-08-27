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
              << " --scale <scale> --root_file <path_to_root_file> --output_file <output_file>\n"
              << "\n"
              << "Arguments:\n"
              << "  --scale <lumi_val>         Integrated luminosity value. Default is 1.\n"
              << "  --root_file <path>        Path to the root file to be scaled.\n"
              << "  --output_file <path>      Path to the output file.\n"
              << "\n"
              << std::endl;
}

int main(int argc, char *argv[])
{
    CommonTool::Options options = CommonTool::parseArguments(argc, argv,false);
    if(options.printhelp) {print_help(argv);return 0;};
    double scale = options.scale;
    Hists hist(options.root_file);
    auto output_file = options.output_file;
    std::string dir_path = output_file.substr(0, output_file.find_last_of('/'));
    if ( output_file.find_last_of('/') != std::string::npos) {
        CommonTool::createDirectoryIfNotExists(dir_path);
    }
    hist.Scale(scale,true);
    hist.Write((TString)output_file);
    cout << "Completed hadd of ROOT files into: " << output_file << ". scale: " << scale << " " << endl;
    return 0;
}

   