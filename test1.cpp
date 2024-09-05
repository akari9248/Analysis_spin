#include "include/common_tool.h"


int main(){
    int nthreads = 4;
    int begin = 0;
    int end = 100;

    CommonTool::parallel_for(nthreads, begin, end, [](int i) {
        sleep(10);
        std::cout << "Processing iteration " << i << std::endl;
        sleep(10);
    });
    return 0;
}