cmake_minimum_required(VERSION 3.26)
project(cpp_space_invader)

find_package(SDL2 CONFIG REQUIRED)
find_package(SDL2_image CONFIG REQUIRED)
find_package(SDL2_ttf CONFIG REQUIRED)
find_package(SDL2_mixer CONFIG REQUIRED)
find_package(SDL2_mixer_ext CONFIG REQUIRED)

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
        ui/objectTextures/SpaceshipTexture.cpp
        ui/objectTextures/SpaceshipTexture.h
        ui/TextureCreatorFromPNG.cpp
        ui/TextureCreatorFromPNG.h
        ui/objectTextures/StarTexture.h
        ui/objectTextures/StarTexture.cpp
        ui/objectTextures/AsteroidTexture.h
        ui/objectTextures/AsteroidTexture.cpp
        sound/GameMusic.cpp
        sound/GameMusic.h
        ui/text/GameText.cpp
        ui/text/GameText.h
        ui/text/SpaceshipHealthGameText.cpp
        ui/text/SpaceshipHealthGameText.h
        ui/text/SpaceshipPointGameText.cpp
        ui/text/SpaceshipPointGameText.h
        objects/SpaceshipBullet.h
        ui/objectTextures/BulletTexture.cpp
        ui/objectTextures/BulletTexture.h
        sound/GameSoundEffect.cpp
        sound/GameSoundEffect.h
        Config.h
        ui/text/SpaceshipPointGameText.h
        ui/objectTextures/BackgroundTexture.h
        ui/objectTextures/BackgroundTexture.cpp
        objects/BackgroundElement.h
        objects/BackgroundElement.cpp
)

target_link_libraries(cpp_space_invader
        PRIVATE
        $<TARGET_NAME_IF_EXISTS:SDL2::SDL2main>
        $<IF:$<TARGET_EXISTS:SDL2::SDL2>,SDL2::SDL2,SDL2::SDL2-static>
        $<IF:$<TARGET_EXISTS:SDL2_image::SDL2_image>,SDL2_image::SDL2_image,SDL2_image::SDL2_image-static>
        $<IF:$<TARGET_EXISTS:SDL2_ttf::SDL2_ttf>,SDL2_ttf::SDL2_ttf,SDL2_ttf::SDL2_ttf-static>
        $<IF:$<TARGET_EXISTS:SDL2_mixer::SDL2_mixer>,SDL2_mixer::SDL2_mixer,SDL2_mixer::SDL2_mixer-static>
        $<IF:$<TARGET_EXISTS:SDL2_mixer_ext::SDL2_mixer_ext>,SDL2_mixer_ext::SDL2_mixer_ext,SDL2_mixer_ext::SDL2_mixer_ext_Static>
)
