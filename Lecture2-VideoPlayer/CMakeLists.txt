cmake_minimum_required(VERSION 3.20)
project(Ders2_VideoOkuma)

set(CMAKE_CXX_STANDARD 14)

find_package(OpenCV REQUIRED)

add_executable(Ders2-VideoOkuma main.cpp)

include_directories(${OPENCV_INCLUDE_DIRS})
target_link_libraries(Ders2-VideoOkuma ${OpenCV_LIBS})
