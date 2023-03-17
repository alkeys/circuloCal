cmake_minimum_required(VERSION 3.24)
project(pruevas C)

set(CMAKE_C_STANDARD 99)

add_executable(pruevas main.c)

TARGET_LINK_LIBRARIES(pruevas m )