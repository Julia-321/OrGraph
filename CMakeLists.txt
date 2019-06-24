cmake_minimum_required(VERSION 3.14)
project(OrGraph)

set(CMAKE_CXX_STANDARD 14)

set(SFML_ROOT E:/SFML)

set (SFML_USE_STATIC_LIBS OFF)

add_executable(OrGraph main.cpp Graph.cpp Graph.h Edge.cpp Edge.h DSU.cpp DSU.h)

find_package(SFML 2.5.1 COMPONENTS graphics window system REQUIRED)
include_directories(E:/SFML/include/SFML)
target_link_libraries(OrGraph sfml-graphics sfml-window sfml-system)
