/**
 * Labb 05, dt047g HT2023
 * @author Hussein Salehi
 * @date 2024-03-26
 * @brief arv hierarchy
 */



#include "Shape.h"

Shape::Shape(std::string color): color(color) {}
std::string Shape::get_color() {return color;}