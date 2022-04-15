cmake_minimum_required(VERSION 3.20)
project(MyDL)

set(CMAKE_CXX_STANDARD 14)

add_subdirectory(src)

add_executable(efc main.cpp)

target_link_libraries(efc lib)
