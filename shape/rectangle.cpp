/**
 * Labb 05, dt047g HT2023
 * @author Hussein Salehi
 * @date 2024-03-26
 * @brief arv hierarchy
 */

#include "rectangle.h"
// initialize the member of the class rectangle
Rectangle::Rectangle(double lenght, double width, std::string color):
width(width), lenght(lenght), Shape(color){}

// get the area of rectangle
double Rectangle::get_area() const {
    return lenght * width;
}



// initialize class member of Parallelepiped and also base class
Parallelepiped::Parallelepiped(double height, double length, double width, std::string color):
height(height), Rectangle(length, width, color){}

// get the area of Parallelepiped
double Parallelepiped::get_area() const {
    double base_area = Rectangle::get_area();
    return 2 * (base_area + lenght * width * height);
}

// get the volume of Parallelepiped
double Parallelepiped::get_volume() const {
    return Rectangle::get_area() * height;
}


// initialize the member class of rounded_rectangle
Rounded_rectangle::Rounded_rectangle(double corner_radius, double lenght, double width, std::string color):
corner_radius(corner_radius), Rectangle(lenght, width, color){}

// get the area of Rounded_rectangle
double Rounded_rectangle::get_area() const {

    double rect_area_without_corners = (lenght - 2 * corner_radius) * (width - 2 * corner_radius);
    double area_of_corners = M_PI * corner_radius * corner_radius;

    return rect_area_without_corners + area_of_corners;

}

