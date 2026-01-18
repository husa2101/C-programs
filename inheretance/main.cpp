#include <iostream>
#include<string>

#include "circle.h"
#include "rectangle.h"


int main() {

circle c("red", 5);
  std::cout << "circle's color is: ( " << c.get_color() <<" ) and the area is: [ " << c.get_area()<< " ]"<< std::endl;

cylinder cl("blue", 6, 2);
      std::cout << "cylinder's color is: ( " << cl.get_color() <<" ) and the area is: [ " << cl.get_area()<< " ]"<< std::endl;

    rectangle r("yellow", 2, 9);
  std::cout << "rectangle's color is: ( " << r.get_color() <<" ) and the area is: [ " << r.get_area()<< " ]"<< std::endl;

  parallelepiped p("black", 2, 10, 5);
std::cout << "Parallelepiped color is: (" << p.get_color() << " ) and the area is: [ " << p.get_area()<< " ]"<< std::endl;

  rounded_rectangle ro("white", 2, 10, 5);
std::cout << "roundedRectangle color is: (" << ro.get_color() << " ) and the area is: [ " << ro.get_area()<< " ]"<< std::endl;



    return 0;
}
