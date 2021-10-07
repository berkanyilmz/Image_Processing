cmake_minimum_required(VERSION 3.20)
project(Ders8_Erozyon)

set(CMAKE_CXX_STANDARD 14)
find_package(OpenCV REQUIRED)

add_executable(Ders8_Erozyon main.cpp)
include_directories(${OpenCV_INCLUDE_DIRS})
target_link_libraries(Ders8_Erozyon ${OpenCV_LIBS})