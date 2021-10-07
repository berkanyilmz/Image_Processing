cmake_minimum_required(VERSION 3.20)
project(Ders4_Matris)

set(CMAKE_CXX_STANDARD 14)

find_package(OpenCV REQUIRED)

add_executable(Ders4_Matris main.cpp)

include_directories(${OpenCV_INCLUDE_DIRS})
target_link_libraries(Ders4_Matris ${OpenCV_LIBS})