cmake_minimum_required(VERSION 3.13)

project(mommy VERSION 1.0 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 98)

add_compile_options(
        -Werror
        -Wall
        -Wextra
)

set(CMAKE_CXX_COMPILER "/usr/bin/clang++")

aux_source_directory(src DIR_SRCS)
add_executable(${PROJECT_NAME} ${DIR_SRCS})

target_include_directories(${PROJECT_NAME} PUBLIC .)