//
// Created by shahr on 2025-11-01.
//

#include "DSA_Graph.h"

#include <iostream>
#include <sstream>
#include <vector>
#include <algorithm>
#include <queue>
#include<limits>

DSA_GRAPH::DSA_GRAPH(int size): size(size) {
    adjacencyMatrix.resize(size, std::vector <double>(size, 0));
    data.resize(size, " ");
    read();
}


DSA_GRAPH::guidInfo DSA_GRAPH::meta_data_info(const std::string & line) {

    guidInfo g;
    std::stringstream ss(line);
     if(!line.empty()) {
         ss >> g.c;
         std::getline(ss, g.description);
     }else {
         std::cerr << "Empty line" << std::endl;
     }

    return g;
}


DSA_GRAPH::Vertex_ID DSA_GRAPH::analys_MetaData_for_vertexId(const std::string & line) {

    Vertex_ID v;
    std::stringstream ss(line);
    ss >> v.c >> v.n;
    std::getline(ss, v.description);



    return v;
}

DSA_GRAPH::VertexEdge DSA_GRAPH::analys_MetaData_for_edge(const std::string &line) {

    VertexEdge v;
    std::stringstream iss(line);

    if(!line.empty()) {
        iss >> v.x >> v.y >> v.weight;
        std::getline(iss, v.description);
    }

    return v;
}



void DSA_GRAPH::analys( const std::string & line) {
    std::vector<guidInfo>guidProject;


    if(!line.empty() && line[0] == '#') {
    auto t =meta_data_info(line);

       guidProject.push_back(t);
        for (auto it: guidProject) {
            std::cout << it.c << " " << it.description << std::endl;
        }
    }else if (line[0] == 'M') {
        // Vertex definition
        auto v = analys_MetaData_for_vertexId(line);
        if (v.n >= 0 && v.n < size) {
            v.description  = trim(v.description);
            data[v.n] = v.description;
        }
    }
    else if (isdigit(line[0])) {
        // Edge definition
        auto e = analys_MetaData_for_edge(line);
        if(e.x >= 0 && e.y >= 0 && e.x < size && e.y < size) {
            adjacencyMatrix[e.x][e.y] = e.weight; // store weight
            adjacencyMatrix[e.y][e.x] = e.weight; // store weight
        }

    }
}



void DSA_GRAPH::read() {

    std::ifstream input;
    std::ofstream output;
    input.open("indata.txt");
    output.open("output.txt");

    if (!input.is_open() || !output.is_open()) {
        std::cerr << "Error opening files" << std::endl;
    }
    std::string line;

    while(std::getline(input, line)) {
        analys(line);
    }
}

void DSA_GRAPH::print() {
    std::cout << "\n--- Graph Summary ---\n";

    // Print all vertices (IDs and names)
    for (int i = 0; i < data.size(); i++) {
        if (!data[i].empty()) {
            std::cout << "[" << i << "] " << data[i] << "\n";
        }
    }

    std::cout << "\n--- Adjacency (edges) ---\n";

    // Print all edges with non-zero weight
    for (int i = 0; i < adjacencyMatrix.size(); i++) {
        for (int j = 0; j < adjacencyMatrix[i].size(); j++) {
            if (adjacencyMatrix[i][j] != 0) {
                std::string from = (i < data.size()) ? data[i] : "it is out of bound";
                std::string to   = (j < data.size()) ? data[j] : "it is out of bound";
                std::cout << from << " -> " << to
                          << " : " << adjacencyMatrix[i][j] << "\n";
            }
        }
    }

    std::cout << std::endl;
}


void DSA_GRAPH::dfsVisited(const int &StartIndex, std::vector<bool>& visited) {
    visited[StartIndex] = true;
    //std::cout <<StartIndex <<":    "<<data[StartIndex] << "\n";
    for (int i = 0; i < size; i++) {
        if(adjacencyMatrix[StartIndex][i] != 0 && visited[i] != true) {
            dfsVisited(i, visited);
        }
    }

}


void DSA_GRAPH::dfs(const std::string &startVertex) {
    std::vector<bool> visited(size, false);
   auto iter = std::find(data.begin(), data.end(), startVertex);
    if (iter == data.end()) {
        std::cerr << "Vertex " << startVertex << " not found" << std::endl;
        return;
    }

    int startIndex = std::distance(data.begin(), iter);
    dfsVisited(startIndex, visited);

    bool allVisited = true;
    for (bool v : visited) {
        if (!v) { allVisited = false; break; }
    }

    if (allVisited) std::cout << "(All nodes are connected eccording to DFS).\n";
    else std::cout << "Some nodes are not connected.\n";


}

void DSA_GRAPH::bfs(std::string &startVertex) {
    std::vector<bool> visited(size, false);
    auto iter = std::find(data.begin(), data.end(), startVertex);
    if(iter == data.end()) {
        std::cout << "Vertex " << startVertex << " not found" << std::endl;
        return;
    }
    int startIndex = std::distance(data.begin(), iter);
    std::queue<int> q;
    q.push(startIndex);
    visited[startIndex] = true;

    while (!q.empty()) {
        int currentIndex = q.front();
        //std::cout <<currentIndex << ": " << data[currentIndex] << std::endl;
        q.pop();
        for (int i = 0; i < size; i++) {
            if(adjacencyMatrix[currentIndex][i] != 0 && visited[i] != true) {
                q.push(i);
                visited[i] = true;

            }
        }

    }

    bool allvisited = true;
    for (auto v: visited) {
        if(!v) {
           allvisited = false;
        }
    }
    if (allvisited == true) std::cout << "(All nodes are connected eccording to the BFS)";
    else std::cout << "Some nodes are not connected.\n";

}








int DSA_GRAPH::minDistance(std::vector<double> &distance, std::vector<bool> &visited) {
    double minVal = std::numeric_limits<double>::max();
    int minIndex = -1;

    for (int j = 0; j < size; ++j) {
        if (!visited[j] && distance[j] <= minVal) {
            minVal = distance[j];
            minIndex = j;
        }
    }
    return minIndex;
}

std::vector<double> DSA_GRAPH::dijkstra(std::string &startVertex) {
    auto iter = std::find(data.begin(), data.end(), startVertex);
    int startIndex = std::distance(data.begin(), iter);

    if (iter == data.end()) {
        std::cerr << "Vertex " << startVertex << " not found\n";
        return {};
    }

    std::vector<bool> visited(size, false);
    std::vector<double> dist(size, std::numeric_limits<double>::max());
    dist[startIndex] = 0.0;

    for (int i = 0; i < size; ++i) {

        int currentIndex = minDistance(dist, visited);
        if (currentIndex == -1) break;

        visited[currentIndex] = true;

        for (int v = 0; v < size; ++v) {
            if (!visited[v] && adjacencyMatrix[currentIndex][v] != 0 &&
                dist[currentIndex] != std::numeric_limits<double>::max()) {

                double newDist = dist[currentIndex] + adjacencyMatrix[currentIndex][v];
                if (newDist < dist[v]) {
                    dist[v] = newDist;
                }
                }
        }
    }

    return dist;
}




std::string DSA_GRAPH::trim(const std::string& s) {
    size_t start = s.find_first_not_of(" \t\r\n");
    size_t end = s.find_last_not_of(" \t\r\n");
    if(start == std::string::npos) return"";
    return s.substr(start, end - start + 1);
}


std::vector<std::string> DSA_GRAPH::getData() {
    return data;
}
