#include <vector>
#include "graph.h"



int main() {


/*std::vector<char> vertexData = {'A', 'B', 'C', 'D'};
    std::vector<std::vector<int>>adjacencyMatrix = {
        {0,1,1,1},
        {1,0,1,0},
        {1,1,0,0},
        {1,0,0,0}
    };
    graph g;
   g.print_adjacency_matrix(adjacencyMatrix);
   g.print_connection(adjacencyMatrix, vertexData); */

    graph g(4);
    g.add_vertex_data(0, 'A');
    g.add_vertex_data(1, 'B');
    g.add_vertex_data(2, 'C');
    g.add_vertex_data(3, 'D');
    g.add_edge(0,1, 3);
    g.add_edge(0,2, 2);
    g.add_edge(3,0, 4);
    g.add_edge(2,1, 1);
    g.printgraph();




    return 0;
}