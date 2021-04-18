cmake_minimum_required(VERSION 3.13)

project(Unnecessary_violence VERSION 1.0 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 98)

add_compile_options(
        -Werror
        -Wall
        -Wextra
)

set(CMAKE_CXX_COMPILER "/usr/bin/clang++")

add_executable(${PROJECT_NAME} src/main.cpp src/Weapon.cpp includes/Weapon.hpp src/HumanA.cpp includes/HumanA.hpp src/HumanB.cpp includes/HumanB.hpp)

target_include_directories(${PROJECT_NAME} PUBLIC .)