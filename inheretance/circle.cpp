//
// Created by shahr on 2025-12-26.
//

#include "circle.h"
#include <cmath>

circle::circle(std::string color, double radius)
:shape(color), radius(radius){}


double circle::get_area() {
    return radius * radius * M_PI ;
}


// implementation of derived class to circle and shape
cylinder::cylinder(std::string color, double radius, double height)
:circle(color, radius), height(height) {}

double cylinder::get_area() {
    double circle_area = circle::get_area();
    return circle_area * height;
}