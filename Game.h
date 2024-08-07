#ifndef CPP_SPACE_INVADER_GAME_H
#define CPP_SPACE_INVADER_GAME_H

#include <SDL.h>
#include <SDL_mixer.h>

#define CPPHTTPLIB_OPENSSL_SUPPORT
#include "httplib.h"

#include <iostream>
#include <vector>
#include <chrono>

#include "Config.h"
#include "ConfigGameItems.h"

#include "objects/Spaceship.h"
#include "objects/Star.h"
#include "objects/Asteroid.h"
#include "objects/BackgroundElement.h"
#include "objects/Alien.h"
#include "objects/HealingItem.h"
#include "objects/GunBoosterItem.h"

#include "ui/objectTextures/BulletTexture.h"
#include "ui/objectTextures/SpaceshipTexture.h"
#include "ui/objectTextures/StarTexture.h"
#include "ui/objectTextures/AsteroidTexture.h"
#include "ui/objectTextures/BackgroundTexture.h"
#include "ui/objectTextures/HealingItemTexture.h"
#include "ui/objectTextures/AlienTexture.h"
#include "ui/objectTextures/GunBoosterTexture.h"
#include "ui/text/GameText.h"
#include "ui/text/SpaceshipHealthGameText.h"
#include "ui/text/SpaceshipPointGameText.h"
#include "ui/text/SpaceshipGunLvlGameText.h"

#include "sound/GameMusic.h"
#include "sound/GameSoundEffect.h"
#include "game-stages/OpenStage.h"
#include "objects/FireLineItem.h"
#include "ui/objectTextures/FireLineBoosterTexture.h"
#include "objects/StarItem.h"
#include "ui/objectTextures/StarItemTexture.h"
#include "ui/objectTextures/ShieldItemTexture.h"
#include "objects/Shield.h"
#include "ui/objectTextures/ShieldTexture.h"
#include "ui/objectTextures/TimeSlowingItemTexture.h"
#include "objects/Explosion.h"
#include "ui/objectTextures/ExplosionTexture.h"

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
    initOpenStage();
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

    std::shared_ptr<int> isRunning{std::make_shared<int>(1)};
    int counter{0};
    Uint32 ticks{0};
    Uint32 frameStart;
    int frameTime;
    std::chrono::steady_clock::time_point lastShootTime;
    int elapsedTime;

    std::unique_ptr<OpenStage> openStage{nullptr};

    //Logic
    shared_vector<FallingObject> fallingObjects;
    shared_vector<Star> stars;
    shared_vector<Asteroid> asteroids;
    //shared_vector<DimensionalObject> dimensionalObjects;
    shared_vector<BackgroundElement> backgroundElems;
    shared_vector<Asteroid> crystalAsteroids;
    shared_vector<Explosion> explosions;

    std::shared_ptr<Spaceship> spaceship{nullptr};
    std::shared_ptr<Alien> alien{nullptr};
    std::shared_ptr<Shield> shield{nullptr};

    std::shared_ptr<GunBoosterItem> gunBooster{nullptr};
    std::shared_ptr<FireLineItem> fireLineBooster{nullptr};
    std::shared_ptr<PickUpItem> shieldItem{nullptr};
    shared_vector<PickUpItem> alienPickUps{};

    std::shared_ptr<HealingItem> healingItem{nullptr};
    std::shared_ptr<StarItem> starItem{nullptr};
    std::shared_ptr<PickUpItem> timeSlowingItem{nullptr};
    shared_vector<PickUpItem> crystalPickUps{};

    //UI
    std::shared_ptr<SpaceshipTexture> currentSpaceshipTexture{nullptr};
    std::shared_ptr<SDL_Color> currentSpaceshipBulletColor{nullptr};

    std::unique_ptr<AlienTexture> alienTexture{nullptr};

    std::unique_ptr<ShieldTexture> shieldTexture{nullptr};

    std::unique_ptr<HealingItemTexture> healingItemTexture{nullptr};
    std::unique_ptr<GunBoosterTexture> gunBoosterTexture{nullptr};
    std::unique_ptr<FireLineBoosterTexture> fireLineBoosterTexture{nullptr};
    std::unique_ptr<StarItemTexture> starItemTexture{nullptr};
    std::unique_ptr<ShieldItemTexture> shieldItemTexture{nullptr};
    std::unique_ptr<TimeSlowingItemTexture> timeSlowingItemTexture{nullptr};

    shared_vector<StarTexture> starTextures{};
    shared_vector<AsteroidTexture> asteroidTextures{};
    shared_vector<BulletTexture> spaceshipBulletsTexture{};
    shared_vector<BulletTexture> alienBulletsTexture{};
    shared_vector<BackgroundTexture> backgroundTextures{};
    shared_vector<ExplosionTexture> explosionTextures{};

    shared_vector<GameText> texts;

    //Sounds
    std::unique_ptr<GameMusic> backgroundMusic{nullptr};
    std::unique_ptr<GameSoundEffect> spaceshipShootSoundEffect{nullptr};
    std::unique_ptr<GameSoundEffect> starPickUpSoundEffect{nullptr};
    std::unique_ptr<GameSoundEffect> objectHitByBullet{nullptr};
    std::unique_ptr<GameSoundEffect> asteroidExplodes{nullptr};
    std::unique_ptr<GameSoundEffect> healingPickUp{nullptr};

    void initSDL();
    void initLogic();
    void initTexture();
    void initSounds();

    void initOpenStage();

    void middleGameStage();
    void handleMiddleGameEvent();
    void pauseStage();
    void handlePauseEvent();
    void printTexture();

    void initStars();
    void initAsteroids();
    void initUniqueObjects();

    void initBackgroundElements();
    std::shared_ptr<BackgroundElement> generateBackgroundElement(int &yPos);

    void initStarTextures();
    void initAsteroidTextures();
    void initBackgroundElemTextures();
    void updateTextures();

    void handleCollisions();
    void makeObjectsMove();
    void gameOverStage();

    void clearObjects();
    void clearTextures();

    void increaseGameDifficulty() const;

    void spaceshipTakesDamage();
    void checkGameOver() const;
    void makeAlienShoot();
    void moveBullets();

    void printPauseTexts() const;
    void initInfoTexts();

    void initUniqueTextures();
    void reduceObjectSpeed();

    void handlePickUpCollisions(SDL_Rect &spaceshipRect);

    void createExplosion(int x, int y, int w, int h);
    void eraseExplosions();

    void TestTexture(SDL_Renderer* renderer);

    void postResultToWebPage();

    void handleGameOverEvent();

    void printGameOverTexts() const;
};

#endif //CPP_SPACE_INVADER_GAME_H
