#include"dsf.h"
#include <stack>

int const allNodeVisited = -1;


void dfs(int S, std::vector<bool>& visited, std::vector<std::vector<double>> matrix) {

	visited[S] = true;   // set the start as visited;

	//std::cout << S << ",";  // printed;
	for (int i = 0; i < matrix.size(); i++)        // iterate from Start punkt and then go trough neighbors;
	{
		if (matrix[S][i] != 0 && !visited[i])          // if the neighbors are not visited;
		{
			dfs( i, visited, matrix); // visit them;
		}
	}
}
bool dfsOfGraph(adjacency_list_t adj,std::vector<std::vector<double>> matrix) {

	std::vector<bool> visited(adj.first.size(), false);
	for (size_t i = 0; i < adj.first.size(); i++)   // we need this for backtracking
	{
		dfs(i,visited, matrix); // chack for unvisited neighbors;
		
		if (allVisited(visited) != allNodeVisited) {
			return false;
		}
	}
	return true;

}

int allVisited(std::vector<bool>& visited)
{
	for (int i = 0; i < visited.size(); i++) {
		if (!visited.at(i)) {
			return i;
		}
	}
	return -1; // retunerar false
}


