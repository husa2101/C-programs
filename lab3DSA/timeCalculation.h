//
// Created by shahr on 2023-05-22.
//

#ifndef LAB3STRUCT_TIMECALCULATION_H
#define LAB3STRUCT_TIMECALCULATION_H
#include<vector>
#include<string>
#include "algorithm.h"
#include "print.h"
#include<chrono>
#include<fstream>
// function that take a function as argument and the value to start generating prime numbers
void searchTime(std::vector<int>(*primeFunc)(int size),int start, int end , int increment );

//take a function as agrument + vector with primes + the textfile to store
void timecalculation(void(*searchFunc)(std::vector<int>&, int), std::vector<int> vec, std::string filename);

// take a function to calculate + vector of primes + textfile in order to calculate the time.
float time(void(*func)(std::vector<int>&, int), std::vector<int>&, std::string );

#endif //LAB3STRUCT_TIMECALCULATION_H
