cmake_minimum_required(VERSION 3.13)

project(world_on_fire VERSION 1.0 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 98)

add_compile_options(
        -Werror
        -Wall
        -Wextra
)

set(CMAKE_CXX_COMPILER "/usr/bin/clang++")

add_executable(${PROJECT_NAME} src/AWeapon.cc src/PlasmaRifle.cc src/PowerFist.cc src/Enemy.cc src/SuperMutant.cc src/RadScorpion.cc src/Character.cc src/main.cc )

target_include_directories(${PROJECT_NAME} PUBLIC .)
