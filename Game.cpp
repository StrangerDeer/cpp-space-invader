#include "Game.h"
#include "ui/text/SpaceshipTravelSpeedGameText.h"

void Game::run() {

  backgroundMusic->playMusic();

  while(*isRunning != QUIT_VALUE){
    frameStart = SDL_GetTicks();

    switch(*isRunning){
        case OPENING_STAGE_VALUE: openStage->run(renderer); break;
        case MIDDLE_GAME_STAGE_VALUE: middleGameStage(); break;
        case GAME_OVER_STAGE_VALUE: gameOverStage(); break;
        default:;
    }

    frameTime = SDL_GetTicks() - frameStart;

    if(FRAME_DELAY > frameTime){
      SDL_Delay(FRAME_DELAY - frameTime);
    }
  }
}

void Game::middleGameStage() {
    handleEvent();
    handleCollisions();
    makeObjectsMove();
    printTexture();

    increaseGameDifficulty();

    if(spaceship->getHealth() <= 0){
        *isRunning = 3;
    }
}

void Game::increaseGameDifficulty() const {
    static int gameDifficulty = 0;
    int diffIncrease = spaceship->getPoints() / 500;
    if (diffIncrease > gameDifficulty) {
        gameDifficulty = diffIncrease;
        spaceship->increaseTravelSpeed();
        alien->increaseDifficulty();

        for(const std::shared_ptr<FallingObject> object : fallingObjects){
            object->increaseSpeed();
        }

        if (gameDifficulty % 2) {
            for (const std::shared_ptr<Asteroid> asteroid : asteroids) {
                asteroid->increaseHealth();
            }
        }
    }
}

void Game::makeObjectsMove() {
  for(const std::shared_ptr<FallingObject> object : fallingObjects){
    object->fall();
  }

  for(const std::shared_ptr<FallingObject> bgElem : backgroundElems) {
      bgElem->fall();
  }

  alien->fall();

  healingItem->fall();
  gunBooster->fall();
  fireLineBooster->fall();

  bool isAlienShooting = alien->decideIfShooting();
  if (isAlienShooting) {
    std::shared_ptr<AlienBullet> bullet = alien->shoot();
    std::shared_ptr<BulletTexture> alienBulletTexture = std::make_shared<BulletTexture>(renderer, bullet, SDL_Color{255, 0, 0, 255});
    alienBulletsTexture.push_back(alienBulletTexture);
  }

  if (!alien->bullets.empty()){
    for(int i = 0; i < alien->bullets.size(); i++) {
      std::shared_ptr<AlienBullet> bullet = alien->bullets.at(i);
      bullet->move();
      if(bullet->bulletRect.y > Config::windowHeight){
        alien->bullets.erase(alien->bullets.begin() + i);
        alienBulletsTexture.erase(alienBulletsTexture.begin() + i);
      }
    }
  }

  if(!spaceship->bullets.empty()){
    for(int i = 0; i < spaceship->bullets.size(); i++){
      std::shared_ptr<SpaceshipBullet> bullet = spaceship->bullets.at(i);
      bullet->move();
      if(bullet->bulletRect.y < 0){
        spaceship->bullets.erase(spaceship->bullets.begin() + i);
        spaceshipBulletsTexture.erase(spaceshipBulletsTexture.begin() + i);
      }
    }
  }
}

void Game::initSDL() {
  SDL_Init(SDL_INIT_EVERYTHING);

  window = SDL_CreateWindow("Stellar Storm", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 1000, 1000,
                            SDL_WINDOW_ALLOW_HIGHDPI | SDL_WINDOW_OPENGL);
  if (!window) {
    std::cerr << "Error: Unable to create window!" << SDL_GetError() << std::endl;
    return;
  }

  SDL_SetWindowFullscreen(window, SDL_WINDOW_FULLSCREEN_DESKTOP);

  int windowWidth, windowHeight;
  SDL_GetWindowSize(window, &windowWidth, &windowHeight);
  Config::windowWidth = windowWidth;
  Config::windowHeight = windowHeight;

  if(Config::windowWidth == 0 || Config::windowHeight == 0){
      std::cerr << "Window size could not  initialised!" << std::endl;
      return;
  }

  renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);

  if (!renderer) {
    std::cerr << "Error: Unable to create renderer!" << SDL_GetError() << std::endl;
    return;
  }

  openStage = std::make_unique<OpenStage>(renderer, isRunning);

  if(!openStage){
    std::cerr << "Error: Open Stage couldn't create!"  << std::endl;
    return;
  }

}

void Game::initSounds() {
  backgroundMusic = std::make_unique<GameMusic>(BACKGROUND_MUSIC_FILEPATH);
  spaceshipShootSoundEffect = std::make_unique<GameSoundEffect>(SPACESHIP_SHOOT_SOUND_EFFECT_FILEPATH);
  starPickUpSoundEffect = std::make_unique<GameSoundEffect>("../sound/star_pick_up.wav");
  objectHitByBullet = std::make_unique<GameSoundEffect>("../sound/asteroid_hit_by_bullet.wav");
  asteroidExplodes = std::make_unique<GameSoundEffect>("../sound/asteroid_explodes.wav");
  healingPickUp = std::make_unique<GameSoundEffect>("../sound/healing_pick_up.wav");
}

void Game::initLogic() {

  clearObjects();

  initBackgroundElements();
  initStars();
  initAsteroids();

  spaceship = std::make_shared<Spaceship>(10, 75, Config::windowWidth * 0.5 - 50, Config::windowHeight * 0.85, 100, 100, 3);

  alien = std::make_shared<Alien>(5, Config::windowWidth * 0.5, Config::windowHeight * -15, 50);

  healingItem = std::make_shared<HealingItem>(0, 0, alien->rect.w, alien->rect.h);
  gunBooster = std::make_shared<GunBoosterItem>(0, 0, alien->rect.w, alien->rect.h);
  fireLineBooster = std::make_shared<FireLineItem>(0, 0, alien->rect.w, alien->rect.h);
}

void Game::clearObjects() {
    if(spaceship){
        spaceship = nullptr;
    }

    if (alien) {
        alien = nullptr;
    }

    if (healingItem) {
        healingItem = nullptr;
    }

    if (gunBooster) {
        gunBooster = nullptr;
    }

    if (fireLineBooster) {
        fireLineBooster = nullptr;
    }

    if(!stars.empty()){
      stars.clear();
    }

    if(!asteroids.empty()){
      asteroids.clear();
    }

    if(!crystalAsteroids.empty()) {
        crystalAsteroids.clear();
    }

    //if(!dimensionalObjects.empty()){
      //dimensionalObjects.clear();
    //}

    if(!backgroundElems.empty()){
      backgroundElems.clear();
    }
}

void Game::handleEvent() {
  while (SDL_PollEvent(&event)) {
    if (event.type == QUIT || event.key.keysym.sym == QUIT_BUTTON) {
      *isRunning = 0;
    }

    if(event.type == SDL_KEYDOWN){
      switch (event.key.keysym.sym) {
          case MOVE_DOWN_BUTTON2:
        case MOVE_DOWN_BUTTON:
          if(spaceship->rect.y + 50 + spaceship->height < Config::windowHeight){
            spaceship->moveDown();
          }
          break;
          case MOVE_UP_BUTTON2:
        case MOVE_UP_BUTTON:
          if(spaceship->rect.y + 50 > 0 + spaceship->height) {
            spaceship->moveUp();
          }
          break;
          case MOVE_RIGHT_BUTTON2:
        case MOVE_RIGHT_BUTTON:
          if(spaceship->rect.x + 60 + spaceship->width < Config::windowWidth){
            spaceship->moveRight();
          }
          break;
          case MOVE_LEFT_BUTTON2:
        case MOVE_LEFT_BUTTON:
          if(spaceship->rect.x + 50 > 0 + spaceship->width) {
            spaceship->moveLeft();
          }
          break;

        case SPACESHIP_SHOOT_BUTTON:
            auto now = std::chrono::steady_clock::now();
            auto timeSinceLastShoot = std::chrono::duration_cast<std::chrono::milliseconds>(now - lastShootTime).count();

            if(timeSinceLastShoot >= (1.0 / spaceship->getFirerate()) * 1000){
                std::vector<std::shared_ptr<SpaceshipBullet>> bullets = spaceship->shoot();
                for (std::shared_ptr<SpaceshipBullet> bullet : bullets) {
                    std::shared_ptr<BulletTexture> spaceShipBulletTexture = std::make_shared<BulletTexture>(renderer, bullet, SDL_Color{0, 255, 175, 255});
                    spaceshipBulletsTexture.push_back(spaceShipBulletTexture);
                }
              spaceshipShootSoundEffect->playSoundEffect();
              lastShootTime = now;
            }
          break;
      }
    }
  }
}

void Game::initTexture() {

    clearTextures();

    initBackgroundElemTextures();
    initStarTextures();
    initAsteroidTextures();

    std::shared_ptr<GameText> livesText = std::make_shared<GameText>("Health: ",
                                                                     DEFAULT_GAME_TEXT_FONT_PATH,
                                                                     DEFAULT_GAME_TEXT_FONT_SIZE,
                                                                     DEFAULT_GAME_TEXT_COLOR, 20,Config::windowHeight * 0.87,
                                                                     renderer);
    std::shared_ptr<SpaceshipHealthGameText> spaceHealthText =
        std::make_shared<SpaceshipHealthGameText>(renderer, spaceship,
                                                  DEFAULT_GAME_TEXT_FONT_PATH,
                                                  DEFAULT_GAME_TEXT_FONT_SIZE,
                                                  DEFAULT_GAME_TEXT_COLOR, 175,Config::windowHeight * 0.87);

    std::shared_ptr<GameText> lvlText = std::make_shared<GameText>("Gun Lvl: ",
                                                                   DEFAULT_GAME_TEXT_FONT_PATH,
                                                                   DEFAULT_GAME_TEXT_FONT_SIZE,
                                                                   DEFAULT_GAME_TEXT_COLOR, 20, Config::windowHeight * 0.93,
                                                                   renderer);

    std::shared_ptr<SpaceshipGunLvlGameText> spaceLvlText =
            std::make_shared<SpaceshipGunLvlGameText>(renderer, spaceship,
                                                      DEFAULT_GAME_TEXT_FONT_PATH,
                                                      DEFAULT_GAME_TEXT_FONT_SIZE,
                                                      DEFAULT_GAME_TEXT_COLOR, 195,Config::windowHeight * 0.93);

    std::shared_ptr<SpaceshipPointGameText> spacePointText = std::make_shared<SpaceshipPointGameText>(
                                                renderer, spaceship,
                                                DEFAULT_GAME_TEXT_FONT_PATH,
                                                DEFAULT_GAME_TEXT_FONT_SIZE,
                                                DEFAULT_GAME_TEXT_COLOR,
                                                Config::windowWidth - 100,
                                                Config::windowHeight * 0.02);

    std::shared_ptr<GameText> travelSpeedText = std::make_shared<GameText>("Travelling at ",
                                                                   DEFAULT_GAME_TEXT_FONT_PATH,
                                                                   DEFAULT_GAME_TEXT_FONT_SIZE,
                                                                   DEFAULT_GAME_TEXT_COLOR,
                                                                   Config::windowWidth - 280,
                                                                   Config::windowHeight * 0.87,
                                                                   renderer);

    std::shared_ptr<SpaceshipTravelSpeedGameText> spaceTravelSpeed =
            std::make_shared<SpaceshipTravelSpeedGameText>(renderer, spaceship,
                                                      DEFAULT_GAME_TEXT_FONT_PATH,
                                                      DEFAULT_GAME_TEXT_FONT_SIZE,
                                                      DEFAULT_GAME_TEXT_COLOR,
                                                      Config::windowWidth - 280,
                                                      Config::windowHeight * 0.93);

    texts.push_back(livesText);
    texts.push_back(spaceHealthText);
    texts.push_back(lvlText);
    texts.push_back(spaceLvlText);
    texts.push_back(spacePointText);
    texts.push_back(travelSpeedText);
    texts.push_back(spaceTravelSpeed);

    spaceshipTexture = std::make_shared<SpaceshipTexture>(renderer, spaceship);
    alienTexture = std::make_unique<AlienTexture>(renderer, alien);
    healingItemTexture = std::make_unique<HealingItemTexture>(renderer, healingItem);
    gunBoosterTexture = std::make_unique<GunBoosterTexture>(renderer, gunBooster);
    fireLineBoosterTexture = std::make_unique<FireLineBoosterTexture>(renderer, fireLineBooster);

    openStage->addTexture(spaceshipTexture);
}

void Game::clearTextures() {
    if(!backgroundTextures.empty()) {
        backgroundTextures.clear();
    }

    if(spaceshipTexture){
        spaceshipTexture = nullptr;
    }

    if (alienTexture) {
        alienTexture = nullptr;
    }

    if (healingItemTexture) {
        healingItemTexture = nullptr;
    }

    if (gunBoosterTexture) {
        gunBoosterTexture = nullptr;
    }

    if (fireLineBoosterTexture) {
        fireLineBoosterTexture = nullptr;
    }

    if(!starTextures.empty()){
      starTextures.clear();
    }

    if(!asteroidTextures.empty()){
      asteroidTextures.clear();
    }

    if(!spaceshipBulletsTexture.empty()){
      spaceshipBulletsTexture.clear();
    }

    if(!alienBulletsTexture.empty()) {
        alienBulletsTexture.clear();
    }


    if(!texts.empty()){
      texts.clear();
    }
}

void Game::initBackgroundElemTextures() {
    std::vector<int> usedIndexes = {};
    int randomIndex = Util::getRandomNumber(1, 10);
    for (const std::shared_ptr<BackgroundElement> &elem : backgroundElems) {
        while ((std::find(usedIndexes.begin(), usedIndexes.end(), randomIndex) != usedIndexes.end())) {
            randomIndex = Util::getRandomNumber(1, 10);
        }
        usedIndexes.push_back(randomIndex);
        std::string filepath = BACKGROUND_ELEM_FILEPATH + std::to_string(randomIndex) + TEXTURE_FILE_EXTENSION;
        std::shared_ptr<BackgroundTexture> backgroundTexture = std::make_shared<BackgroundTexture>(renderer, elem, filepath);
        backgroundTextures.push_back(backgroundTexture);
    }
}

void Game::initAsteroidTextures() {
  for (const std::shared_ptr<Asteroid> &asteroid : asteroids) {
    int randomIndex = Util::getRandomNumber(1, 5);
    std::string filepath = ASTEROIDS_FILEPATH + std::to_string(randomIndex) + TEXTURE_FILE_EXTENSION;
    std::shared_ptr<AsteroidTexture> asteroidTexture = std::make_shared<AsteroidTexture>(renderer, asteroid, filepath);
    asteroidTextures.push_back(asteroidTexture);
  }


    int index = 1;
  for (const std::shared_ptr<Asteroid> &asteroid : crystalAsteroids) {
      std::string filepath = CRYSTAL_ASTEROIDS_FILEPATH + std::to_string(index) + TEXTURE_FILE_EXTENSION;
      std::shared_ptr<AsteroidTexture> crystalAsteroidTexture = std::make_shared<AsteroidTexture>(renderer, asteroid, filepath);
      asteroidTextures.push_back(crystalAsteroidTexture);
      index++;
  }
}

void Game::initStarTextures() {

  for(const std::shared_ptr<Star> star : stars){
    std::shared_ptr<StarTexture> starTexture = nullptr;

    switch (star->textureId) {
      case PINK_STAR_TEXTURE_ID:
        starTexture = std::make_shared<StarTexture>(renderer, star, PINK_STAR_FILEPATH);
        break;
      case GREEN_STAR_TEXTURE_ID:
        starTexture = std::make_shared<StarTexture>(renderer, star, GREEN_STAR_FILEPATH);
        break;
      case BLUE_STAR_TEXTURE_ID:
        starTexture = std::make_shared<StarTexture>(renderer, star, BLUE_STAR_FILEPATH);
        break;
      case GOLD_STAR_TEXTURE_ID:
        starTexture = std::make_shared<StarTexture>(renderer, star, GOLD_STAR_FILEPATH);
        break;
      case RED_STAR_TEXTURE_ID:
        starTexture = std::make_shared<StarTexture>(renderer, star, RED_STAR_FILEPATH);
        break;
      default:;
    }

    starTextures.push_back(starTexture);
  }
}

void Game::handleCollisions() {

  SDL_Rect spaceshipRect{spaceship->rect.x, spaceship->rect.y, spaceship->width, spaceship->height};
  SDL_Rect healingItemRect{healingItem->rect.x, healingItem->rect.y, healingItem->width, healingItem->height};
  SDL_Rect gunBoosterRect{gunBooster->rect.x, gunBooster->rect.y, gunBooster->width, gunBooster->height};
  SDL_Rect fireLineBoosterRect{fireLineBooster->rect.x, fireLineBooster->rect.y, fireLineBooster->width, fireLineBooster->height};

    if (SDL_HasIntersection(&spaceshipRect, &fireLineBoosterRect)) {
        fireLineBooster->removeFromScreen();
        fireLineBooster->increaseSpaceshipFireLine(spaceship);
        healingPickUp->playSoundEffect();
        alien->increaseDifficulty();
        for(const std::shared_ptr<Asteroid> asteroid : asteroids) {
            asteroid->increaseHealth();
        }
    }

  if (SDL_HasIntersection(&spaceshipRect, &gunBoosterRect)) {
      gunBooster->removeFromScreen();
      gunBooster->increaseSpaceshipFireRate(spaceship);
      alien->increaseDifficulty();
      for(const std::shared_ptr<Asteroid> asteroid : asteroids) {
          asteroid->increaseHealth();
      }
      healingPickUp->playSoundEffect();
  }

  if (SDL_HasIntersection(&spaceshipRect, &healingItemRect)) {
      healingItem->removeFromScreen();
      healingItem->healSpaceship(spaceship);
      healingPickUp->playSoundEffect();
  }

  for (auto &asteroid : asteroids) {

    SDL_Rect asteroidRect{asteroid->rect.x, asteroid->rect.y, asteroid->width, asteroid->height};

    if (SDL_HasIntersection(&spaceshipRect, &asteroidRect)) {
      asteroid->reset();
      asteroidExplodes->playSoundEffect();
      spaceship->takeDamage();
    }
  }

  for (auto &crystalAst : crystalAsteroids) {
      SDL_Rect crystalAstRect{crystalAst->rect.x, crystalAst->rect.y, crystalAst->width, crystalAst->height};

      if (SDL_HasIntersection(&spaceshipRect, &crystalAstRect)) {
          crystalAst->reset();
          asteroidExplodes->playSoundEffect();
          spaceship->takeDamage();
      }
  }

  for (auto &star : stars) {

    SDL_Rect starRect{star->rect.x, star->rect.y, star->width, star->height};

    if (SDL_HasIntersection(&spaceshipRect, &starRect)) {
      starPickUpSoundEffect->playSoundEffect();
      star->placeAtStartingPos();
      star->givePoints(spaceship);
    }
  }

  if(!alien->bullets.empty()) {
      for (int i = 0; i < alien->bullets.size(); i++) {
          std::shared_ptr<AlienBullet> bullet = alien->bullets.at(i);
          SDL_Rect bulletRect{bullet->bulletRect.x, bullet->bulletRect.y, bullet->width, bullet->height};

          if (SDL_HasIntersection(&bulletRect, &spaceshipRect)) {
              spaceship->takeDamage();
              asteroidExplodes->playSoundEffect();
              alien->bullets.erase(alien->bullets.begin() + i);
              alienBulletsTexture.erase(alienBulletsTexture.begin() + i);
          }
      }
  }


    restartLoop:
  if(!spaceship->bullets.empty()){
    for(int i = 0; i < spaceship->bullets.size(); i++){
      std::shared_ptr<SpaceshipBullet> bullet = spaceship->bullets.at(i);
      SDL_Rect bulletRect{bullet->bulletRect.x, bullet->bulletRect.y, bullet->width, bullet->height};

      if (alien->rect.y + alien->height >= 0) {
          SDL_Rect alienRect{alien->rect.x, alien->rect.y, alien->width, alien->height};

          if (SDL_HasIntersection(&bulletRect, &alienRect)) {
              alien->takeDamage();
              objectHitByBullet->playSoundEffect();
              spaceship->bullets.erase(spaceship->bullets.begin() + i);
              spaceshipBulletsTexture.erase(spaceshipBulletsTexture.begin() + i);
              int alienX = alien->rect.x;
              int alienY = alien->rect.y;

              if (alien->isDead()) {
                  alien->givePoints(spaceship);
                  pickUps.clear();
                  pickUps.push_back(healingItem);
                  int maxRandomIndex = 0;
                  if (spaceship->getGunLvl() < 5) {
                      pickUps.push_back(gunBooster);
                      maxRandomIndex++;
                  }
                  if (spaceship->getLinesOfFire() < 5) {
                      pickUps.push_back(fireLineBooster);
                      maxRandomIndex++;
                  }
                  int randomIndex = Util::getRandomNumber(0, maxRandomIndex);
                  pickUps[randomIndex]->placeAtSpawnPos(alienX, alienY);
              }

              break;
          }
      }

      for(auto asteroid : asteroids){
        if(asteroid->rect.y + asteroid->height < 0){
          continue;
        }

        SDL_Rect asteroidRect{asteroid->rect.x, asteroid->rect.y, asteroid->width, asteroid->height};

        if(SDL_HasIntersection(&bulletRect, &asteroidRect)){
          asteroid->takeDamage();
          spaceship->bullets.erase(spaceship->bullets.begin() + i);
          spaceshipBulletsTexture.erase(spaceshipBulletsTexture.begin() + i);

          if(asteroid->isDead()){
            asteroidExplodes->playSoundEffect();
            asteroid->givePoints(spaceship);
          }

          goto restartLoop;
        }
      }

        for(auto crystalAst : crystalAsteroids){
            if(crystalAst->rect.y + crystalAst->height < 0){
                continue;
            }

            SDL_Rect crystalAstRect{crystalAst->rect.x, crystalAst->rect.y, crystalAst->width, crystalAst->height};

            if(SDL_HasIntersection(&bulletRect, &crystalAstRect)){
                crystalAst->takeDamage();
                spaceship->bullets.erase(spaceship->bullets.begin() + i);
                spaceshipBulletsTexture.erase(spaceshipBulletsTexture.begin() + i);
                int crystalX = crystalAst->rect.x;
                int crystalY = crystalAst->rect.y;


                if(crystalAst->isDead()){
                    asteroidExplodes->playSoundEffect();
                    crystalAst->givePoints(spaceship);

                    crystalPickUps.clear();
                    crystalPickUps.push_back(healingItem); //star
                    crystalPickUps.push_back(healingItem); //star
                    crystalPickUps.push_back(healingItem); //star
                    crystalPickUps.push_back(healingItem); //shield
                    crystalPickUps.push_back(healingItem); //time slow
                    int randomIndex = Util::getRandomNumber(0, 4);
                    crystalPickUps[randomIndex]->placeAtSpawnPos(crystalX + crystalAst->width / 2, crystalY + crystalAst->height / 2);
                }

                goto restartLoop;
            }
        }
    }
  }
}

void Game::printTexture() {
    SDL_RenderClear(renderer);
    ticks = SDL_GetTicks();


    for(const std::shared_ptr<BackgroundTexture> &backgroundTexture : backgroundTextures) {
        backgroundTexture->print(renderer, ticks);
    }

    for(const std::shared_ptr<StarTexture> &starTexture : starTextures) {
        starTexture->print(renderer, ticks);
    }

    for(std::shared_ptr<AsteroidTexture> &asteroidTexture : asteroidTextures) {
        asteroidTexture->print(renderer, ticks);
    }

    spaceshipTexture->print(renderer, ticks);
    alienTexture->print(renderer, ticks);
    healingItemTexture->print(renderer, ticks);
    gunBoosterTexture->print(renderer, ticks);
    fireLineBoosterTexture->print(renderer, ticks);


  if(!spaceshipBulletsTexture.empty()){
    for(std::shared_ptr<BulletTexture> bullet : spaceshipBulletsTexture){
      bullet->print(renderer);
    }
  }

    if(!alienBulletsTexture.empty()){
        for(std::shared_ptr<BulletTexture> bullet : alienBulletsTexture){
            bullet->print(renderer);
        }
    }

  spaceshipTexture->print(renderer, ticks);

    for(std::shared_ptr<GameText> text : texts){
      text->print(renderer);
    }

    SDL_RenderPresent(renderer);
}

void Game::gameOverStage() {
     Util::setTimeEnd((double)clock() / (double)CLOCKS_PER_SEC);
    elapsedTime = Util::getTimeDuration();

    GameText gameOverText{"GAME OVER",
                        DEFAULT_GAME_TEXT_FONT_PATH,
                        DEFAULT_GAME_TEXT_FONT_SIZE,
                        DEFAULT_GAME_TEXT_COLOR,
                        Config::windowWidth / 2 - 80,
                        Config::windowHeight / 2,
                        renderer};
  GameText continueText{
          "Press space to restart!",
      DEFAULT_GAME_TEXT_FONT_PATH,
      DEFAULT_GAME_TEXT_FONT_SIZE,
      DEFAULT_GAME_TEXT_COLOR,
      Config::windowWidth / 2 - 80,
      (Config::windowHeight / 2) + DEFAULT_GAME_TEXT_FONT_SIZE,
      renderer
  };
  std::string hMessage = "Your score: " + std::to_string(spaceship->getPoints());
    GameText highScoreText{
            hMessage,
            DEFAULT_GAME_TEXT_FONT_PATH,
            DEFAULT_GAME_TEXT_FONT_SIZE,
            DEFAULT_GAME_TEXT_COLOR,
            (Config::windowWidth / 2) - 80,
            (Config::windowHeight / 2) - DEFAULT_GAME_TEXT_FONT_SIZE * 2,
            renderer
    };
    std::string tMessage = "Time survived: " + std::to_string(elapsedTime);
    GameText timeText{
            tMessage,
            DEFAULT_GAME_TEXT_FONT_PATH,
            DEFAULT_GAME_TEXT_FONT_SIZE,
            DEFAULT_GAME_TEXT_COLOR,
            (Config::windowWidth / 2) - 80,
            (Config::windowHeight / 2) - DEFAULT_GAME_TEXT_FONT_SIZE,
            renderer
    };

  GameMusic gameOverMusic{"../sound/game_over.wav"};

  gameOverMusic.playMusic();

  while(*isRunning == 3){
    while (SDL_PollEvent(&event)) {
      if (event.type == QUIT || event.key.keysym.sym == QUIT_BUTTON) {
        *isRunning = 0;
      }

      if(event.type == SDL_KEYDOWN){
        if(event.key.keysym.sym == SDLK_SPACE){
            Util::setTimeBegin(((double)clock()) / (double)CLOCKS_PER_SEC);
          initLogic();
          initTexture();
          *isRunning = 2;
        }
      }
    }
    highScoreText.print(renderer);
    timeText.print(renderer);
    continueText.print(renderer);
    gameOverText.print(renderer);
    SDL_RenderPresent(renderer);
  }
}

void Game::initStars() {

  for(int i = 0; i < PINK_STAR_MAX_NUMBER; i++){
    std::shared_ptr<Star> pink = std::make_shared<Star>(PINK_STAR_TEXTURE_ID,
                                                        STAR_WIDTH,
                                                        STAR_HEIGHT,
                                                        PINK_STAR_MIN_SPEED,
                                                        PINK_STAR_MAX_SPEED,
                                                        PINK_STAR_POINT);
    stars.push_back(pink);
    fallingObjects.push_back(pink);
  }

  for(int i = 0; i < GREEN_STAR_MAX_NUMBER; i++){
    std::shared_ptr<Star> green = std::make_shared<Star>(GREEN_STAR_TEXTURE_ID,
                                                        STAR_WIDTH,
                                                        STAR_HEIGHT,
                                                        GREEN_STAR_MIN_SPEED,
                                                        GREEN_STAR_MAX_SPEED,
                                                        GREEN_STAR_POINT);
    stars.push_back(green);
    fallingObjects.push_back(green);
  }

  for(int i = 0; i < BLUE_STAR_MAX_NUMBER; i++){
    std::shared_ptr<Star> blue = std::make_shared<Star>(BLUE_STAR_TEXTURE_ID,
                                                         STAR_WIDTH,
                                                         STAR_HEIGHT,
                                                         BLUE_STAR_MIN_SPEED,
                                                         BLUE_STAR_MAX_SPEED,
                                                         BLUE_STAR_POINT);
    stars.push_back(blue);
    fallingObjects.push_back(blue);
  }

  for(int i = 0; i < GOLD_STAR_MAX_NUMBER; i++){
    std::shared_ptr<Star> gold = std::make_shared<Star>(GOLD_STAR_TEXTURE_ID,
                                                         STAR_WIDTH,
                                                         STAR_HEIGHT,
                                                         GOLD_STAR_MIN_SPEED,
                                                         GOLD_STAR_MAX_SPEED,
                                                         GOLD_STAR_POINT);
    stars.push_back(gold);
    fallingObjects.push_back(gold);
  }

  for(int i = 0; i < RED_STAR_MAX_NUMBER; i++){
    std::shared_ptr<Star> red = std::make_shared<Star>(RED_STAR_TEXTURE_ID,
                                                         STAR_WIDTH,
                                                         STAR_HEIGHT,
                                                         RED_STAR_MIN_SPEED,
                                                         RED_STAR_MAX_SPEED,
                                                         RED_STAR_POINT);
    stars.push_back(red);
    fallingObjects.push_back(red);
  }
}

void Game::initAsteroids() {

  for(int i = 0; i < SMALL_ASTEROID_MAX_NUMBER; i++){
    std::shared_ptr<Asteroid> a = std::make_shared<Asteroid>(SMALL_ASTEROID_HEALTH,
                                                             SMALL_ASTEROID_HEIGHT,
                                                             SMALL_ASTEROID_HEIGHT,
                                                             MIN_SPEED_FOR_ASTEROIDS,
                                                             MAX_SPEED_FOR_ASTEROIDS,
                                                             SMALL_ASTEROIDS_POINT,
                                                             ASTEROID_MIN_ROT,
                                                             ASTEROID_MAX_ROT,
                                                             ASTEROID_Y_MULTIPLIER);
    asteroids.push_back(a);
    fallingObjects.push_back(a);
  }

  for(int i = 0; i < MEDIUM_ASTEROID_MAX_NUMBER; i++){
    std::shared_ptr<Asteroid> a = std::make_shared<Asteroid>(MEDIUM_ASTEROID_HEALTH,
                                                             MEDIUM_ASTEROID_HEIGHT,
                                                             MEDIUM_ASTEROID_HEIGHT,
                                                             MIN_SPEED_FOR_ASTEROIDS,
                                                             MAX_SPEED_FOR_ASTEROIDS,
                                                             MEDIUM_ASTEROIDS_POINT,
                                                              ASTEROID_MIN_ROT,
                                                              ASTEROID_MAX_ROT,
                                                              ASTEROID_Y_MULTIPLIER);
    asteroids.push_back(a);
    fallingObjects.push_back(a);
  }

  for(int i = 0; i < LARGE_ASTEROID_MAX_NUMBER; i++){
    std::shared_ptr<Asteroid> a = std::make_shared<Asteroid>(LARGE_ASTEROID_HEALTH,
                                                             LARGE_ASTEROID_HEIGHT,
                                                             LARGE_ASTEROID_HEIGHT,
                                                             MIN_SPEED_FOR_ASTEROIDS,
                                                             MAX_SPEED_FOR_ASTEROIDS,
                                                             LARGE_ASTEROIDS_POINT,
                                                             ASTEROID_MIN_ROT,
                                                             ASTEROID_MAX_ROT,
                                                             ASTEROID_Y_MULTIPLIER);
    asteroids.push_back(a);
    fallingObjects.push_back(a);
  }

  for(int i = 0; i < CRYSTAL_ASTEROID_MAX_NUMBER; i++) {
      std::shared_ptr<Asteroid> a = std::make_shared<Asteroid>(CRYSTAL_ASTEROID_HEALTH,
                                                               CRYSTAL_ASTEROID_HEIGHT,
                                                               CRYSTAL_ASTEROID_HEIGHT,
                                                               MIN_SPEED_FOR_ASTEROIDS,
                                                               MAX_SPEED_FOR_CRYSTAL_ASTEROIDS,
                                                               CRYSTAL_ASTEROID_POINT,
                                                               ASTEROID_MIN_ROT,
                                                               CRYSTAL_ASTEROID_MAX_ROT,
                                                               CRYSTAL_ASTEROID_Y_MULTIPLIER);
      crystalAsteroids.push_back(a);
      fallingObjects.push_back(a);
  }
}

void Game::initBackgroundElements() {
  for (int i = 0; i < NUMBER_OF_BACKGROUND_ELEMENTS; ++i) {
    std::shared_ptr<BackgroundElement> elem = generateBackgroundElement();
    backgroundElems.push_back(elem);
  }
}

std::shared_ptr<BackgroundElement> Game::generateBackgroundElement() {
  static int yPos = -(Config::windowHeight) * 0.5;
  int x = Util::getRandomNumber(0, Config::windowWidth - BACKGROUND_ELEMENT_SIZE);
  int y = yPos - BACKGROUND_ELEMENT_SIZE * 1.5;
  yPos = y;
  return std::make_shared<BackgroundElement>(x,
                                             y,
                                             BACKGROUND_ELEMENT_SIZE,
                                             BACKGROUND_ELEMENT_SIZE,
                                             BACKGROUND_ELEMENT_SPEED,
                                             BACKGROUND_ELEMENT_SPEED,
                                             true);
}