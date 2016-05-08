cmake_minimum_required(VERSION 3.3)
project(Data_Container)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(SOURCE_FILES
    aghContainer.cpp
    aghContainer.h
    aghException.cpp
    aghException.h
    aghInclude.h
    aghVector.cpp
    aghVector.h
    catch.h
    ex3main.cpp)

add_executable(Data_Container ${SOURCE_FILES})