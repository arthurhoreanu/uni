cmake_minimum_required(VERSION 3.27)
project(l1)

set(CMAKE_CXX_STANDARD 17)

add_executable(l1 app.cpp
        Graph.cpp
        Graph.h
        newGraph.cpp
        newGraph.h)
