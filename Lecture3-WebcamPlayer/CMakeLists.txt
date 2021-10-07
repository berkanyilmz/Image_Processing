cmake_minimum_required(VERSION 3.20)
project(Ders3_KameradanGoruntuOkuma)

set(CMAKE_CXX_STANDARD 14)

find_package(OpenCV REQUIRED)

add_executable(Ders3_KameradanGoruntuOkuma main.cpp)

include_directories(${OpenCV_INCLUDE_DIRS})
target_link_libraries(Ders3_KameradanGoruntuOkuma ${OpenCV_LIBS})