//
// Created by hussein on 2023-04-22.
//

#include "print_to_file.h"
void write(std::string filename, std::string output){

    std::ofstream myfile;
    myfile.open(filename, std::ios::out | std::ios::app);
    if (myfile.is_open())
    {
        myfile << output << "\n";
    }
    myfile.close();

}