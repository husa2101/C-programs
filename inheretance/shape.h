//
// Created by shahr on 2025-12-26.
//

#ifndef SHAPE_H
#define SHAPE_H
#include <string>

class shape {
    protected:
    std::string color;
    public :
    shape ( std :: string color ) ;
    virtual double get_area () = 0;
    std :: string get_color () ;
};


#endif //SHAPE_H
