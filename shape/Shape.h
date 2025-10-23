/**
 * Labb 05, dt047g HT2023
 * @author Hussein Salehi
 * @date 2024-03-26
 * @brief arv hierarchy
 */




#ifndef SHAPE_SHAPE_H
#define SHAPE_SHAPE_H
#include <string>

class Shape {
public :

    Shape ( std :: string color ) ;
    virtual double get_area () const = 0;
    std :: string get_color () ;
private:
    std::string color;
};


#endif //SHAPE_SHAPE_H
