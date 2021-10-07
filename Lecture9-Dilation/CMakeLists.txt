cmake_minimum_required(VERSION 3.20)
project(Ders9_Dilation)

set(CMAKE_CXX_STANDARD 14)
find_package(OpenCV REQUIRED)

add_executable(Ders9_Dilation main.cpp)
include_directories(${OpenCV_INCLUDE_DIRS})
target_link_libraries(Ders9_Dilation ${OpenCV_LIBS})