cmake_minimum_required(VERSION 3.29)
project(inheretance)

set(CMAKE_CXX_STANDARD 20)

add_executable(inheretance main.cpp
        shape.h
        shape.cpp
        circle.cpp
        circle.h
        rectangle.cpp
        rectangle.h
)
