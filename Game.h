#ifndef CPP_SPACE_INVADER_GAME_H
#define CPP_SPACE_INVADER_GAME_H

#include <SDL.h>
#include <SDL_mixer.h>

#include <iostream>
#include <vector>
#include <chrono>

#include "Config.h"

#include "objects/Spaceship.h"
#include "objects/Star.h"
#include "objects/Asteroid.h"
#include "objects/BackgroundElement.h"

#include "ui/objectTextures/BulletTexture.h"
#include "ui/objectTextures/SpaceshipTexture.h"
#include "ui/objectTextures/StarTexture.h"
#include "ui/objectTextures/AsteroidTexture.h"
#include "ui/objectTextures/BackgroundTexture.h"
#include "ui/text/GameText.h"
#include "ui/text/SpaceshipHealthGameText.h"
#include "ui/text/SpaceshipPointGameText.h"

#include "sound/GameMusic.h"
#include "sound/GameSoundEffect.h"
#include "objects/Alien.h"
#include "ui/objectTextures/AlienTexture.h"
#include "objects/HealingItem.h"
#include "ui/objectTextures/HealingItemTexture.h"


template<typename T>
using shared_vector = std::vector<std::shared_ptr<T>>;

class Game {

public:
  Game() {
    lastShootTime = std::chrono::steady_clock::now();
    initSDL();
    initLogic();
    initTexture();
    initSounds();
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

    int windowWidth{0};
    int windowHeight{0};
    int isRunning{1};
    int counter{0};
    Uint32 ticks{0};
    Uint32 frameStart;
    int frameTime;
    std::chrono::steady_clock::time_point lastShootTime;

    //Logic
    shared_vector<Star> stars;
    shared_vector<Asteroid> asteroids;
    shared_vector<DimensionalObject> dimensionalObjects;
    shared_vector<BackgroundElement> backgroundElems;

    shared_vector<Star> pinkStars;
    shared_vector<Star> greenStars;
    shared_vector<Star> blueStars;
    shared_vector<Star> goldStars;
    shared_vector<Star> redStars;

    std::shared_ptr<Spaceship> spaceship{nullptr};
    std::shared_ptr<Alien> alien{nullptr};
    std::shared_ptr<HealingItem> healingItem{nullptr};

    //UI
    std::unique_ptr<SpaceshipTexture> spaceshipTexture{nullptr};
    std::unique_ptr<AlienTexture> alienTexture{nullptr};
    std::unique_ptr<HealingItemTexture> healingItemTexture{nullptr};

    shared_vector<StarTexture> starTextures{};
    shared_vector<AsteroidTexture> asteroidTextures{};
    shared_vector<BulletTexture> spaceshipBulletsTexture{};
    shared_vector<BulletTexture> alienBulletsTexture{};
    shared_vector<BackgroundTexture> backgroundTextures{};

    shared_vector<GameText> texts;

    //Sounds
    std::unique_ptr<GameMusic> backgroundMusic{nullptr};
    std::unique_ptr<GameSoundEffect> spaceshipShootSoundEffect{nullptr};
    std::unique_ptr<GameSoundEffect> starPickUpSoundEffect{nullptr};
    std::unique_ptr<GameSoundEffect> objectHitByBullet{nullptr};
    std::unique_ptr<GameSoundEffect> asteroidExplodes{nullptr};

    void initSDL();
    void initLogic();
    void initTexture();
    void initSounds();
    void openStage();
    void middleGameStage();
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
                          shared_vector<Star> &starVector);
    void initOneKindOfAsteroids(int numberOfAsteroids,
                              int windowWidth,
                              int windowHeight,
                              int maxHp,
                              int width,
                              int height,
                              int minSpeed,
                              int maxSpeed,
                              int point);

  void initBackgroundElements(int numberOfElems,
                              int windowWidth,
                              int windowHeight,
                              int width,
                              int height,
                              int minSpeed,
                              int maxSpeed);

  void initStarTextures();
  void initAsteroidTextures();
  void initBackgroundElemTextures();

  void handleCollisions();

  void makeObjectsMove();

  void gameOverStage();

  void clearObjects();

  void clearTextures();
};

#endif //CPP_SPACE_INVADER_GAME_H
