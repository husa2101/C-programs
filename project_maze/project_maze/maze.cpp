#include "maze.h"
/*
# skrivet av: Hussein Salehi
# skapat datum: 2022-05-30
# Senaste ändring: 2022-09-17
# Kurs: objektbaserad Programering
# handledare: Jimmy Ålander
# Betyg: E
*/


// constructer with defined size for matrix
MyMaze::MyMaze() {
	this->rows = 11;
	this->colums = 11;
	//Createcells();
}
// node constructer
MyMaze::node::node(int col, int row) {

	this->is_end = false;
	this->is_start = false;
	this->visited = false;
	this->colums = col;
	this->rows = row;
}
// function for creating a new cells and fill the container with new nodes
void MyMaze::Createcells() {

	for (size_t y = 0; y < rows; y++) {

		std::vector<node> newNode;
		for (size_t x = 0; x < colums; x++) {

			node cell = node(x, y);
			newNode.push_back(cell);
		}
		MyvectorUnvisited.push_back(newNode);
	}
}

// funktion for finding unvisited cells
std::vector<MyMaze::node>MyMaze::Unvisited(int CoordinateR, int CoordinateC) {
	std::vector<MyMaze::node> hasUnvisitedNeighbor;

	// ROWS
	if (CoordinateR > 0 && CoordinateR + 2 < MyvectorUnvisited.size() - 1) {                  // två villkor for att hålla oss inom ramen
		if (!MyvectorUnvisited[CoordinateR + 2][CoordinateC].visited) {                       // om vår granne till söderut inte är besökt 
			hasUnvisitedNeighbor.push_back(MyvectorUnvisited[CoordinateR + 2][CoordinateC]);      // då tar vi det 

		}
	}
	if (CoordinateR < MyvectorUnvisited.size() - 1 && CoordinateR - 2  > 0) {                  //
		if (!MyvectorUnvisited[CoordinateR - 2][CoordinateC].visited) {                        // om granne till norrut är inte besökt 
			hasUnvisitedNeighbor.push_back(MyvectorUnvisited[CoordinateR - 2][CoordinateC]);   // 
		}
	}

	// COLUMS
	if (CoordinateC > 0 && CoordinateC + 2 < MyvectorUnvisited.size() - 1) {                    //
		if (!MyvectorUnvisited[CoordinateR][CoordinateC + 2].visited) {                        // om granne till öst är inte besökt 
			hasUnvisitedNeighbor.push_back(MyvectorUnvisited[CoordinateR][CoordinateC + 2]);  //
		}
	}

	if (CoordinateC < MyvectorUnvisited.size() - 1 && CoordinateC - 2> 0) {                    //
		if (!MyvectorUnvisited[CoordinateR][CoordinateC - 2].visited) {							// om granne till väst inte är besökt 
			hasUnvisitedNeighbor.push_back(MyvectorUnvisited[CoordinateR][CoordinateC - 2]);    //
		}
	}

	return hasUnvisitedNeighbor;

}


// function for opening the path in a maze

void MyMaze::pathway(node current, node neighbor)
{
	if (current.colums < neighbor.colums) {                               
		MyvectorUnvisited[current.rows][current.colums + 1].visited = true;
	}

	if (current.colums > neighbor.colums) {
		MyvectorUnvisited[current.rows][current.colums - 1].visited = true;
	}

	if (neighbor.rows < current.rows) {
		MyvectorUnvisited[current.rows - 1][current.colums].visited = true;
	}
	if (neighbor.rows > current.rows) {
		MyvectorUnvisited[current.rows + 1][current.colums].visited = true;
	}
}

// 
void MyMaze::dfs()
{
	srand(unsigned int(time(NULL))); // seed the random number generator used by the function rand() / initialize random number generator
	std::stack<node> pathStack;      // hold the visited node
	MyvectorUnvisited.clear();       // clear the continer in order to create a new maze
	Createcells();                   // fill the 2D vector with new cells

	// start av maze
	node currentN = MyvectorUnvisited[1][1];  // start cell 

	pathStack.push(currentN);
	MyvectorUnvisited[1][1].visited = true;

	while (!pathStack.empty()) {

		currentN = pathStack.top();

		std::vector<MyMaze::node> hasNeighbors = Unvisited(currentN.rows, currentN.colums);
		if (!hasNeighbors.empty()) {

			pathStack.push(currentN);

			node randomNeighbor = hasNeighbors[rand() % hasNeighbors.size()];

			pathway(currentN, randomNeighbor);

			MyvectorUnvisited[randomNeighbor.rows][randomNeighbor.colums].visited = true;
			pathStack.push(randomNeighbor);
		}
		else {
			pathStack.pop();
		}

	}
}
// function for printing out the maze
void MyMaze::display_cells()
{
	MyvectorUnvisited[0][1].is_start = true;
	MyvectorUnvisited[4][10].is_end = true;

	for (size_t y = 0; y < rows; y++)
	{
		for (size_t x = 0; x < colums; x++)
		{
			if (MyvectorUnvisited[x][y].is_start)
			{
				std::cout << "s ";
			}
			else if (MyvectorUnvisited[x][y].is_end)
			{
				std::cout << "e ";
			}
			else if (MyvectorUnvisited[x][y].visited)
			{
				std::cout << "  ";
			}
			else
			{
				std::cout << "##";
			}
		}

		std::cout << std::endl;
	}
}

