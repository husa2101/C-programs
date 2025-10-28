#include <iostream>
#include <queue>
#include<cstdlib>
#include<ctime>
#include<algorithm>
#include "sortsAlgorithm.h"
#include"dataGenerator.h"
#include <chrono>
#include"timecalculation.h"


int main() {

    auto start = 0;
    auto end = 10000000;
    auto increment =500000 ;


    auto randomValue = [](int N){ std::vector<int> randG= randGenerator(N); return randG;};
    auto increasing = [](int N){std::vector<int> increas = monotonicIncreasing(N); return increas;};
    auto decreasing = [](int N){std::vector<int> decreas = monotonicDecreasing(N); return decreas;};
    auto constvalue = [](int N){std::vector<int> constant = constValue(N); return constant;};

    sortTime(start, end, increment, decreasing);

    return 0;
}

