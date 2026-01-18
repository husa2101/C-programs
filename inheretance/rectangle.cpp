//
// Created by shahr on 2025-12-26.
//

#include "rectangle.h"
#include <cmath>

rectangle::rectangle(std::string color, double lenght, double width)
: shape(color), lenght(lenght), width(width) {}

double rectangle::get_area() {
    return lenght * width;
}


// implementation of derived class Parallelepiped of rectangle
parallelepiped::parallelepiped
(std::string color, double lenght, double widht, double height)
:rectangle(color, lenght, widht ), height(height) {}

double parallelepiped::get_area() {
    return 2 * (rectangle::lenght * rectangle::width) + 2 *
    (rectangle::lenght * height) + 2 * (rectangle::width * height);
}

//implementation of derived class runded_rectangle of class rectangle and shape
rounded_rectangle::rounded_rectangle
(std::string color, double rediusRoundedCorner, double widht, double lenght)
:rectangle(color, lenght, widht),rediusRaoundedCorner(rediusRoundedCorner)  {}

double rounded_rectangle::get_area() {
    return rectangle::get_area() +
        2 * rediusRaoundedCorner * (rectangle::lenght + rectangle::width) +
            M_PI *(rediusRaoundedCorner * rediusRaoundedCorner);
}
