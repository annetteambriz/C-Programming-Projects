cmake_minimum_required(VERSION 3.29)
project(C_Programming_Class C)

set(CMAKE_C_STANDARD 11)

add_executable(C_Programming_Class WageCalculator.c
        WageCalculatorWithLoop.c
        Conditionals.c
        Arrays.c
        main.c)
