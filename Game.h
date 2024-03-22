#ifndef CPP_SPACE_INVADER_GAME_H
#define CPP_SPACE_INVADER_GAME_H

#include <SDL.h>
#include <SDL_mixer.h>

#include <iostream>
#include <vector>
#include <chrono>

#include "objects/Spaceship.h"
#include "objects/Star.h"
#include "objects/Asteroid.h"

#include "ui/objectTextures/BulletTexture.h"
#include "ui/objectTextures/SpaceshipTexture.h"
#include "ui/objectTextures/StarTexture.h"
#include "ui/objectTextures/AsteroidTexture.h"
#include "ui/text/GameText.h"
#include "ui/text/SpaceshipHealthGameText.h"
#include "ui/text/SpaceshipPointGameText.h"

#include "sound/GameMusic.h"
#include "sound/GameSoundEffect.h"

template<typename T>
using shared_vector = std::vector<std::shared_ptr<T>>;

class Game {

public:
  Game() {
    lastShootTime = std::chrono::steady_clock::now();
    initSDL();
    initLogic();
    initTexture();
  }

  ~Game() {
    SDL_DestroyWindow(window);
    SDL_DestroyRenderer(renderer);
    SDL_Quit();
  }

  void run();

private:
    SDL_Window *window{nullptr};
    SDL_Renderer *renderer{nullptr};
    SDL_Event event;

    bool isRunning{true};
    std::chrono::steady_clock::time_point lastShootTime;

    shared_vector<GameText> texts;

    std::vector<std::shared_ptr<Star>> stars;
    std::vector<std::shared_ptr<Asteroid>> asteroids;
    std::vector<std::shared_ptr<DimensionalObject>> dimensionalObjects;

    std::vector<std::shared_ptr<Star>> pinkStars;
    std::vector<std::shared_ptr<Star>> greenStars;
    std::vector<std::shared_ptr<Star>> blueStars;
    std::vector<std::shared_ptr<Star>> goldStars;
    std::vector<std::shared_ptr<Star>> redStars;

    std::unique_ptr<GameMusic> backgroundMusic{nullptr};
    std::unique_ptr<GameSoundEffect> spaceshipShootSoundEffect{nullptr};

    std::shared_ptr<Spaceship> spaceship{nullptr};

    std::unique_ptr<SpaceshipTexture> spaceshipTexture{nullptr};
    std::vector<std::shared_ptr<StarTexture>> starTextures{};
    std::vector<std::shared_ptr<AsteroidTexture>> asteroidTextures{};
    shared_vector<BulletTexture> spaceshipBulletsTexture{};

    void initSDL();
    void initLogic();
    void initTexture();
    void handleEvent();
    void printTexture();

    void initOneKindOfStars(int numberOfStars,
                          int windowWidth,
                          int windowHeight,
                          int starWidth,
                          int starHeight,
                          int minSpeed,
                          int maxSpeed,
                          int point,
                          std::vector<std::shared_ptr<Star>> &starVector);
    void initOneKindOfAsteroids(int numberOfAsteroids,
                              int windowWidth,
                              int windowHeight,
                              int maxHp,
                              int width,
                              int height,
                              int minSpeed,
                              int maxSpeed,
                              int point);

    void initStarTextures();
    void initAsteroidTextures();
    void handleCollisions();

    void makeObjectsFall();
};

#endif //CPP_SPACE_INVADER_GAME_H
