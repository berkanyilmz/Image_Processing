cmake_minimum_required(VERSION 3.20)
project(Ders6_Piksel)

set(CMAKE_CXX_STANDARD 14)
find_package(OpenCV REQUIRED)
add_executable(Ders6_Piksel main.cpp)
include_directories(${OpenCV_INCLUDE_DIRS})
target_link_libraries(Ders6_Piksel ${OpenCV_LIBS})