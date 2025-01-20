cmake_minimum_required(VERSION 3.29)
project(q1_copy C)

set(CMAKE_C_STANDARD 99)

add_executable(q1_copy main.c)
target_link_libraries(q1_copy m)