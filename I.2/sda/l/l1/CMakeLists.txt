cmake_minimum_required(VERSION 3.27)
project(l1)

set(CMAKE_CXX_STANDARD 17)

add_executable(l1 App.cpp
        ExtendedTest.cpp
        ExtendedTest.h
        ShortTest.cpp
        ShortTest.h
        SortedBag.cpp
        SortedBag.h
        SortedBagIterator.cpp
        SortedBagIterator.h)
