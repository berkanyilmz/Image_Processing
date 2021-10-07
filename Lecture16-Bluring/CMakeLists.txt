cmake_minimum_required(VERSION 3.20)
project(Ders16_Bulaniklastirma)

set(CMAKE_CXX_STANDARD 14)
find_package(OpenCV REQUIRED)

add_executable(Ders16_Bulaniklastirma main.cpp)
include_directories(${OpenCV_INCLUDE_DIRS})
target_link_libraries(Ders16_Bulaniklastirma ${OpenCV_LIBS})