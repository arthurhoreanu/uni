cmake_minimum_required(VERSION 3.27)
project(s1_s2)

set(CMAKE_CXX_STANDARD 17)

add_executable(s1_s2 main.cpp
        bankAccount.cpp
        BankAccount.h
    balance.txt)
