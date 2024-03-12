
#include "Game.h"

void Game::run() {

    while(isRunning){
        handleEvent();
        SDL_RenderClear(renderer);
        Uint32 ticks = SDL_GetTicks();
        spaceshipTexture->print(renderer, ticks);
        asteroidTexture1->print(renderer, ticks);

        for(std::shared_ptr<BlueStarTexture> starTexture : starTextures) {
            starTexture->print(renderer, ticks);
        }
        for (std::shared_ptr<Star> star : stars) {
            star->fall();
        }
        SDL_RenderPresent(renderer);
        SDL_Delay(25);
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

    //TODO: move these into initLogic
    spaceship = std::make_shared<Spaceship>(1, 1, 200, 200, 300, 400, 1, 1);
    asteroid1 = std::make_shared<Asteroid>(1, 1, 500, 200, 350, 350, 1, 1, true, 1);
    blueStar1 = std::make_shared<Star>(500, 200, 55, 150, 10, 30, true, 10);
    blueStar2 = std::make_shared<Star>(400, 0, 55, 150, 15, 35, true, 10);
    blueStar3 = std::make_shared<Star>(600, -50, 55, 150, 7, 20, true, 10);
    stars = {blueStar1, blueStar2, blueStar3};
}

void Game::handleEvent() {
    while (SDL_PollEvent(&event)){
        if(event.type == SDL_QUIT || event.key.keysym.sym == SDLK_ESCAPE){
            isRunning = false;
        }

    }
}

void Game::initTexture() {
    spaceshipTexture = std::make_unique<SpaceshipTexture>(renderer, spaceship);
    asteroidTexture1 = std::make_shared<AsteroidTexture>(renderer, asteroid1);
    blueStarTexture1 = std::make_shared<BlueStarTexture>(renderer, blueStar1);
    blueStarTexture2 = std::make_shared<BlueStarTexture>(renderer, blueStar2);
    blueStarTexture3 = std::make_shared<BlueStarTexture>(renderer, blueStar3);
    starTextures = {blueStarTexture1, blueStarTexture2, blueStarTexture3};
}
