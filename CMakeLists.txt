cmake_minimum_required(VERSION 2.8.0 FATAL_ERROR)

project(omp_exercises)

set(CMAKE_BUILD_TYPE "Release")

find_package(OpenMP REQUIRED)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} ${OpenMP_CXX_FLAGS}")

add_subdirectory(ex2)

