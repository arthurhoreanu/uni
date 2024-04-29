cmake_minimum_required(VERSION 3.27)
project(rational)

set(CMAKE_CXX_STANDARD 17)

add_executable(rational L1_rational_test.cpp
        L1_rational.cpp
        L1_rational.h)
