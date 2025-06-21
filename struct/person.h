#if !defined(MACRO)
#define MACRO

#include <string>
#include <vector>
#include <fstream>
#include <iostream>
void read(std::ifstream &file);


struct Adress
{
    std::string street;
    int zip;
    std::string city;
};

struct Person
{
    std::string name;
    std::string id;
    Adress location;
};




#endif // MACRO

