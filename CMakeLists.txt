cmake_minimum_required(VERSION 3.14)
project(OrGraph)

set(CMAKE_CXX_STANDARD 14)

set(SFML_ROOT E:/SFML-2.5.1)
set(SFML_STATIC_LIBRARIES TRUE)

add_executable(OrGraph main.cpp Graph.cpp Graph.h)

find_package(SFML 2.5 COMPONENTS graphics audio REQUIRED)
target_link_libraries(OrGraph sfml-graphics sfml-audio)