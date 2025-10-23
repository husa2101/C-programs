/**
 * Labb 05, dt047g HT2023
 * @author Hussein Salehi
 * @date 2024-03-26
 * @brief arv hierarchy
 */



#include "Square.h"

// initialize the member class
Square::Square(double side, std::string color): side(side), Shape(color) {}

// get the area of the square
double Square::get_area() const {
    return side * side;
}