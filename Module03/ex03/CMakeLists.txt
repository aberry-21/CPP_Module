cmake_minimum_required(VERSION 3.13)

project(now_it_s_easier VERSION 1.0 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 98)

add_compile_options(
        -Werror
        -Wall
        -Wextra
)

set(CMAKE_CXX_COMPILER "/usr/bin/clang++")

add_executable(${PROJECT_NAME} src/ClapTrap src/FragTrap.cc src/ScavTrap.cc src/NinjaTrap.cc src/main.cc)

target_include_directories(${PROJECT_NAME} PUBLIC .)