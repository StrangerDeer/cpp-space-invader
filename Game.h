#ifndef CPP_SPACE_INVADER_GAME_H
#define CPP_SPACE_INVADER_GAME_H

#include <SDL.h>
#include <SDL_mixer.h>

#include <iostream>
#include "objects/Player.h"
#include "ui/SpaceshipTexture.h"

class Game {

public:
    Game(){
        initSDL();
        initTexture();
    }

    ~Game(){
        SDL_DestroyWindow(window);
        SDL_DestroyRenderer(renderer);
    }

    void run();

private:
    SDL_Window* window{nullptr};
    SDL_Renderer* renderer{nullptr};
    SDL_Event event;

    bool isRunning{true};

    std::shared_ptr<Player> player{nullptr};

    std::unique_ptr<SpaceshipTexture> playerTexture{nullptr};

    void initSDL();
    void initTexture();
    void handleEvent();
};


#endif //CPP_SPACE_INVADER_GAME_H
