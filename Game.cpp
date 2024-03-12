#include "Game.h"

void Game::run() {

    while(isRunning){
        handleEvent();
        SDL_RenderClear(renderer);
        playerTexture->print(renderer);
        SDL_RenderPresent(renderer);
    }
}

void Game::initSDL() {
    window = SDL_CreateWindow("Space Invader", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 1000,1000,
                              SDL_WINDOW_ALLOW_HIGHDPI | SDL_WINDOW_OPENGL);
    if (!window) {
        std::cerr << "Error: Unable to create window!" << SDL_GetError() << std::endl;
        return;
    }

    renderer = SDL_CreateRenderer(window, -1,SDL_RENDERER_ACCELERATED);

    if (!renderer) {
        std::cerr << "Error: Unable to create renderer!" << SDL_GetError() << std::endl;
        return;
    }
}

void Game::handleEvent() {
    while (SDL_PollEvent(&event)){
        if(event.type == SDL_QUIT || event.key.keysym.sym == SDLK_ESCAPE){
            isRunning = false;
        }

    }
}

void Game::initTexture() {

    playerTexture = std::make_unique<SpaceshipTexture>(renderer,player);

}