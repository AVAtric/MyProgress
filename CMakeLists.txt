cmake_minimum_required(VERSION 3.10)
project(progress C)

set(CMAKE_C_STANDARD 99)

add_executable(progress main.c progress.h progress.c)