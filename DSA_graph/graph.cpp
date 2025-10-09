    //
    // Created by shahr on 2025-10-06.
    //
    #include "graph.h"
    #include <iostream>

graph::graph(int size): size(size) {
    adjacencyMatrix.resize(size, std::vector<int>(size, 0));
    data.resize(size, ' ');
}

void graph::add_edge(int u, int v, int weight) {
    if(u >= 0 && v >= 0 && u < size && v < size) {
        adjacencyMatrix[u][v] = weight;
        //adjacencyMatrix[v][u] = 1;
    }
}

void graph::add_vertex_data(int vertex, char c) {
    if(vertex < size && vertex >= 0) {
        data[vertex] = c;
    }
}

void graph::printgraph() {
    std::cout << "Adjacency matrix:" << std::endl;
    for(int i = 0; i < size; i++) {
        for(int j = 0; j < size; j++) {
            std::cout << adjacencyMatrix[i][j] << " ";
        }
        std::cout << std::endl;
    }
    for(int i = 0; i < size; i++) {
        std::cout <<"Vertex_data " << i <<": "<< data[i] << std::endl;
    }
}




/*
    void graph::print_adjacency_matrix(std::vector<std::vector<int>> &adjacency_matrix) {
        for(int i = 0; i < adjacency_matrix.size(); ++i) {
            for(int j = 0; j < adjacency_matrix.size(); ++j) {
                std::cout << adjacency_matrix[i][j] << " ";
            }
            std::cout << "\n";
        }
    }
    void graph::print_connection(std::vector<std::vector<int>> &adjacency_matrix, std::vector<char> &connection) {
        for(int i = 0; i < connection.size(); ++i) {
            std::cout << connection[i] << " : ";
            for (int j = 0; j < adjacency_matrix.size(); ++j) {
                if (adjacency_matrix[i][j]) {
                    std::cout << connection[j] << " ";
                }
            }
            std::cout << "\n";
        }
    }*/