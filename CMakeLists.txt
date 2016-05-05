cmake_minimum_required(VERSION 3.3)
project(Data_Container)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(SOURCE_FILES
    aghException.cpp
    aghException.h
    catch.h
    aghInclude.h
    aghContainer.cpp
    aghContainer.h
    ex3main.cpp)

add_executable(Data_Container ${SOURCE_FILES})