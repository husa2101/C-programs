//
// Created by shahr on 2023-05-22.
//

#include "print.h"


void clear(std::vector<std::string> fileNames) {
    std::ofstream myfile;
    for (int i = 0; i < fileNames.size(); i++) {
        myfile.open(fileNames.at(i), std::ios::out | std::ios::trunc);
        if (myfile.is_open())
        {
            // take filename and erase the last 5 charectors and then write the string over the previus contant.
            myfile << " ";
        }
        myfile.close();
    }
}

void write(std::string message, std::string textfiles) {
    std::ofstream myfile;
    myfile.open(textfiles, std::ofstream ::out | std::ofstream::app);
    if(myfile.is_open()){
        myfile << message << "\n";
    }
    myfile.close();

}
