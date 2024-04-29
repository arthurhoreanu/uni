cmake_minimum_required(VERSION 3.27)
project(l2)

set(CMAKE_CXX_STANDARD 17)

add_executable(l2 L2_dsm_test.cpp
        L2_dsm.cpp
        L2_dsm.h)
