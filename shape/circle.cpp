/**
 * Labb 05, dt047g HT2023
 * @author Hussein Salehi
 * @date 2024-03-26
 * @brief arv hierarchy
 */



#include "circle.h"

// initialize a member of a class circle
Circle::Circle(double radius, std::string color)
        :radius(radius), Shape(color)
{}

// get the area of a class circle
double Circle::get_area() const
{
    return radius * radius * M_PI;
}



// initialize the member of class drived class cylinder
Cylinder::Cylinder(double radius, std::string color, double height) : Circle(radius, color), height(height) {}

// get the area of class cylinder
double Cylinder::get_area() const {
    double lateralArea = 2 * M_PI * radius * height;
    double base_area =  Circle::get_area();
    double total_area = lateralArea + base_area;
    return total_area;
}

// get the volume of class cylinder
double Cylinder::volume() const {

    return Circle::get_area()* height;
}
