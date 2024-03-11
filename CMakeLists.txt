cmake_minimum_required(VERSION 3.26)
project(cpp_space_invader)

set(CMAKE_CXX_STANDARD 17)

add_executable(cpp_space_invader main.cpp
        objects/Asteroid.h
        objects/DimensionalObject.h
        objects/FallingObject.h
        objects/FlyingObject.h
        objects/HealthObject.h
        objects/Player.h
        objects/Util.h
        objects/ScoreObject.h
        objects/Star.h)
