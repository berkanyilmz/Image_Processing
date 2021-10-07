cmake_minimum_required(VERSION 3.20)
project(Ders10_Open)

set(CMAKE_CXX_STANDARD 14)
find_package(OpenCV REQUIRED)

add_executable(Ders10_Open main.cpp)
include_directories(${OpenCV_INCLUDE_DIRS})
target_link_libraries(Ders10_Open ${OpenCV_LIBS})