cmake_minimum_required(VERSION 3.26)
project(cpp_space_invader)

find_package(SDL2 CONFIG REQUIRED)
find_package(SDL2_image CONFIG REQUIRED)
find_package(SDL2_ttf CONFIG REQUIRED)

set(CMAKE_CXX_STANDARD 17)

add_executable(cpp_space_invader main.cpp
        objects/Asteroid.h
        objects/DimensionalObject.h
        objects/FallingObject.h
        objects/FlyingObject.h
        objects/HealthObject.h
        objects/Spaceship.h
        objects/ScoreObject.h
        Util.h
        Game.cpp
        Game.h
        ui/TextureCreator.cpp
        ui/TextureCreator.h
        ui/SpaceshipTexture.cpp
        ui/SpaceshipTexture.h
        ui/TextureCreatorFromPNG.cpp
        ui/TextureCreatorFromPNG.h)

target_link_libraries(cpp_space_invader
        PRIVATE
        $<TARGET_NAME_IF_EXISTS:SDL2::SDL2main>
        $<IF:$<TARGET_EXISTS:SDL2::SDL2>,SDL2::SDL2,SDL2::SDL2-static>
        $<IF:$<TARGET_EXISTS:SDL2_image::SDL2_image>,SDL2_image::SDL2_image,SDL2_image::SDL2_image-static>
        $<IF:$<TARGET_EXISTS:SDL2_ttf::SDL2_ttf>,SDL2_ttf::SDL2_ttf,SDL2_ttf::SDL2_ttf-static>
)
