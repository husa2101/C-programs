cmake_minimum_required(VERSION 3.27)
project(contactbok)

set(CMAKE_CXX_STANDARD 17)

add_executable(contactbok main.cpp
        person.cpp
        person.h
)
