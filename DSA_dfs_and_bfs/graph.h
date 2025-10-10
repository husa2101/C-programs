//
// Created by shahr on 2025-10-06.
//

#ifndef GRAPH_H
#define GRAPH_H
#include <vector>

class graph {
public:
    /*void print_adjacency_matrix(std::vector<std::vector<int>> &adjacency_matrix);
    void print_connection(std::vector<std::vector<int>> &adjacency_matrix, std::vector<char> &connection);
*/
    graph(int size);
    void addEdge(int u, int v);
    void add_vertex_data(int v, char data);
    void printgraph();
    void dfs_visit(int, std::vector<bool>&);
    void dfs(char );
    void bfs(char);


private:
    std::vector<char> data;
    std::vector<std::vector<int>> adjacencyMatrix;
    int size;
};
#endif //GRAPH_H
