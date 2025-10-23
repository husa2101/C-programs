/**
 * Labb 05, dt047g HT2023
 * @author Hussein Salehi
 * @date 2024-03-26
 * @brief arv hierarchy
 */



#include <iostream>
#include <vector>
#include "circle.h"
#include "rectangle.h"
#include "Square.h"
#include"Shape.h"

void get_data (std::vector<Shape*>shapes );

int main() {

    std::vector<Shape*>shapes;

   Circle* c  = new Circle( 9, "red");
   Rectangle* r =new Rectangle (8, 9, "blue");
    Cylinder* cl = new Cylinder (6, "black", 5);
    Parallelepiped* p = new Parallelepiped(5, 5, 8, "gul");
    Rounded_rectangle* round = new Rounded_rectangle(2, 4, 3, "orange");
    Square* q = new Square(5, "gro");

    shapes.push_back(c);
    shapes.push_back(r);
    shapes.push_back(cl);
    shapes.push_back(p);
    shapes.push_back(round);
    shapes.push_back(q);
    get_data(shapes);


    /*
    std::cout << q.get_area() << " " << q.get_color() <<std::endl;
    std::cout << round.get_area() << " "<< round.get_color()<< std::endl;
    std::cout << p.get_area() << "  " << p.get_volume() <<std::endl;
    std::cout << "the volume is: "<<cl.volume() << "and the area is: "<< cl.get_area()<< std::endl;
    std::cout  << c.get_area() <<" "<<c.get_color() << std::endl;
    std::cout <<r.get_area() << " " << r.get_color() << std::endl;
*/


    return 0;
}

void get_data(std::vector<Shape*>vec){
    std::vector<Shape*>::iterator it;

    double totalArea = 0.0;

    for(it = vec.begin(); it != vec.end(); it++){
    Shape* obj = *it;
    std::cout << "Color: "<< obj->get_color() << ", Area: " << obj->get_area() << std::endl;
    totalArea+=obj->get_area();
    }

    std::cout << "TotalArea; " << totalArea;

}