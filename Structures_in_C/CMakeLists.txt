cmake_minimum_required(VERSION 3.29)
project(Structures_in_C C)

set(CMAKE_C_STANDARD 11)

add_executable(Structures_in_C main.c
        employee.h
        processInput.c
        calculateOutputs.c
        displayResults.c)
