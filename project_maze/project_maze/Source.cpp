#include"Maze.h"
#include<iostream>

int main() {
    MyMaze myMaze;
    bool run = true;
    char input;


    std::cout << "_________________________________________________________________________\n";
    std::cout << "                   WELCOME TO THE MAZE GENERATOR                         \n";
    std::cout << "___________________________ menu ______________________________________\n";
    std::cout << " create new maze? (Y)/(Q): ";

    while (run) {
       
        std::cin >> input;
        system("cls");

        if ((input == 'y') || (input == 'Y')) {
            
            myMaze.dfs();
            myMaze.display_cells();
           
        }

        else if ((input == 'q') || (input == 'Q')) {
            run = false;
            std::cout << "\nProgram Ending, GoodBye...\n";
        }

        else {
            std::cout << "\nInvalid input... try again ! \n";
        }
        std::cout << "\n Would you like to generate a new one or Quit? (Y)/(Q):";
    }

    return 0;
}