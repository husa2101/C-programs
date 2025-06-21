#include "person.h"

void read(std::ifstream & file){
    std::vector<Person> vPetrson;

    std::string line;
    while(std::getline(file, line)){
    std::cout << line;
    }
 
}