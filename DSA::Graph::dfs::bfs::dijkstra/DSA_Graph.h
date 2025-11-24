//
// Created by shahr on 2025-11-01.
//

#ifndef DSA_GRAPH_H
#define DSA_GRAPH_H

#include <vector>
#include <fstream>


class DSA_GRAPH {

    struct guidInfo {
        char c;
        std::string description;
    };

    struct Vertex_ID {
        int n;
        char c;
        std::string description;
    };

    struct VertexEdge {
        double x, y;
        double weight;
        std::string description;
    };

    std::vector<std::vector<double>>adjacencyMatrix;
    std::vector<std::string>data;
    int size;

    public:
    DSA_GRAPH(int);
    void read();
    void analys(const std::string &);
    guidInfo meta_data_info(const std::string &);
    Vertex_ID analys_MetaData_for_vertexId(const std::string &);
    VertexEdge analys_MetaData_for_edge(const std::string &);
    void print();
    void dfs(const std::string&);
    void dfsVisited(const int&, std::vector<bool>&);
    std::string trim(const std::string&);
    void bfs(std::string&);
    std::vector<double> dijkstra(std::string&);
    int minDistance(std::vector<double>&, std::vector<bool>&);
    std::vector<std::string>getData();

};

#endif //DSA_GRAPH_H
