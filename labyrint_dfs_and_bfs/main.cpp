#include "labyrint.h"


/*
 * this program it is a Labyrint with a start och end cell, the mean objective of writing this program
 * is to learn about the DFS(depth first search) and BFS (Breadth-First Search) and to understand the
 * difference between them.
 */

int main() {
    Maze maze;

    maze.dfs(maze.grid[1][0], maze.grid[11-1][11-2]);
    //auto path = maze.bfs(maze.grid[1][0], maze.grid[11-1][11-2]);

    //maze.displaybfs(path);



    maze.displaydfs();
    return 0;
}
