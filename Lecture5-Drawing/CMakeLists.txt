cmake_minimum_required(VERSION 3.20)
project(Ders5_CizimIslemleri)

set(CMAKE_CXX_STANDARD 14)

find_package(OpenCV REQUIRED)

add_executable(Ders5_CizimIslemleri main.cpp)

include_directories(${OpenCV_INCLUDE_DIRS})
target_link_libraries(Ders5_CizimIslemleri ${OpenCV_LIBS})