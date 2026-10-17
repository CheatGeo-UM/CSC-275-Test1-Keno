cmake_minimum_required(VERSION 4.3)
project(CSC_275_Test1_Keno)

set(CMAKE_CXX_STANDARD 14)

include_directories(.)

add_executable(CSC_275_Test1_Keno
        main.cpp
        Game.cpp
        Game.h
        KenoNumbers.cpp
        KenoNumbers.h
        Player.cpp
        Player.h)
