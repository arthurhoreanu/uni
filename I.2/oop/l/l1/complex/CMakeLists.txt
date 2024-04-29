cmake_minimum_required(VERSION 3.27)
project(complex)

set(CMAKE_CXX_STANDARD 17)

add_executable(complex L1_complex_test.cpp
        L1_complex.cpp
        L1_complex.h)
