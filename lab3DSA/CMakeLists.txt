cmake_minimum_required(VERSION 3.24)
project(lab3struct)

set(CMAKE_CXX_STANDARD 17)

add_executable(lab3struct main.cpp
        dataGenerate.cpp
        dataGenerate.h
        algorithm.cpp
        algorithm.h
        timeCalculation.cpp
        timeCalculation.h
        graph.py
        print.cpp print.h)
