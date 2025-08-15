cmake_minimum_required(VERSION 3.24)
project(projectcpp3)

set(CMAKE_CXX_STANDARD 20)

add_executable(projectcpp3 main.cpp Dictionary.cpp Dictionary.h Node.cpp Node.h Iterator.cpp Iterator.h)
