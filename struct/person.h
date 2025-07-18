//
// Created by shahr on 2025-01-15.
//

#ifndef OBJECTORIENTERING_PERSON_H
#define OBJECTORIENTERING_PERSON_H
#include <iostream>
#include <iomanip>
#include<string>
#include <vector>
#include<fstream>
#include<algorithm>
#include<cctype>





struct Address{
    std::string street;
    int zip;
    std::string city;
};

struct Person{
    std::string name;
    std::string id;
    Address location;
};

// this function change the txt file and user input to tolower before it is processed
std::string strTolower (std::string s);
void print(const Person &person);
std::vector<std::string> split(std::string& s, char delemeter);
std::vector<Person> read_input(std::ifstream & input);
std::vector<Person> search(std::vector<Person> & Vperson, std::string name);



#endif //OBJECTORIENTERING_PERSON_H
