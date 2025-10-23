/**
 * Labb 05, dt047g HT2023
 * @author Hussein Salehi
 * @date 2024-03-26
 * @brief arv hierarchy
 */


#ifndef SHAPE_CIRCLE_H
#define SHAPE_CIRCLE_H
#include "cmath"
#include "Shape.h"
#include <string>
// derived class of shape class
class Circle: public Shape{
public:
    // class constructure
    Circle(double radius, std::string color = "");
    virtual double get_area () const override;

protected:
    double radius;
};

// derived class of circle
class Cylinder: public Circle {
public:
    Cylinder(double radius, std::string color, double height);
    double volume() const;
    virtual double get_area() const override;

protected:
double height;
};
#endif //SHAPE_CIRCLE_H
