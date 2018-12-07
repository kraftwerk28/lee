cmake_minimum_required(VERSION 3.12)
project(lee)

set(CMAKE_CXX_STANDARD 14)

add_executable(lee main.cc window.h window.cc defines.h)

target_link_libraries(lee -lsfml-system -lsfml-window -lsfml-graphics -lpthread)