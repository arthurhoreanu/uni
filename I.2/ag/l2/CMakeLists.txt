cmake_minimum_required(VERSION 3.27)
project(l2)

set(CMAKE_CXX_STANDARD 17)

add_executable(l2 main.cpp
        Graph.cpp
        Graph.h)
