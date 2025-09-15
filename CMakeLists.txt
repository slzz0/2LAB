cmake_minimum_required(VERSION 3.12)

project(lab2)  

include_directories(headers)

set(SOURCES
    source/main.cpp
    source/array.cpp      
    source/menu.cpp
    source/program.cpp
    source/utilits.cpp
)

set(HEADERS
    headers/array.h       
    headers/menu.h
    headers/program.h
    headers/utilits.h
)

add_executable(lab2 ${SOURCES} ${HEADERS})  