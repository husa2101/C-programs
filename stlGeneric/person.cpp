/**
 * Labb 05, dt047g HT2023
 * @author Hussein Salehi
 * @date 2024-03-26
 * @brief The STL generic algorithms
 */


#include "person.h"
// initialize the class member of person
Person::Person(std::string name, double age):
name(name), lenght(age) {}


bool Person::operator == (Person &lhs) {
    return lhs.name == name;
}

// get the name of a person
std::string Person::getName() const {return name;}

// get the lenght of a person
double Person::getLenght() const {return lenght;}