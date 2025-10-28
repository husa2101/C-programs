#include"print.h"

void print(adjacency_list_t test)
{
    for (int i = 0; i < test.first.size(); i++) {
        std::cout << i;
        for (auto it : test.second) {
            if (it.n1 == i)
                std::cout << " --> " << it.weight << " --> " << it.n2;
        }
        std::cout << std::endl;
    }
}



// A utility function to print the constructed distance
// array
void printSPT(std::vector<std::pair<double, bool>>& adj, int start, int dest, adjacency_list_t& list) {
    std::cout << list.first[start] << " ===> " << list.first[dest] << ":   " << adj.at(dest).first << std::endl;
}