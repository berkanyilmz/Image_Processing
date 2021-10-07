cmake_minimum_required(VERSION 3.20)
project(Ders14_BlackHat)

set(CMAKE_CXX_STANDARD 14)
find_package(OpenCV REQUIRED)

add_executable(Ders14_BlackHat main.cpp)
include_directories(${OpenCV_INCLUDE_DIRS})
target_link_libraries(Ders14_BlackHat ${OpenCV_LIBS})