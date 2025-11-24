#include <iostream>
#include <fstream>
#include <algorithm>

#include "DSA_Graph.h"
#include <map>

int main() {

    DSA_GRAPH graph(48);
    //graph.print();
    std::cout << std::endl;
    std::string startValue, endValue;
    startValue = "Åkanten1";
    bool runnig = true;
    graph.dfs(startValue);
    std::cout << std::endl;
    std::vector<std::string> data = graph.getData();
    graph.bfs(startValue);



    while (runnig){
        int n;
        std::cout << "\nEnter 1 to calculate path, 2 to exit: ";
        std::cin >> n;

        switch (n) {
            case 1: {
                int startPoint, endPoint;
                std::cout << "chose starting point and destination by entering a number: " <<std::endl;
                for (int i = 0; i < data.size(); i++) {
                        std::cout << i <<": "<<data[i] <<"\n";
                }



                std::cin >> startPoint >> endPoint;


                // Validate input
                if (startPoint < 0 || startPoint >= data.size() ||
                    endPoint   < 0 || endPoint   >= data.size()) {
                    std::cout << "Invalid index! Try again.\n";
                    break;
                    }

                std::vector<double> distanceToAllVertexes = graph.dijkstra(data[startPoint]);

                std::cout << "The shortest path from "
               << data[startPoint] << " to " << data[endPoint]
               << " is: " << distanceToAllVertexes[endPoint] << "\n";
            }

            break;

            case 2:
                runnig = false;

                break;

            default:

                    std::cout << " Invalid option try igen " <<std::endl;
            break;

        }

    };
    return 0;
}
