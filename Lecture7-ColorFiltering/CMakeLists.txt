cmake_minimum_required(VERSION 3.20)
project(Ders7_RenkFiltreleme)

set(CMAKE_CXX_STANDARD 14)
find_package(OpenCV REQUIRED)

add_executable(Ders7_RenkFiltreleme main.cpp)

include_directories(${OpenCV_INCLUDE_DIRS})
target_link_libraries(Ders7_RenkFiltreleme ${OpenCV_LIBS})