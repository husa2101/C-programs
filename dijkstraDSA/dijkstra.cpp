//
// Created by shahr on 2025-10-25.
//
 #include "djikstra.h"
#include <algorithm>
#include <limits>

Graph::Graph(int size): size(size) {
 adjList.resize(size, std::vector<int>(size, 0));
 Data.resize(size, ' ');
}

void Graph::addEdge(int u, int v, int weight) {
 if (u >= 0 && v >= 0 && u < size && v < size ) {
  adjList[u][v] = weight;
  adjList[v][u] = weight; // för undirected graph
 }
}

void Graph::add_vertex_data(int vertex, char c) {
  if (vertex < size && vertex >= 0) {
   Data[vertex] = c;
  }
}


int Graph::findIndex(const char &c) {
 auto it = std::find(Data.begin(), Data.end(), c);
 int startIbdex = std::distance(Data.begin(), it);
 return startIbdex;
}

int Graph::minDistance(std::vector<int> &distanse, std::vector<bool> &visited) {
 int min = std::numeric_limits<int>::max(), minIndex = -1;
 for (int i = 0; i < size; i++) {
  if(!visited[i] && distanse[i] <= min) {
   min = distanse[i];
   minIndex = i;
  }
 }
 return minIndex;
}


std::vector<int> Graph::dijkstra(char& c) {
 int startIndex = findIndex(c);
 std::vector<bool>visited(size, false);
 std::vector<int>distanses(size);
 std::fill(distanses.begin(), distanses.end(), std::numeric_limits<int>::max());
 distanses[startIndex] = 0;


for (int i = 0; i < size; i++) {
  int u = minDistance(distanses, visited);
  if (u == -1) break;

  visited[u] = true;
  for (int v = 0; v < size; v++) {
   if (!visited[v] && adjList[u][v] != 0 && distanses[u] != std::numeric_limits<int>::max()) {


      int newDist = distanses[u] + adjList[u][v];
    if (newDist < distanses[v]) {
     distanses[v] = newDist;
    }
   }
  }
 }
 return distanses;
}

const std::vector<char> &Graph::getData() const {
 return Data;
}



void Graph::print() {
 for (int i = 0; i < size; ++i) {
  for (int j = 0; j < size; ++j) {
   std::cout << adjList[i][j] << " ";
  }
  std::cout << std::endl;
 }
}


