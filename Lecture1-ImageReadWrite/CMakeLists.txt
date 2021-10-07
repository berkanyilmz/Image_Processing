cmake_minimum_required(VERSION 3.20)
project(GoruntuOkumaYazma)

set(CMAKE_CXX_STANDARD 14)

find_package(OpenCV REQUIRED)

add_executable(GoruntuOkumaYazma main.cpp)

include_directories(${OpenCV_INCLUDE_DIRS})
target_link_libraries(GoruntuOkumaYazma ${OpenCV_LIBS})
