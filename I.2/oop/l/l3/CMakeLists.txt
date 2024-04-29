cmake_minimum_required(VERSION 3.27)
project(Pharmacy)

set(CMAKE_CXX_STANDARD 20)

add_executable(Pharmacy main.cpp
        Domain/Medicine.cpp
        Domain/Medicine.h
        Controller/Controller.cpp
        Controller/Controller.h
        Repository/Repository.cpp
        Repository/Repository.h
        UI/UserInterface.cpp
        UI/UserInterface.h
        Test/Test.cpp
        Test/Test.h)
