/**
 * Labb 05, dt047g HT2023
 * @author Hussein Salehi
 * @date 2024-03-26
 * @brief arv hierarchy
 */



#ifndef SHAPE_SQUARE_H
#define SHAPE_SQUARE_H
#include "Shape.h"

// square derived class of shape
class Square: public Shape {
public:
    // construct the object of the class Square
    Square(double side,std::string color );

    // override the shape function to get the area of square
    virtual double get_area() const override;


private:
    double side;
};

#endif //SHAPE_SQUARE_H
