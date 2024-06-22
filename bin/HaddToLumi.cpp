#include <iostream>
#include <iomanip>
#include <vector>
#include <string>
#include "../include/Hists.h"
#include "../include/common_tool.h"
using namespace std;
void print_help(char *argv[])
{
    std::cerr << "Usage: " << argv[0]
              << " --lumi <lumi_val> --root_file <path_to_root_file> --xsection_file <path_to_xsection_file> --output_file <output_file>\n"
              << "\n"
              << "Arguments:\n"
              << "  --lumi <lumi_val>         Integrated luminosity value. Default is 1.\n"
              << "  --root_file <path>        Path to a text file containing a list of ROOT files (one per line).\n"
              << "  --xsection_file <path>    Path to a text file containing cross-sections. The second column of this file should\n"
              << "                            correspond to the cross-sections of the ROOT files listed in the root_file.\n"
              << "  --output_file <path>      Path to the output file.\n"
              << "\n"
              << "All arguments are required except for --lumi, which defaults to 1 if not specified.\n"
              << std::endl;
}
int main(int argc, char *argv[])
{
    CommonTool::Options options = CommonTool::parseArguments(argc, argv,false);
    if(options.printhelp) {print_help(argv);return 0;};
    auto root_files = CommonTool::readFirstColumn(options.root_file);
    auto xsections = CommonTool::readSecondColumn(options.xsection_file);
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
        double mc_number = hist["MC_number"]->GetBinContent(2);
        double generate_number = hist["MC_number"]->GetBinContent(1);
        double scale = xsections.at(i)*lumi*1.0/mc_number;
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

   