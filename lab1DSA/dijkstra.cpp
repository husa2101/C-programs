#include"dijkstra.h"
#include"print.h"
#include <list>
#include <limits>


void dijkstra(adjacency_list_t adj, int src,  int dest) {

	// innehåller alla behandlade noder och kortaste avstånd mellan dem och src.
	std::vector<std::pair<double, bool>> behandlad(adj.first.size(), std::make_pair(std::numeric_limits<weight_t>::max(), false)); 
	std::priority_queue<std::pair<double, int>, std::vector<std::pair<double, int>>, std::greater<>> pq; // minimum heap

	pq.push(std::make_pair( 0, src ));


	while (!pq.empty())
	{
		std::pair<double, int> node = pq.top();
		pq.pop(); 

		
		if(behandlad.at(node.second).second == false)
		behandlad.at(node.second).first = std::min(node.first, behandlad.at(node.second).first);
		behandlad.at(node.second).second = true;
		//std::cout << "\n" << dis.second << "!\n";


		
		for (auto it : adj.second) // itererar genom
		{
			if (it.n1 == node.second) {   // om noden i adj list är lika med vårt start punkt 
				double edgeWeight = it.weight + node.first;    // ta vikten
				// om grannens Node är kortare än föregående Node om det är kortare så går vi ditt annars kollar vi en annan granne 

				if (behandlad.at(it.n2).first > edgeWeight && behandlad.at(it.n2).second  == false) // if the next node is shorter then previos node 
				{
					// lagra vikt + dist och src och pusha den till qeueue
					std::pair<double, int>  grannar = std::make_pair(edgeWeight, it.n2);
					std::cout << it.n2 << ", ";
					pq.push(grannar); 
				}
			}

		}


	}

	printSPT(behandlad, src, dest, adj);
}


