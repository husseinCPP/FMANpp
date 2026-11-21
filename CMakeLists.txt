
cmake_minimum_required(VERSION 3.23)
project(FManpp)

set(CMAKE_CXX_COMPILER=GCC)
set(CMAKE_CXX_COMPILER_VERSION "14.2.0")

set(CMAKE_CXX_STANDARD 23)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)   

add_executable(${PROJECT_NAME} src/fman++.cpp.cpp)
target_include_directories(FManpp PRIVATE include)
target_compile_options(${PROJECT_NAME} PRIVATE -Wall -Wextra)
