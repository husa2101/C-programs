//
// Created by hussein on 2023-04-16.
//

#ifndef UNTITLED_SORTSALGORITHM_H
#define UNTITLED_SORTSALGORITHM_H


#include<iostream>
#include<vector>
#include<algorithm>


void Quicksort(std::vector<int> &v, int start, int end, bool);
int Partition(std::vector<int> &v, int start, int end,  bool);
int partitionMedium(std::vector<int> &v, int start, int end);
std::vector<int> selectionSort(std::vector<int>&);
std::vector<int> insertionSort(std::vector<int>&);



#endif //UNTITLED_SORTSALGORITHM_H
