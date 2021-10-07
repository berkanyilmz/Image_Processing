cmake_minimum_required(VERSION 3.20)
project(Ders17_KenarBulma)

set(CMAKE_CXX_STANDARD 14)
find_package(OpenCV REQUIRED)

add_executable(Ders17_KenarBulma main.cpp)
include_directories(${OpenCV_INCLUDE_DIRS})
target_link_libraries(Ders17_KenarBulma ${OpenCV_LIBS})