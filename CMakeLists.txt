cmake_minimum_required(VERSION 3.10)
project(a-compiler C)

set(CMAKE_C_STANDARD 23)
set(CMAKE_C_EXTENSIONS ON)
set(CMAKE_C_STANDARD_REQUIRED ON)

include_directories(include)

add_executable(compiler
    src/main.c
)
