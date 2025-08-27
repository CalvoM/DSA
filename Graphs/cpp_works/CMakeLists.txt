cmake_minimum_required(VERSION 3.10)

project(graphs)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)
add_executable(${PROJECT_NAME} main.cxx)
target_sources(${PROJECT_NAME} PUBLIC "src/Graph.cxx")
target_include_directories(${PROJECT_NAME} PUBLIC "includes")