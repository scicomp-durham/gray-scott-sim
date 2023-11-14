cmake_minimum_required(VERSION 3.6) 
project(GrayScottSim VERSION 1.0)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED True)

add_executable(GrayScottSim gs.cpp)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -static-libstdc++")

target_compile_features(GrayScottSim PUBLIC cxx_std_11)