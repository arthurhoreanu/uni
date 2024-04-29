cmake_minimum_required(VERSION 3.27)
project(l4)

set(CMAKE_CXX_STANDARD 17)

add_executable(l4 App.cpp
        Matrix.cpp
        ShortTest.cpp
        ExtendedTest.cpp)
