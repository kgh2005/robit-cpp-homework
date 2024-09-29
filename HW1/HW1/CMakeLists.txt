cmake_minimum_required(VERSION 3.5)

project(HW1 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(HW1 main.cpp boolstack.h boolstack.cpp boolqueue.h boolqueue.cpp)
