cmake_minimum_required(VERSION 3.14)  # 设置CMake的最低版本要求
project(GrayScottSim)  # 设置你的项目名称

# 设置C++标准
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED True)

if(MSVC)
  # 设置运行时库选项
  set(CMAKE_CXX_FLAGS_DEBUG "${CMAKE_CXX_FLAGS_DEBUG} /MDd")
  set(CMAKE_CXX_FLAGS_RELEASE "${CMAKE_CXX_FLAGS_RELEASE} /MD")
endif()

# 添加你的源文件和模拟逻辑文件
add_executable(GrayScottApp gs.cpp GrayScottSimulation.cpp)

# 创建一个新的可执行文件用于测试，并包含模拟逻辑文件
add_executable(GrayScottTests tests.cpp GrayScottSimulation.cpp)

if(MSVC)
  # 设置gtest库的运行时库选项为与你的项目相同
  set(gtest_force_shared_crt ON CACHE BOOL "Use shared (DLL) run-time lib even when Google Test is built as static lib.")
endif()

# 添加googletest作为子目录
add_subdirectory(extern/googletest)

# 包含googletest的头文件
include_directories(extern/googletest/include)

# 链接googletest到你的测试项目
target_link_libraries(GrayScottTests gtest gtest_main)
