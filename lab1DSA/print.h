#pragma once
#include"reader.h"
#include<iostream>
void print(adjacency_list_t test);


void printSPT(std::vector<std::pair<double, bool>>& adj, int start, int dest, adjacency_list_t& list);
