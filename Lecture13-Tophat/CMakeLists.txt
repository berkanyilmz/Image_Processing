cmake_minimum_required(VERSION 3.20)
project(Ders13_TopHat)

set(CMAKE_CXX_STANDARD 14)
find_package(OpenCV REQUIRED)

add_executable(Lecture13-TopHat main.cpp)
include_directories(${OpenCV_INCLUDE_DIRS})
target_link_libraries(Lecture13-TopHat ${OpenCV_LIBS})