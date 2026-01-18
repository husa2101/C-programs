//
// Created by shahr on 2025-12-26.
//

#include "shape.h"
#include <stdexcept>

// shape medlemar
shape::shape(std::string color): color(color) {
}

std::string shape::get_color() {
    return color;
}




