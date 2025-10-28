//
// Created by hussein on 2023-04-16.
//
#include "dataGenerator.h"


std::vector<int> randGenerator(int randValues) {
std::srand(time(NULL)); // use current time as seed for random generator
    std::vector<int>data;
    for (int i= 0; i < randValues; i++) {
    data.push_back(rand());
    }
    return data;
}

std::vector<int> monotonicIncreasing(int N) {
    std::vector<int>monotonicIncreasing;
    monotonicIncreasing.push_back(0);
    srand(time(NULL));
    for(int i = 0; i < N; i++) {
        int randomValue = rand() % 10;
        int previousValue = monotonicIncreasing.back(); // get the previous value in the vector.
        monotonicIncreasing.push_back(previousValue + randomValue); // Generate a new value that's larger than the previous one.
    }
    return monotonicIncreasing;
}

std::vector<int> monotonicDecreasing(int N) {
    std::vector<int>data;
    data.push_back(INT_MAX); // start with the maximum value possible value;
    srand(time(NULL));

    for (int i = 1; i < N; i++) {
        int randomValue = rand() % 10;
        int previousValue = data.back(); // get the previous value in the vector.
        data.push_back(previousValue - randomValue); // generate a new value that is smaller than the prevoius value.
    }
    return data;
}

std::vector<int> constValue(int N) {
    srand(time(NULL));
    int value = rand() % 100;
    std::vector<int> data;
    for (int i = 0; i < N; i++) {
    data.push_back(value);
    }
    return data;
}
