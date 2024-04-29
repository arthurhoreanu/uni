cmake_minimum_required(VERSION 3.27)
project(l2)

set(CMAKE_CXX_STANDARD 17)

add_executable(l2 App.cpp
        ShortTest.cpp
        ShortTest.h
        ExtendedTest.cpp
        ExtendedTest.h
        Map.cpp
        Map.h
        MapIterator.cpp
        MapIterator.h)
