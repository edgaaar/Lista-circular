cmake_minimum_required(VERSION 2.8.9)
project(Lista-circular)

include_directories(include)

set(SOURCES src/Nodo.cpp src/main.cpp src/ListaCircular.cpp)

add_executable(lista-circular ${SOURCES})
