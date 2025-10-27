//
// Created by shahr on 2025-10-25.
//

#ifndef DJIKSTRA_H
#define DJIKSTRA_H
#include <vector>
#include <iostream>


class Graph {
    public:
    Graph(int size);
    void addEdge(int u, int v, int weight);
    void add_vertex_data(int v, char data);
    std::vector<int> dijkstra(char&);

    int findIndex(const char& c);
    int minDistance(std::vector<int>&, std::vector<bool>&);
    void print();
    const std::vector<char>& getData() const;

private:
    int size;
    std::vector<std::vector<int>> adjList;
    std::vector<char> Data;

};
#endif //DJIKSTRA_H
