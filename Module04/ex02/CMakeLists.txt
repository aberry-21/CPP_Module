cmake_minimum_required(VERSION 3.13)

project(purify_it VERSION 1.0 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 98)

add_compile_options(
        -Werror
        -Wall
        -Wextra
)

set(CMAKE_CXX_COMPILER "/usr/bin/clang++")

add_executable(${PROJECT_NAME} includes/ISpaceMarine.h includes/ISquad.h src/Squad.cc src/TacticalMarine.cc src/AssaultTerminator.cc src/main.cc)

target_include_directories(${PROJECT_NAME} PUBLIC .)
