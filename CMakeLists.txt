cmake_minimum_required(VERSION 3.10)
cmake_policy(VERSION 3.10)

project(PerlinGen)

set(source_dir "${PROJECT_SOURCE_DIR}/src/")
add_executable("${CMAKE_PROJECT_NAME}" src/main.cpp)

include_directories(${CMAKE_SOURCE_DIR}/include)
# target_include_directories("${CMAKE_PROJECT_NAME}" PUBLIC "${CMAKE_SOURCE_DIR}/include") # specifies include folder