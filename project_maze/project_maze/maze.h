#pragma once
#include <iostream>
#include <vector>
#include <stack>



class MyMaze
{
private:
size_t rows, colums;
	struct node {
		node(int , int);
		size_t rows, colums;
		bool visited, is_start, is_end;
	}; 


	
	std::vector < std::vector < node>> MyvectorUnvisited;
	
	

	public:
	
		MyMaze();               
		void dfs();                              
		void Createcells();
		void display_cells();
		void pathway(node, node);
		std::vector<node> Unvisited(int, int);
		
};



