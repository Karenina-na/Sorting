cmake_minimum_required(VERSION 3.25)
project(Sorting_Algorithm_Interface_Framework)

set(CMAKE_CXX_STANDARD 17)
set(EXECUTABLE_OUTPUT_PATH ${PROJECT_SOURCE_DIR}/bin)

# 静态编译、静态链接
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -static-libgcc -static-libstdc++")
add_subdirectory(src) # src/CMakeLists.txt