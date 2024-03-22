#include "Game.h"

void Game::run() {

  backgroundMusic->playMusic();

  while(isRunning){
    frameStart = SDL_GetTicks();
    handleEvent();
    handleCollisions();
    makeObjectsFall();

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
    printTexture();

    frameTime = SDL_GetTicks() - frameStart;

    if(FRAME_DELAY > frameTime){
      SDL_Delay(FRAME_DELAY - frameTime);
    }
  }
}

void Game::makeObjectsFall() {
    int windowHeight = SDL_GetWindowSurface(window)->h;
    int windowWidth = SDL_GetWindowSurface(window)->w;
    for (std::shared_ptr<Star> star : stars) {
        star->fall();
        if (star.get()->rect.y > windowHeight + 300) {
            star->placeAtStartingPos(windowWidth, windowHeight);
        }
    }
    for (std::shared_ptr<Asteroid> asteroid : asteroids) {
        asteroid->fall();
        if (asteroid.get()->rect.y > windowHeight + 300) {
            asteroid->placeAtStartingPos(windowWidth, windowHeight);
        }
    }
    for (std::shared_ptr<BackgroundElement> &elem : backgroundElems) {
        elem->fall();
        if (elem->rect.y > windowHeight + (((elem->height * 1.5) * backgroundElems.size()) - windowHeight - elem->height)) {
            elem->placeAtStartingPos(windowWidth, windowHeight);
        }
    }
}

void Game::initSDL() {
  SDL_Init(SDL_INIT_EVERYTHING);

  window = SDL_CreateWindow("Space Invader", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 1000, 1000,
                            SDL_WINDOW_ALLOW_HIGHDPI | SDL_WINDOW_OPENGL);
  if (!window) {
    std::cerr << "Error: Unable to create window!" << SDL_GetError() << std::endl;
    return;
  }

  SDL_SetWindowFullscreen(window, SDL_WINDOW_FULLSCREEN_DESKTOP);

  SDL_GetWindowSize(window, &windowWidth, &windowHeight);

  renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);

  if (!renderer) {
    std::cerr << "Error: Unable to create renderer!" << SDL_GetError() << std::endl;
    return;
  }
}

void Game::initSounds() {
  backgroundMusic = std::make_unique<GameMusic>(BACKGROUND_MUSIC_FILEPATH);
  spaceshipShootSoundEffect = std::make_unique<GameSoundEffect>(SPACESHIP_SHOOT_SOUND_EFFECT_FILEPATH);
}

std::shared_ptr<Star> generateStar(int windowWidth,
                                   int windowHeight,
                                   int width,
                                   int height,
                                   int minSpeed,
                                   int maxSpeed,
                                   int point) {
  int x = Util::getRandomNumber(0, windowWidth);
  int y = Util::getRandomNumber(-windowHeight * 2, (0 - windowHeight) / 2);
  return std::make_shared<Star>(x, y, width, height, minSpeed, maxSpeed, point);
}

std::shared_ptr<Asteroid> generateAsteroid(int windowWidth,
                                           int windowHeight,
                                           int maxHp,
                                           int width,
                                           int height,
                                           int minSpeed,
                                           int maxSpeed,
                                           int points) {
  int x = Util::getRandomNumber(0, windowWidth);
  int y = Util::getRandomNumber(-windowHeight * 3, (0 - windowHeight) / 2);
  return std::make_shared<Asteroid>(maxHp, x, y, width, height, minSpeed, maxSpeed, points, windowWidth, windowHeight);
}

std::shared_ptr<BackgroundElement> generateBackgroundElement(int windowWidth,
                                                             int windowHeight,
                                                             int width,
                                                             int height,
                                                             int minSpeed,
                                                             int maxSpeed) {
    static int yPos = -windowHeight * 1;
    int x = Util::getRandomNumber(0, windowWidth - width);
    int y = yPos - height * 1.5;
    yPos = y;
    return std::make_shared<BackgroundElement>(x, y, width, height, 20, 20, true);
}

void Game::initOneKindOfStars(int numberOfStars,
                              int windowWidth,
                              int windowHeight,
                              int starWidth,
                              int starHeight,
                              int minSpeed,
                              int maxSpeed,
                              int point,
                              shared_vector<Star> &starVector) {
  for (int i = 0; i < numberOfStars; ++i) {
    std::shared_ptr<Star> s = generateStar(windowWidth,
                                           windowHeight,
                                           starWidth,
                                           starHeight,
                                           minSpeed,
                                           maxSpeed,
                                           point);
    stars.push_back(s);
    starVector.push_back(s);
    dimensionalObjects.push_back(s);
  }
}

void Game::initOneKindOfAsteroids(int numberOfAsteroids,
                                  int windowWidth,
                                  int windowHeight,
                                  int maxHp,
                                  int width,
                                  int height,
                                  int minSpeed,
                                  int maxSpeed,
                                  int point) {
  for (int i = 0; i < numberOfAsteroids; ++i) {
    std::shared_ptr<Asteroid>
        a = generateAsteroid(windowWidth,
                             windowHeight,
                             maxHp,
                             width,
                             height,
                             minSpeed,
                             maxSpeed,
                             point);
    asteroids.push_back(a);
    dimensionalObjects.push_back(a);
  }
}


void Game::initBackgroundElements(int numberOfElems,
                                  int windowWidth,
                                  int windowHeight,
                                  int width,
                                  int height,
                                  int minSpeed,
                                  int maxSpeed) {
    for (int i = 0; i < numberOfElems; ++i) {
        std::shared_ptr<BackgroundElement>
                elem = generateBackgroundElement(windowWidth,
                                                 windowHeight,
                                                 width,
                                                 height,
                                                 minSpeed,
                                                 maxSpeed);
        backgroundElems.push_back(elem);
    }
}

void Game::initLogic() {
  constexpr int STAR_HEIGHT = 125;
  constexpr int STAR_WIDTH = 50;

  constexpr int NUMBER_OF_PINK_STARS = 7;
  constexpr int NUMBER_OF_GREEN_STARS = 5;
  constexpr int NUMBER_OF_BLUE_STARS = 3;
  constexpr int NUMBER_OF_GOLD_STARS = 2;
  constexpr int NUMBER_OF_RED_STARS = 1;

  constexpr int POINT_FOR_PINK_STARS = 5;
  constexpr int POINT_FOR_GREEN_STARS = 10;
  constexpr int POINT_FOR_BLUE_STARS = 15;
  constexpr int POINT_FOR_GOLD_STARS = 25;
  constexpr int POINT_FOR_RED_STARS = 50;

  constexpr int MIN_SPEED_FOR_PINK_STARS = 2;
  constexpr int MIN_SPEED_FOR_GREEN_STARS = 5;
  constexpr int MIN_SPEED_FOR_BLUE_STARS = 7;
  constexpr int MIN_SPEED_FOR_GOLD_STARS = 10;
  constexpr int MIN_SPEED_FOR_RED_STARS = 15;

  constexpr int MAX_SPEED_FOR_PINK_STARS = 10;
  constexpr int MAX_SPEED_FOR_GREEN_STARS = 20;
  constexpr int MAX_SPEED_FOR_BLUE_STARS = 30;
  constexpr int MAX_SPEED_FOR_GOLD_STARS = 35;
  constexpr int MAX_SPEED_FOR_RED_STARS = 40;

  constexpr int SMALL_ASTEROID_HEIGHT = 70;
  constexpr int MEDIUM_ASTEROID_HEIGHT = 120;
  constexpr int LARGE_ASTEROID_HEIGHT = 250;

  constexpr int NUMBER_OF_SMALL_ASTEROIDS = 20;
  constexpr int NUMBER_OF_MEDIUM_ASTEROIDS = 10;
  constexpr int NUMBER_OF_LARGE_ASTEROIDS = 3;

  constexpr int HEALTH_OF_SMALL_ASTEROIDS = 1;
  constexpr int HEALTH_OF_MEDIUM_ASTEROIDS = 3;
  constexpr int HEALTH_OF_LARGE_ASTEROIDS = 5;

  constexpr int POINT_FOR_SMALL_ASTEROIDS = 1;
  constexpr int POINT_FOR_MEDIUM_ASTEROIDS = 3;
  constexpr int POINT_FOR_LARGE_ASTEROIDS = 5;

  constexpr int MIN_SPEED_FOR_ASTEROIDS = 1;
  constexpr int MAX_SPEED_FOR_ASTEROIDS = 15;

  constexpr int MIN_SPEED_FOR_BACKGROUND_ELEM = 1;
  constexpr int MAX_SPEED_FOR_BACKGROUND_ELEM = 1;
  constexpr int BACKGROUND_ELEM_HEIGHT = 600;
  constexpr int NUMBER_OF_BACKGROUND_ELEMS = 7;

  int windowWidth = SDL_GetWindowSurface(window)->w;
  int windowHeight = SDL_GetWindowSurface(window)->h;

  initBackgroundElements(NUMBER_OF_BACKGROUND_ELEMS,
                           windowWidth,
                           windowHeight,
                           BACKGROUND_ELEM_HEIGHT,
                           BACKGROUND_ELEM_HEIGHT,
                           MIN_SPEED_FOR_BACKGROUND_ELEM,
                           MAX_SPEED_FOR_BACKGROUND_ELEM);

  initOneKindOfStars(NUMBER_OF_PINK_STARS,
                     windowWidth,
                     windowHeight,
                     STAR_WIDTH,
                     STAR_HEIGHT,
                     MIN_SPEED_FOR_PINK_STARS,
                     MAX_SPEED_FOR_PINK_STARS,
                     POINT_FOR_PINK_STARS,
                     pinkStars);
  initOneKindOfStars(NUMBER_OF_GREEN_STARS,
                     windowWidth,
                     windowHeight,
                     STAR_WIDTH,
                     STAR_HEIGHT,
                     MIN_SPEED_FOR_GREEN_STARS,
                     MAX_SPEED_FOR_GREEN_STARS,
                     POINT_FOR_GREEN_STARS,
                     greenStars);
  initOneKindOfStars(NUMBER_OF_BLUE_STARS,
                     windowWidth,
                     windowHeight,
                     STAR_WIDTH,
                     STAR_HEIGHT,
                     MIN_SPEED_FOR_BLUE_STARS,
                     MAX_SPEED_FOR_BLUE_STARS,
                     POINT_FOR_BLUE_STARS,
                     blueStars);
  initOneKindOfStars(NUMBER_OF_GOLD_STARS,
                     windowWidth,
                     windowHeight,
                     STAR_WIDTH,
                     STAR_HEIGHT,
                     MIN_SPEED_FOR_GOLD_STARS,
                     MAX_SPEED_FOR_GOLD_STARS,
                     POINT_FOR_GOLD_STARS,
                     goldStars);
  initOneKindOfStars(NUMBER_OF_RED_STARS,
                     windowWidth,
                     windowHeight,
                     STAR_WIDTH,
                     STAR_HEIGHT,
                     MIN_SPEED_FOR_RED_STARS,
                     MAX_SPEED_FOR_RED_STARS,
                     POINT_FOR_RED_STARS,
                     redStars);

  initOneKindOfAsteroids(NUMBER_OF_SMALL_ASTEROIDS,
                         windowWidth,
                         windowHeight,
                         HEALTH_OF_SMALL_ASTEROIDS,
                         SMALL_ASTEROID_HEIGHT,
                         SMALL_ASTEROID_HEIGHT,
                         MIN_SPEED_FOR_ASTEROIDS,
                         MAX_SPEED_FOR_ASTEROIDS,
                         POINT_FOR_SMALL_ASTEROIDS);
  initOneKindOfAsteroids(NUMBER_OF_MEDIUM_ASTEROIDS,
                         windowWidth,
                         windowHeight,
                         HEALTH_OF_MEDIUM_ASTEROIDS,
                         MEDIUM_ASTEROID_HEIGHT,
                         MEDIUM_ASTEROID_HEIGHT,
                         MIN_SPEED_FOR_ASTEROIDS,
                         MAX_SPEED_FOR_ASTEROIDS,
                         POINT_FOR_MEDIUM_ASTEROIDS);
  initOneKindOfAsteroids(NUMBER_OF_LARGE_ASTEROIDS,
                         windowWidth,
                         windowHeight,
                         HEALTH_OF_LARGE_ASTEROIDS,
                         LARGE_ASTEROID_HEIGHT,
                         LARGE_ASTEROID_HEIGHT,
                         MIN_SPEED_FOR_ASTEROIDS,
                         MAX_SPEED_FOR_ASTEROIDS,
                         POINT_FOR_LARGE_ASTEROIDS);


    spaceship = std::make_shared<Spaceship>(5, 50, windowWidth * 0.5, windowHeight * 0.85, 100, 100, 1, 1);

}

void Game::handleEvent() {
  while (SDL_PollEvent(&event)) {
    if (event.type == QUIT || event.key.keysym.sym == QUIT_BUTTON) {
      isRunning = false;
    }

    if(event.type == SDL_KEYDOWN){
      switch (event.key.keysym.sym) {
        case MOVE_DOWN_BUTTON:
          if(spaceship->rect.y + 50 + spaceship->height < windowHeight){
            spaceship->moveDown();
          }
          break;
        case MOVE_UP_BUTTON:
          if(spaceship->rect.y + 50 > 0 + spaceship->height) {
            spaceship->moveUp();
          }
          break;
        case MOVE_RIGHT_BUTTON:
          if(spaceship->rect.x + 60 + spaceship->width < windowWidth){
            spaceship->moveRight();
          }
          break;
        case MOVE_LEFT_BUTTON:
          if(spaceship->rect.x + 50 > 0 + spaceship->width) {
            spaceship->moveLeft();
          }
          break;

        case SPACESHIP_SHOOT_BUTTON:
            auto now = std::chrono::steady_clock::now();
            auto timeSinceLastShoot = std::chrono::duration_cast<std::chrono::milliseconds>(now - lastShootTime).count();

            if(timeSinceLastShoot >= (1.0 / spaceship->getFirerate()) * 1000){
              std::shared_ptr<SpaceshipBullet> bullet = spaceship->shoot(spaceship->width, spaceship->height);
              std::shared_ptr<BulletTexture> bulletTexture = std::make_shared<BulletTexture>(renderer, bullet);
              spaceshipBulletsTexture.push_back(bulletTexture);
              spaceshipShootSoundEffect->playSoundEffect();
              lastShootTime = now;
            }
          break;
      }
    }
  }
}

void Game::initTexture() {

    int windowWidth = SDL_GetWindowSurface(window)->w;
    int windowHeight = SDL_GetWindowSurface(window)->h;

    initBackgroundElemTextures();
    initStarTextures();
    initAsteroidTextures();

    std::shared_ptr<GameText> livesText = std::make_shared<GameText>(renderer,
                                                                     DEFAULT_GAME_TEXT_FONT_PATH,
                                                                     DEFAULT_GAME_TEXT_FONT_SIZE,
                                                                     "Health: ",
                                                                     DEFAULT_GAME_TEXT_COLOR, 20,windowHeight * 0.93);
    std::shared_ptr<SpaceshipHealthGameText> spaceHealthText =
        std::make_shared<SpaceshipHealthGameText>(renderer, spaceship,
                                                  DEFAULT_GAME_TEXT_FONT_PATH,
                                                  DEFAULT_GAME_TEXT_FONT_SIZE,
                                                  DEFAULT_GAME_TEXT_COLOR, 175,windowHeight * 0.93);

    std::shared_ptr<SpaceshipPointGameText> spacePointText = std::make_shared<SpaceshipPointGameText>(
            renderer, spaceship,
            DEFAULT_GAME_TEXT_FONT_PATH,
            DEFAULT_GAME_TEXT_FONT_SIZE,
            DEFAULT_GAME_TEXT_COLOR,
            windowWidth - 150,windowHeight * 0.93);

    texts.push_back(livesText);
    texts.push_back(spaceHealthText);
    texts.push_back(spacePointText);

    spaceshipTexture = std::make_unique<SpaceshipTexture>(renderer, spaceship);
}

void Game::initBackgroundElemTextures() {
    std::string BACKGROUND_IMG = "../ui/textures/background";
    for (const std::shared_ptr<BackgroundElement> &elem : backgroundElems) {
        int randomIndex = Util::getRandomNumber(1, 10);
        std::string filepath = BACKGROUND_IMG + std::to_string(randomIndex) + ".png";
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
}

void Game::initStarTextures() {

  for (const std::shared_ptr<Star> &bluestar : blueStars) {
    std::shared_ptr<StarTexture> starTexture = std::make_shared<StarTexture>(renderer, bluestar, BLUE_STAR_FILEPATH);
    starTextures.push_back(starTexture);
  }
  for (const std::shared_ptr<Star> &greenstar : greenStars) {
    std::shared_ptr<StarTexture> starTexture = std::make_shared<StarTexture>(renderer, greenstar, GREEN_STAR_FILEPATH);
    starTextures.push_back(starTexture);
  }
  for (const std::shared_ptr<Star> &pinkStar : pinkStars) {
    std::shared_ptr<StarTexture> starTexture = std::make_shared<StarTexture>(renderer, pinkStar, PINK_STAR_FILEPATH);
    starTextures.push_back(starTexture);
  }
  for (const std::shared_ptr<Star> &goldstar : goldStars) {
    std::shared_ptr<StarTexture> starTexture = std::make_shared<StarTexture>(renderer, goldstar, GOLD_STAR_FILEPATH);
    starTextures.push_back(starTexture);
  }
  for (const std::shared_ptr<Star> &redstar : redStars) {
    std::shared_ptr<StarTexture> starTexture = std::make_shared<StarTexture>(renderer, redstar, RED_STAR_FILEPATH);
    starTextures.push_back(starTexture);
  }
}

void Game::handleCollisions() {

  SDL_Rect spaceshipRect{spaceship->rect.x, spaceship->rect.y, spaceship->width, spaceship->height};

  for (auto &asteroid : asteroids) {

    SDL_Rect asteroidRect{asteroid->rect.x, asteroid->rect.y, asteroid->width, asteroid->height};

    if (SDL_HasIntersection(&spaceshipRect, &asteroidRect)) {
      asteroid->reset();
      spaceship->takeDamage();
    }
  }
  for (auto &star : stars) {

    SDL_Rect starRect{star->rect.x, star->rect.y, star->width, star->height};

    if (SDL_HasIntersection(&spaceshipRect, &starRect)) {
      star->placeAtStartingPos(windowWidth, windowHeight);
      star->givePoints(spaceship);
    }
  }

  if(!spaceship->bullets.empty()){
    for(int i = 0; i < spaceship->bullets.size(); i++){
      std::shared_ptr<SpaceshipBullet> bullet = spaceship->bullets.at(i);
      SDL_Rect bulletRect{bullet->bulletRect.x, bullet->bulletRect.y, bullet->width, bullet->height};

      for(auto asteroid : asteroids){
        if(asteroid->rect.y + asteroid->height < 0){
          continue;
        }

        SDL_Rect asteroidRect{asteroid->rect.x, asteroid->rect.y, asteroid->width, asteroid->height};

        if(SDL_HasIntersection(&bulletRect, &asteroidRect)){
          asteroid->reduceHp(bullet->damage);
          spaceship->bullets.erase(spaceship->bullets.begin() + i);
          spaceshipBulletsTexture.erase(spaceshipBulletsTexture.begin() + i);
        }

        if(asteroid->isDead()){
          asteroid->givePoints(spaceship);
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


  if(!spaceshipBulletsTexture.empty()){
    for(std::shared_ptr<BulletTexture> bullet : spaceshipBulletsTexture){
      bullet->print(renderer);
    }
  }

  spaceshipTexture->print(renderer, ticks);

    for(std::shared_ptr<GameText> text : texts){
        text->display(renderer);
    }

    SDL_RenderPresent(renderer);
}

