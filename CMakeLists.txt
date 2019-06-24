cmake_minimum_required(VERSION 3.14)
project(OrGraph)

set(CMAKE_CXX_STANDARD 14)


add_executable(OrGraph main.cpp Graph.cpp Graph.h Edge.cpp Edge.h DSU.cpp DSU.h)

