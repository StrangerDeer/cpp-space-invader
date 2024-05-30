#pragma once

#include <filesystem>

#define MAX_FPS 60
#define FRAME_DELAY (1000 / MAX_FPS)

#define QUIT_VALUE 0
#define OPENING_STAGE_VALUE 1
#define MIDDLE_GAME_STAGE_VALUE 2
#define GAME_OVER_STAGE_VALUE 3
#define PAUSE_STAGE_VALUE 4

#define QUIT SDL_QUIT
#define QUIT_BUTTON SDLK_ESCAPE
#define PAUSE_BUTTON SDLK_t
#define MOVE_DOWN_BUTTON SDLK_DOWN
#define MOVE_UP_BUTTON SDLK_UP
#define MOVE_RIGHT_BUTTON SDLK_RIGHT
#define MOVE_LEFT_BUTTON SDLK_LEFT
#define MOVE_DOWN_BUTTON2 SDLK_s
#define MOVE_UP_BUTTON2 SDLK_w
#define MOVE_RIGHT_BUTTON2 SDLK_d
#define MOVE_LEFT_BUTTON2 SDLK_a
#define SPACESHIP_SHOOT_BUTTON SDLK_SPACE

#define TEXTURE_FILE_EXTENSION ".png"

#define DEFAULT_GAME_TEXT_FONT_SIZE 50
#define DEFAULT_GAME_TEXT_FONT_SIZE_LARGE 200
#define DEFAULT_GAME_TEXT_COLOR SDL_Color{0,255,0,255}
#define DEFAULT_GAME_TEXT_COLOR_2 SDL_Color{175,255,0,255}

namespace fs = std::filesystem;
using path = fs::path;

#define TEXTURE_FILEPATH (path("..") / "ui" / "textures")

#define SPACESHIP1_FILEPATH (TEXTURE_FILEPATH / "spaceship.png").string()
#define SPACESHIP1_DAMAGE_FILEPATH (TEXTURE_FILEPATH / "spaceshipdamage1.png").string()
#define SPACESHIP2_FILEPATH (TEXTURE_FILEPATH / "spaceship2.png").string()
#define SPACESHIP2_DAMAGE_FILEPATH (TEXTURE_FILEPATH / "spaceshipdamage2.png").string()
#define SPACESHIP3_FILEPATH (TEXTURE_FILEPATH / "spaceship3.png").string()
#define SPACESHIP3_DAMAGE_FILEPATH (TEXTURE_FILEPATH / "spaceshipdamage3.png").string()


#define ASTEROIDS_FILEPATH (TEXTURE_FILEPATH / "asteroid").string()
#define CRYSTAL_ASTEROIDS_FILEPATH (TEXTURE_FILEPATH / "crystal-asteroid").string()
#define BACKGROUND_ELEM_FILEPATH (TEXTURE_FILEPATH / "background").string()
#define BLUE_STAR_FILEPATH (TEXTURE_FILEPATH / "bluestar.png").string()
#define GREEN_STAR_FILEPATH (TEXTURE_FILEPATH / "greenstar.png" ).string()
#define PINK_STAR_FILEPATH (TEXTURE_FILEPATH / "pinkstar.png" ).string()
#define GOLD_STAR_FILEPATH (TEXTURE_FILEPATH / "goldstar.png").string()
#define RED_STAR_FILEPATH (TEXTURE_FILEPATH / "redstar.png" ).string()
#define DEFAULT_GAME_TEXT_FONT_PATH (path("..") / "ui" / "text" / "Open 24 Display St.ttf").string()
#define BACKGROUND_MUSIC_FILEPATH (path("..") / "sound" / "background.wav").string()
#define SPACESHIP_SHOOT_SOUND_EFFECT_FILEPATH (path("..") / "sound" / "spaceshipShootSoundeffect.wav").string()

class Config {
public:
    static int windowWidth, windowHeight;
};
