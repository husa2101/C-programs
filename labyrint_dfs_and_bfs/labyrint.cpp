//
// Created by shahr on 2025-08-18.
//
#include "labyrint.h"

/*
 * maze constructor
 */
Maze::Maze(): maze_size(11) {
    start = {1 ,0};
    end = { maze_size -1, maze_size - 2};
    for (int i = 0; i < maze_size; ++i) {
    std::vector<Node>NodeContainer;
        for (int j = 0; j < maze_size; ++j) {
            Node cell = Node(i, j);
            NodeContainer.push_back(cell);
        }
    grid.push_back(NodeContainer);
    }

}

/*
 * node constructor
 */
Maze::Node::Node(int row, int col): visited(false), x(row), y(col),
left(true), right(true), bottom(true), top(true){}

std::vector<Maze::Node*> Maze::unvisitedNodes(Node& node) {
    std::vector<Node*> result;

    int row = node.x;
    int col = node.y;

    if (row > 0 && !grid[row - 1][col].visited)result.push_back(&grid[row-1][col]);

    if (row < grid.size()-1 && !grid[row + 1][col].visited) result.push_back(&grid[row+1][col]);

    if (col > 0 && !grid[row][col - 1].visited)result.push_back(&grid[row][col-1]);

    if (col < grid.size() -1 && !grid[row][col + 1].visited)result.push_back(&grid[row][col+1]);



    return result;
}

void Maze::removWall(Maze::Node &a, Maze::Node &b) {
    if (a.x == b.x){
        if (a.y < b.y){
            a.right = false;
            b.left = false;
        }else{
            a.left = false;
            b.right = false;
        }
    }else if(a.y == b.y){
        if(a.x < b.x){
            a.bottom = false;
            b.top = false;
        }else{
            a.top = false;
            b.bottom = false;
        }
    }
}

/*
 * Depth first Search is a recursive algorithm for searching all the vertices of a
 * graph or tree data structure bout in our exemple stop visiting until visit the end cell
 */
void Maze::dfs(Node& startNode, Node& endNode) {
    std::srand(std::time({})); // use current time as seed for random generator
    std::stack<Node*> s;
    s.push(&startNode);


    while (!s.empty()) {
        Node* current = s.top();
        current->visited = true;

        // Get neighbors
        auto neighbors = unvisitedNodes(*current);

        if(!neighbors.empty()){
        Node* next = neighbors[rand() % neighbors.size()];

            removWall(*current, *next);
            if (next->x == endNode.x && next->y == endNode.y) break;
            s.push(next);

        }else{
            s.pop();
        }

    }
}


/*
 * display function for BFS algorithm
 */
void Maze::displaybfs(const std::vector<Node*>& path) {
    for (size_t i = 0; i < maze_size; ++i) {
        for (size_t j = 0; j < maze_size; ++j) {
            Node& cell = grid[i][j];
            if (i == start.x && j == start.y) {
                std::cout << " S ";
            }
            else if (i == end.x && j == end.y) {
                std::cout << " E ";
            }
            else if (std::find(path.begin(), path.end(), &cell) != path.end()) {
                std::cout << " . ";  // mark solution path
            }
            else {
                std::cout << " # ";
            }
        }
        std::cout << "\n";
    }
}


/*
 * function that display dfs process of going through a maze from start to end.
 */
void Maze::displaydfs() {
    for (size_t i = 0; i < maze_size; ++i) {
        for (size_t j = 0; j < maze_size; ++j) {
            if (i == start.x && j == start.y) {
                std::cout << " S ";
            }
            else if (i == end.x && j == end.y) {
                std::cout << " E ";
            }
            else if (grid[i][j].visited ){
                std::cout << " . ";  // empty space for visited
            }
            else {
                std::cout << " # ";  // wall
            }
        }
        std::cout << "\n";
    }
}


/*
 * the BFS general concept is to visit cells from start cell, then all its neighbors before
 * proceeding further, thus finding the shortest path to the end cell.
 */
std::vector<Maze::Node*> Maze::bfs(Node& startNode, Node& endNode) {
    std::queue<Node*> q;
    std::map<Node*, Node*> parent;

    q.push(&startNode);
    parent[&startNode] = nullptr;
    startNode.visited = true;

    while (!q.empty()) {
        Node* current = q.front();
        q.pop();

        if (current == &endNode) break; // found target

        auto neighbors = unvisitedNodes(*current);

        // need a random engine
        static std::random_device rd;
        static std::mt19937 g(rd());

// shuffle using the engine
        std::shuffle(neighbors.begin(), neighbors.end(), g);

        for (auto next : neighbors) {
            if (!next->visited) {
                next->visited = true;
                parent[next] = current;
                q.push(next);
            }
        }
    }

    // reconstruct path
    std::vector<Node*> path;
    Node* cur = &endNode;
    while (cur) {
        path.push_back(cur);
        cur = parent[cur];
    }
    std::reverse(path.begin(), path.end());
    return path;
}

