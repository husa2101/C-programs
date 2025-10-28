#include"bfs.h"
#include <list>

bool bfs(int Start, adjacency_list_t adj)
{
	std::queue<int> Q;
	std::vector<bool> visited(adj.first.size(), false);
	Q.push(Start);
	visited[Start] = true;
	

	while (!Q.empty())
	{
		int	Node = Q.front();
		Q.pop();
		//std::cout << v << ",";

		for (auto u : adj.second)
		{
			if (u.n1 == Node) {


				if (!visited[u.n2]){

					Q.push(u.n2);
					visited[u.n2] = true;
				}
			}
			
		}
		
	}
	return true;

}
