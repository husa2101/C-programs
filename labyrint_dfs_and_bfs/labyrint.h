//
// Created by shahr on 2025-08-18.
//

#ifndef LABYRINT_MAZE_H
#define LABYRINT_MAZE_H
#include <iostream>
#include <iomanip>
#include <vector>
#include <stack>
#include <queue>
#include <map>
#include <algorithm>
#include <ctime>
#include <iterator>
#include<random>
class Maze {

private:
    struct Node {
        Node(int , int);
        int x, y;
        bool visited;
        bool left, right, bottom, top;
    };
    struct position{
        size_t x, y;
    };

    size_t maze_size;
    position start, end;




public:
    Maze();

    std::vector<std::vector<Node>>grid;
    std::vector<Node*>unvisitedNodes(Node& node);
    void dfs(Node& , Node& );
    std::vector<Maze::Node*> bfs(Node& startNode, Node& endNode);
    void removWall(Node&, Node&);
    void displaybfs(const std::vector<Node*>& path);

    void displaydfs();



};

#endif //LABYRINT_MAZE_H
