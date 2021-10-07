cmake_minimum_required(VERSION 3.20)
project(Ders18_BilgiCikarma)

set(CMAKE_CXX_STANDARD 14)
find_package(OpenCV REQUIRED)

add_executable(Ders18_BilgiCikarma main.cpp)
include_directories(${OpenCV_INCLUDE_DIRS})
target_link_libraries(Ders18_BilgiCikarma ${OpenCV_LIBS})