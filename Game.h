#ifndef CPP_SPACE_INVADER_GAME_H
#define CPP_SPACE_INVADER_GAME_H

#include <SDL.h>

#include <iostream>

class Game {

public:
    Game(){
        initSDL();
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

    void initSDL();
    void handleEvent();
};


#endif //CPP_SPACE_INVADER_GAME_H
