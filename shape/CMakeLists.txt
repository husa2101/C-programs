cmake_minimum_required(VERSION 3.27)
project(shape)

set(CMAKE_CXX_STANDARD 17)

add_executable(shape main.cpp
        Shape.cpp
        Shape.h
        circle.cpp
        circle.h
        rectangle.cpp
        rectangle.h
        Square.cpp
        Square.h
)
