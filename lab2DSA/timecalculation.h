//
// Created by hussein on 2023-04-18.
//

#ifndef UNTITLED_TIMECALCULATION_H
#define UNTITLED_TIMECALCULATION_H
#include <iostream>
#include <vector>
#include <algorithm>
#include <chrono>
#include <random>
#include "sortsAlgorithm.h"

void sortTime(int start, int end, int increment, std::vector<int>(*funk)(int size));

// och sort functionen tar en parameter som reference.
void timeCalculate(void (*sort_funk)(std::vector<int>&), std::vector<int>, std::string);
double time(void(*funck)(std::vector<int>&), std::vector<int>);





#endif //UNTITLED_TIMECALCULATION_H
