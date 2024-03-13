#ifndef CPP_SPACE_INVADER_GAME_H
#define CPP_SPACE_INVADER_GAME_H

#include <SDL.h>
#include <SDL_mixer.h>

#include <iostream>
#include "objects/Spaceship.h"
#include "ui/objectTextures/SpaceshipTexture.h"
#include "objects/Star.h"
#include "ui/objectTextures/StarTexture.h"
#include "objects/Asteroid.h"
#include "ui/objectTextures/AsteroidTexture.h"
#include "sound/BackgroundMusic.h"
#include "ui/text/GameText.h"
#include "ui/text/SpaceshipHealthGameText.h"
#include <vector>

template<typename T>
using shared_vector = std::vector<std::shared_ptr<T>>;

class Game {

public:
  Game() {
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

    shared_vector<GameText> texts;

    std::vector<std::shared_ptr<Star>> stars;
    std::vector<std::shared_ptr<Asteroid>> asteroids;
    std::vector<std::shared_ptr<DimensionalObject>> dimensionalObjects;

    std::vector<std::shared_ptr<Star>> pinkStars;
    std::vector<std::shared_ptr<Star>> greenStars;
    std::vector<std::shared_ptr<Star>> blueStars;
    std::vector<std::shared_ptr<Star>> goldStars;
    std::vector<std::shared_ptr<Star>> redStars;

    bool isRunning{true};

    std::unique_ptr<BackgroundMusic> backgroundMusic{nullptr};

    std::shared_ptr<Spaceship> spaceship{nullptr};

    std::unique_ptr<SpaceshipTexture> spaceshipTexture{nullptr};

    std::vector<std::shared_ptr<StarTexture>> starTextures{};
    std::vector<std::shared_ptr<AsteroidTexture>> asteroidTextures{};

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
};

#endif //CPP_SPACE_INVADER_GAME_H
