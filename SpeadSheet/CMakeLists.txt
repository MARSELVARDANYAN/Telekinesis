cmake_minimum_required(VERSION 3.15)

project(SpreadSheed)

set(CMAKE_CXX_STANDARD 20)

add_executable(SpreadSheed src/main.cpp src/Cell.cpp src/SpreadSheed.cpp headers/Cell.h headers/SpreadSheed.h)