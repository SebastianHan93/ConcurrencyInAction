#include <iostream>
#include "ParallelAccumulate.h"

int main() {
    clock_t start, finish;
    double  duration;

    std::vector<int> num(100000000,5);

    start = clock();
    int parallelRet =  parallel_accumulate(num.begin(),num.end(), 0);
    finish = clock();
    duration = (double)(finish - start) / CLOCKS_PER_SEC;

    std::cout << "duration:" << duration <<std::endl;
    std::cout << parallelRet <<std::endl;
    std::cout << "-------------------------------" <<std::endl;

    std::vector<int> num1(100000000,5);
    start = clock();
    int singleRet=std::accumulate(num1.begin(),num1.end(),0);
    finish = clock();
    duration = (double)(finish - start) / CLOCKS_PER_SEC;
    std::cout << "duration:" << duration <<std::endl;
    std::cout << singleRet <<std::endl;
    return 0;
}
