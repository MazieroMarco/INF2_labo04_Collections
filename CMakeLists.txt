cmake_minimum_required(VERSION 3.15)
project(Projet)

set(CMAKE_CXX_STANDARD 11)

set(CMAKE_CXX_STANDARD 11)
set (CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -Wconversion -Wextra -Wsign-conversion -pedantic")

add_executable(Projet main_labo_04.cpp collection_g.h exceptions.h produit.h produit.cpp)