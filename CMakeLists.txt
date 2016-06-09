cmake_minimum_required(VERSION 2.8.0 FATAL_ERROR)

project(omp_exercises)

set(CMAKE_BUILD_TYPE "Release")

option(ENABLE_OPENMP "Tun on OpenMP threading" ON)

if (ENABLE_OPENMP)
    find_package(OpenMP REQUIRED)
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} ${OpenMP_CXX_FLAGS}")
    add_definitions("-DHAVE_OPENMP")
endif()

add_subdirectory(ex2)

