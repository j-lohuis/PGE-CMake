cmake_minimum_required(VERSION 3.15)

project(empge CXX)

add_executable(main main.cpp olcPixelGameEngine.h)

include(cmake/PGE.cmake)
pge_set_emscripten_options(main)
