#include "../include/MetaDataManager.h"
#include <iostream>

int main(int argc, char** argv) {
    if (argc != 2) {
        std::cerr << "Usage: " << argv[0] << " <root_file>" << std::endl;
        return 1;
    }

    const char* fileName = argv[1];
    
    MetaDataManager newManager;
    newManager.LoadFromRootFile(fileName);
    std::cout << newManager.GetMetaDataAsString() << std::endl;

    return 0;
}