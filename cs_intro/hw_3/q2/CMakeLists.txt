cmake_minimum_required(VERSION 3.20)
project(question_template C)

set(CMAKE_C_STANDARD 99)

set(CMAKE_C_FLAGS "-Wall -Werror -pedantic-errors -lm -g")
add_executable(question_template q2.c)
