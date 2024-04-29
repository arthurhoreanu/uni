cmake_minimum_required(VERSION 3.27)
project(s4)

set(CMAKE_CXX_STANDARD 17)

add_executable(s4 main.cpp
        CrudRepository.h
        Customer.h
        InMemoryRepository.h
        InMemoryRepository.cpp)
