#pragma once
#include<vector>
#include"reader.h"
#include<iostream>

void dfs(int S, std::vector<bool>& visited, std::vector<std::vector<double>> matrix);
bool dfsOfGraph(adjacency_list_t adj, std::vector<std::vector<double>> matrix);
int allVisited(std::vector<bool>& visited);