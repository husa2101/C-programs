//
// Created by shahr on 2025-12-26.
//

#ifndef RECTANGLE_H
#define RECTANGLE_H
#include "shape.h"


class rectangle: public shape {
protected:
    double lenght, width;
public:
    rectangle ( std :: string color, double, double ) ;
    double get_area () ;
};


// derived class of reclangle and shape
class parallelepiped: public rectangle {
    double height;

    public:
    parallelepiped(std::string color, double, double, double);
    double get_area () ;
};



// derived class of rectangle and shape
class rounded_rectangle: public rectangle {

    double rediusRaoundedCorner;
public:
    rounded_rectangle
    (std::string color,double rediusRoundedCorner, double lenght, double widht);
    double get_area () ;
};


#endif //RECTANGLE_H
