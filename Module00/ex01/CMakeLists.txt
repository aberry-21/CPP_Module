cmake_minimum_required(VERSION 3.13)

project(phonebook VERSION 1.0 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 98)

add_compile_options(
        -Werror
        -Wall
        -Wextra
)

set(CMAKE_CXX_COMPILER "/usr/bin/clang++")

add_executable(${PROJECT_NAME} src/Contact.cpp src/PhoneBook.cpp src/main.cpp ../../Module01/ex00/main.cpp)

target_include_directories(${PROJECT_NAME} PUBLIC includes/Contact.hpp, includes/PhoneBook.hpp)