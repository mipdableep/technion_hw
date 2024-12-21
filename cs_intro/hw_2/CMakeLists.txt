cmake_minimum_required(VERSION 3.20)

project(hw_2 C)

set(CMAKE_C_STANDARD 99)

set(CMAKE_C_FLAGS "-Wall -Werror -pedantic-errors -lm -g")

add_executable(q1 hw2q1.c)
add_executable(q2 hw2q2.c)
add_executable(q3 hw2q3.c)