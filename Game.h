#ifndef CPP_SPACE_INVADER_GAME_H
#define CPP_SPACE_INVADER_GAME_H

#include <SDL.h>

#include <iostream>
#include "objects/Spaceship.h"
#include "ui/objectTextures/SpaceshipTexture.h"
#include "objects/Star.h"
#include "ui/objectTextures/BlueStarTexture.h"
#include "objects/Asteroid.h"
#include "ui/objectTextures/AsteroidTexture.h"
#include <vector>

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

    std::shared_ptr<Spaceship> spaceship{nullptr};
    std::shared_ptr<Asteroid> asteroid1{nullptr};
    std::shared_ptr<Star> blueStar1{nullptr};
    std::shared_ptr<Star> blueStar2{nullptr};
    std::shared_ptr<Star> blueStar3{nullptr};
    std::vector<std::shared_ptr<Star>> stars{};

    std::unique_ptr<SpaceshipTexture> spaceshipTexture{nullptr};
    std::shared_ptr<AsteroidTexture> asteroidTexture1{nullptr};
    std::shared_ptr<BlueStarTexture> blueStarTexture1{nullptr};
    std::shared_ptr<BlueStarTexture> blueStarTexture2{nullptr};
    std::shared_ptr<BlueStarTexture> blueStarTexture3{nullptr};
    std::vector<std::shared_ptr<BlueStarTexture>> starTextures{};

    void initSDL();
    void initTexture();
    void handleEvent();
};


#endif //CPP_SPACE_INVADER_GAME_H
