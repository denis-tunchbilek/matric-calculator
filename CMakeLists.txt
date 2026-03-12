cmake_minimum_required(VERSION 3.20)
project(matrix_report CXX)

set(CMAKE_CXX_STANDARD 23)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_library(matrix_core
        src/matrix.cpp
)
target_include_directories(matrix_core PUBLIC include)