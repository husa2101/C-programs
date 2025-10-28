#include <iostream>
#include"reader.h"
#include"matrix.h"
#include"dijkstra.h"
#include "print.h"
#include"dsf.h"
#include"bfs.h"
using namespace std;

typedef pair<int, int> iPair;

int main() {

    adjacency_list_t test = parse_file("Text.txt");
    vector<vector<double>> matrix = convertToMatrix(test); // matrix


    bool dfs= dfsOfGraph(test, matrix);  // test if the graph is coneccted;

    if (!dfs) {
        std::cout << "the graph is not linked" << std::endl;
    }
    else
    {
        std::cout << "all the node is coneccted" << std::endl;
    }

    std::cout << "-------------------------------------------" << "\n";

    bool Bfs = bfs(0, test);
    if (!Bfs)
    {
        std::cout << "the graph is not valid" << std::endl;
    }
    else {
        std::cout << " the graph is valid" << std::endl;
    }

   dijkstra(test, 24, 37);
   
    //print(test);
    





    
    return 0;
}