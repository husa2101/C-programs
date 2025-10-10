    //
    // Created by shahr on 2025-10-06.
    //
    #include "graph.h"
    #include <iostream>
#include <algorithm>
#include <stack>

    graph::graph(int size): size(size) {
    adjacencyMatrix.resize(size, std::vector<int>(size, 0));
    data.resize(size, ' ');
}

void graph::addEdge(int u, int v) {
    if(u >= 0 && v >= 0 && u < size && v < size) {
        adjacencyMatrix[u][v] = 1;
        adjacencyMatrix[v][u] = 1;
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

void graph::dfs_visit(int v, std::vector<bool>& visited) {
visited[v] = true;
        std::cout << data[v] << "  ";
        for (int i = 0; i < size; i++) {
            if(adjacencyMatrix[v][i] == 1 && !visited[i]) {
                dfs_visit(i, visited);
            }
        }

}

void graph::dfs(char start_vertex) {
    std::vector<bool> visited(size, false);
        auto it = std::find(data.begin(), data.end(), start_vertex);
        if(it == data.end()) {
            std::cerr << "Vertex " << start_vertex << " does not exist" << std::endl;
        }

        //This is iterator arithmetic.Subtracting two iterators gives you the distance(number of elements) between them — basically
        //the index of it in the vector or we can use std:.distance
    //int startIndex = it - data.begin();
        int start_index = std::distance(data.begin(), it);

        dfs_visit(start_index, visited);
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