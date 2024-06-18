#pragma once
#include <iostream>
#include <vector>
#include <string>
#include <sys/stat.h>
#include <sys/types.h>
#include "SaveData.h"
#include <getopt.h>
#include <cstdlib>
class CommonTool {
    public:
  template <typename T>
  std::vector<T> static concatenate(const std::vector<T> &v1,
                             const std::vector<T> &v2) {
    std::vector<T> result;
    result.reserve(v1.size() + v2.size()); // 预先分配足够的空间以提高效率
    result.insert(result.end(), v1.begin(),
                  v1.end()); // 插入第一个 vector 的所有元素
    result.insert(result.end(), v2.begin(),
                  v2.end()); // 插入第二个 vector 的所有元素
    return result;
  }
  template <typename T>
    static void concatenateToFirstVect(std::vector<T>& v1, const std::vector<T>& v2) {
            v1.insert(v1.end(), v2.begin(), v2.end());
  }
  // Check if a directory exists, and create it if it doesn't
    static void createDirectoryIfNotExists(const std::string& path) {
        struct stat info;
        if (stat(path.c_str(), &info) != 0) {
            // Directory does not exist, create it
            if (mkdir(path.c_str(), 0777) != 0) {
                std::cerr << "Error: Unable to create directory " << path << std::endl;
                std::exit(1);
            }
        } else if (!(info.st_mode & S_IFDIR)) {
            std::cerr << "Error: " << path << " is not a directory." << std::endl;
            std::exit(1);
        }
    }
    struct Options
    {
        int chunki = 0;
        int nparts = 1;    // Default value for nparts
        int nchunks = 100; // Default value for nchunks
        std::string inputFolder;
        std::string outputFolder;
        int jinit_ptlow = -1;
        int jinit_pthigh = -1;
        int j0_ptlow = -1;
        int j0_pthigh = -1;
        int j2_ptlow = -1;
        int j2_pthigh = -1;
        int spin = 0;      // Default value for spin
        int OneGeVCut = 0; // Default value for OneGeVCut
    };

    static Options parseArguments(int argc, char *argv[])
    {
        Options options;
        int opt;

        struct option long_options[] = {
            {"jinit_ptlow", required_argument, 0, 0},
            {"jinit_pthigh", required_argument, 0, 0},
            {"j0_ptlow", required_argument, 0, 0},
            {"j0_pthigh", required_argument, 0, 0},
            {"j2_ptlow", required_argument, 0, 0},
            {"j2_pthigh", required_argument, 0, 0},
            {"spin", required_argument, 0, 0},
            {"OneGeVCut", required_argument, 0, 0},
            {0, 0, 0, 0}};

        int long_index = 0;
        while ((opt = getopt_long(argc, argv, "i:I:O:n:k:", long_options, &long_index)) != -1)
        {
            switch (opt)
            {
            case 'i':
                options.chunki = std::atoi(optarg); // Convert argument to integer
                break;
            case 'I':
                options.inputFolder = optarg; // Get input folder path
                break;
            case 'O':
                options.outputFolder = optarg; // Get output folder path
                break;
            case 'n':
                options.nparts = std::atoi(optarg); // Convert argument to integer
                break;
            case 'k':
                options.nchunks = std::atoi(optarg); // Convert argument to integer
                break;
            case 0: // Handle long options
                if (strcmp(long_options[long_index].name, "jinit_ptlow") == 0)
                {
                    options.jinit_ptlow = std::atoi(optarg);
                }
                else if (strcmp(long_options[long_index].name, "jinit_pthigh") == 0)
                {
                    options.jinit_pthigh = std::atoi(optarg);
                }
                else if (strcmp(long_options[long_index].name, "j0_ptlow") == 0)
                {
                    options.j0_ptlow = std::atoi(optarg);
                }
                else if (strcmp(long_options[long_index].name, "j0_pthigh") == 0)
                {
                    options.j0_pthigh = std::atoi(optarg);
                }
                else if (strcmp(long_options[long_index].name, "j2_ptlow") == 0)
                {
                    options.j2_ptlow = std::atoi(optarg);
                }
                else if (strcmp(long_options[long_index].name, "j2_pthigh") == 0)
                {
                    options.j2_pthigh = std::atoi(optarg);
                }
                else if (strcmp(long_options[long_index].name, "spin") == 0)
                {
                    options.spin = std::atoi(optarg);
                }
                else if (strcmp(long_options[long_index].name, "OneGeVCut") == 0)
                {
                    options.OneGeVCut = std::atoi(optarg);
                }
                break;
            default:
                std::cerr << "Usage: " << argv[0] << " [-i inputInt] [-I inputFolder] [-O outputFolder] "
                          << "[-n nparts] [-k nchunks] [--jinit_ptlow val] [--jinit_pthigh val] "
                          << "[--j0_ptlow val] [--j0_pthigh val] [--j2_ptlow val] [--j2_pthigh val] "
                          << "[--spin val] [--OneGeVCut val]" << std::endl;
                std::exit(1);
            }
        }

        if (options.inputFolder.empty() || options.outputFolder.empty())
        {
            std::cerr << "Input and output folders must be specified." << std::endl;
            std::exit(1);
        }

        // Check and create input and output folders
        createDirectoryIfNotExists(options.inputFolder);
        createDirectoryIfNotExists(options.outputFolder);
        return options;
    }
    // Process and save data according to the options
    template <typename Analyzer>
    static void processAndSaveData(const Options& options, Analyzer& analyzer) {
      if(options.chunki>=options.nchunks) {return;}
        for (int part = 0; part < options.nparts; part++) {
            double begin = (options.chunki * options.nparts + part) * 1.0 / (options.nchunks * options.nparts);
            double events_frac = 1.0 / (options.nchunks * options.nparts);
            analyzer.treeEvents.clear();
            analyzer.run_frac(events_frac, begin);
            SaveData::writeTreeEventsToRoot(
                analyzer.treeEvents,
                options.outputFolder + "/Chunk" + std::to_string(options.chunki) + "_Part" + std::to_string(part) + ".root", true);
        }
    }

};