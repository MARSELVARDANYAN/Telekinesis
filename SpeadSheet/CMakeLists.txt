cmake_minimum_required(VERSION 3.15)

project(SpreadSheet)

set(CMAKE_CXX_STANDARD 20)

# Include directories for header files
include_directories(headers)

# Add executable and link libraries if needed
add_executable(SpreadSheet src/main.cpp src/Cell.cpp src/SpreadSheet.cpp)
