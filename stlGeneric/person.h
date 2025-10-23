/**
 * Labb 05, dt047g HT2023
 * @author Hussein Salehi
 * @date 2024-03-26
 * @brief The STL generic algorithms
 */



#ifndef LAB5_STL_GENERIC_PERSON_H
#define LAB5_STL_GENERIC_PERSON_H
#include "string"
#include <iostream>

class Person {
private:
    std::string name;
    double lenght;

public:
    Person(std::string name, double lenght);
    bool operator ==(Person& lhs);
    std::string getName() const;
    double getLenght() const;

};

// funktor som skriver ut ett resultat
class Print{
public:
    void operator()(const Person& p)const {
    std::cout << "{ "<<p.getName() << p.getLenght()<< " }"<< "\n";
    }
};

// funktor som hittar det första elementet som är större än prescribed värde
class MyPridicate{
private:
    double value;

public:
    MyPridicate(double value): value(value){};
   bool operator()(const Person& p) const{
        return p.getLenght() > value;
   }
};

// funktor som hittar det första paret av lika intilliggande element
class FindSameName{
public:
    bool operator()(Person& lhs, Person& rhs){
        return lhs == rhs;
    }
};

// funktor som jämföra två sekvenser eller delar av sekvenser för likhet,
class FindEqual{
public:
   bool operator()(Person& arr, Person& p){
        return p.getName() == arr.getName() && p.getLenght() == arr.getLenght();
    }
};

// algorithm accumulate in order to calculate the average value
class MyBinOp{
public:
    // sum is a start value= 0
    double operator()(double sum , const Person&p ) const{
        return sum + p.getLenght();
    }
};

// function object for transform operation
class MyUnOp{
public:
    double operator()(Person& p){
    return p.getLenght();
    }
};

// funktions objet som utför ett specifik peration på var och en värde i vec2 och sedan ersätts med den gamla värdet i vec2
class Myfunc{
private:

    double  mean;
public:

    Myfunc(double m): mean(m){}
    double operator()(double x){
        return x -mean;
    }
};



#endif //LAB5_STL_GENERIC_PERSON_H
