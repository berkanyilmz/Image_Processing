cmake_minimum_required(VERSION 3.20)
project(Ders15_Filtreleme)

set(CMAKE_CXX_STANDARD 14)
find_package(OpenCV REQUIRED)

add_executable(Ders15_Filtreleme main.cpp)
include_directories(${OpenCV_INCLUDE_DIRS})
target_link_libraries(Ders15_Filtreleme ${OpenCV_LIBS})