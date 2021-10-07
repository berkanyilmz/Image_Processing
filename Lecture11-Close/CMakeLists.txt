cmake_minimum_required(VERSION 3.20)
project(Ders11_Close)

set(CMAKE_CXX_STANDARD 14)
find_package(OpenCV REQUIRED)

add_executable(Ders11_Close main.cpp)
include_directories(${OpenCV_INCLUDE_DIRS})
target_link_libraries(Ders11_Close ${OpenCV_LIBS})