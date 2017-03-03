cmake_minimum_required(VERSION 3.6)
project(GameOfLife)

set(CMAKE_CXX_STANDARD 11)

set(SOURCE_FILES main.c data.h data.c simulation.c simulation.h config.c config.h ini.c ini.h)
add_executable(GameOfLife ${SOURCE_FILES} main.c)