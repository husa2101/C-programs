#include <vector>
#include "matrix.h"
#include <iostream>

std::vector<std::vector<double>> convertToMatrix(adjacency_list_t test) {
	// 2D vector with the fix size and initialize all the element from 0
	std::vector<std::vector<double> > matrix(test.first.size(), std::vector<double>(test.first.size(), 0));
	for (int i = 0; i < test.first.size(); i++) {
		for (auto j : test.second) {
			if (j.n1 == i)
				matrix[i][j.n2] = j.weight; // assign a weight between nods.
		}
	}
	return matrix;
}




