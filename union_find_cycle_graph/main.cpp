#include <cstdio>
#include <iostream>
#include <ostream>
#include <vector>
#include "graph.h"
#include <stdio.h>



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

    graph g(7);
    g.add_vertex_data(0, 'A');
    g.add_vertex_data(1, 'B');
    g.add_vertex_data(2, 'C');
    g.add_vertex_data(3, 'D');
    g.add_vertex_data(4, 'E');
    g.add_vertex_data(5, 'F');
    g.add_vertex_data(6, 'G');

    /*g.addEdge(3, 0); // D - A
    g.addEdge(0, 2); // A - C
    g.addEdge(0, 3); // A - D
    g.addEdge(0, 4); // A - E
    g.addEdge(4, 2); // E - C
    g.addEdge(2, 5); // C - F
    g.addEdge(2, 1); // C - B
    g.addEdge(2, 6); // C - G
    g.addEdge(1, 5); // B - F*/

    g.addEdge(1, 0); // B - A
    g.addEdge(0, 3); // A - D
    g.addEdge(0, 2); // A - C
    g.addEdge(2, 3); // C - D
    g.addEdge(3, 4); // D - E
    g.addEdge(3, 5); // D - F
    g.addEdge(3, 6); // D - G
    g.addEdge(4, 5); // E - F

    g.printgraph();
   if(g.isCyclic()) {
       std::cout << "Cycle detected" << std::endl;
   }

/*printf("Depth First Search starting from vertex D \n");
    g.dfs('D');
    printf("\nBepth First Search starting from vertex D \n");
    g.bfs('D');*/



    return 0;
}