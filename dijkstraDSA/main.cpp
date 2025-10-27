#include <iostream>
#include "djikstra.h"


int main()
{
    Graph g(7);
    g.add_vertex_data(0, 'A');
    g.add_vertex_data(1, 'B');
    g.add_vertex_data(2, 'C');
    g.add_vertex_data(3, 'D');
    g.add_vertex_data(4, 'E');
    g.add_vertex_data(5, 'F');
    g.add_vertex_data(6, 'G');

    g.addEdge(3, 0, 4); // D - A, weight 4
    g.addEdge(3, 4, 2); // D - E, weight 2
    g.addEdge(0, 2, 3); // A - C, weight 3
    g.addEdge(0, 4, 4); // A - E, weight 4
    g.addEdge(4, 2, 4); // E - C, weight 4
    g.addEdge(4, 6, 5); // E - G, weight 5
    g.addEdge(2, 5, 5); // C - F, weight 5
    g.addEdge(2, 1, 2); // C - B, weight 2
    g.addEdge(1, 5, 2); // B - F, weight 2
    g.addEdge(6, 5, 5); // G - F, weight 5


    char startVertex = 'D';
    std::vector<int>distansesToAllvertexes = g.dijkstra(startVertex);
    std::vector<char> VertexData = g.getData();



    printf("Dijkstra's Algorithem from vertex D: \n");
    for(int i = 0; i < distansesToAllvertexes.size(); i++) {
        std::cout << "the shurtest distance from D to   "<< VertexData[i] << ": "<< distansesToAllvertexes[i] << std::endl;
    }
    return 0;
}
