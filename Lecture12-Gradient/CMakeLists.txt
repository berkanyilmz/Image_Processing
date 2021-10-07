cmake_minimum_required(VERSION 3.20)
project(Ders12_Gradient)

set(CMAKE_CXX_STANDARD 14)
find_package(OpenCV REQUIRED)

add_executable(Ders12_Gradient main.cpp)
include_directories(${OpenCV_INCLUDE_DIRS})
target_link_libraries(Ders12_Gradient ${OpenCV_LIBS})