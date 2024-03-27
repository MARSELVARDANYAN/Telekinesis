cmake_minimum_required(VERSION 3.10)

project(Stack)

set(CMAKE_CXX_STANDARD 20)

add_executable(Stack Src/main.cpp Header/stack.hpp Header/stack.h)
