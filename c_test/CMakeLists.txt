cmake_minimum_required(VERSION 3.3)
project(c_test)

set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -Werror -std=c99")

set(SOURCE_FILES main.c)
add_executable(c_test ${SOURCE_FILES})