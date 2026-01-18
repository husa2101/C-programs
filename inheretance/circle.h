//
// Created by shahr on 2025-12-26.
//

#ifndef CIRCLE_H
#define CIRCLE_H
#include "shape.h"


class circle: public shape{
protected:
    double radius;
public:
    circle( std :: string color, double radius ) ;
    double get_area () override;

};


class cylinder: public circle {
    double height;
public:
    cylinder(std::string color, double, double);
    double get_area () ;
};


#endif //CIRCLE_H
