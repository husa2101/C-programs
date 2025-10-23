/**
 * Labb 05, dt047g HT2023
 * @author Hussein Salehi
 * @date 2024-03-26
 * @brief arv hierarchy
 */



#ifndef SHAPE_RECTANGLE_H
#define SHAPE_RECTANGLE_H
#include "Shape.h"
#include "cmath"

// derived class of the shape class
class Rectangle: public Shape{
public:

    // construct the onject of the class
    Rectangle(double lenght, double width, std::string color);
    virtual double get_area()const override;

protected:
    double lenght;
    double width;
};


// derived class of Rectangle
class Parallelepiped: public Rectangle{
public:
    // construct the onject of the class
    Parallelepiped(double height,double lenght, double width, std::string color );
    virtual double get_area() const override;
    double get_volume() const;

private:
    double height;
};


// derived class of rectangle
class Rounded_rectangle: public Rectangle{
public:
    // construct the onject of the class
    Rounded_rectangle(double corner_radius,double lenght, double width, std::string color );
    virtual double get_area()const override;

private:
    double corner_radius;
};

#endif //SHAPE_RECTANGLE_H
