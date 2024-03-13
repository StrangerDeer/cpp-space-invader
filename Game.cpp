#include "Game.h"

void Game::run() {

    while(isRunning){
        handleEvent();
        SDL_RenderClear(renderer);
        Uint32 ticks = SDL_GetTicks();

        spaceshipTexture->print(renderer, ticks);

        for(std::shared_ptr<StarTexture> starTexture : starTextures) {
            starTexture->print(renderer, ticks);
        }

        for(std::shared_ptr<AsteroidTexture> asteroidTexture : asteroidTextures) {
            asteroidTexture->print(renderer, ticks);
        }

        for (std::shared_ptr<Star> star : stars) {
            star->fall();
        }
        for (std::shared_ptr<Asteroid> asteroid : asteroids) {
            asteroid->fall();
        }



        SDL_RenderPresent(renderer);
        SDL_Delay(60);
    }
}

void Game::initSDL() {
  window = SDL_CreateWindow("Space Invader", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 1000, 1000,
                            SDL_WINDOW_ALLOW_HIGHDPI | SDL_WINDOW_OPENGL);
  if (!window) {
    std::cerr << "Error: Unable to create window!" << SDL_GetError() << std::endl;
    return;
  }

    SDL_SetWindowFullscreen(window, SDL_WINDOW_FULLSCREEN_DESKTOP);

  renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);

    if (!renderer) {
        std::cerr << "Error: Unable to create renderer!" << SDL_GetError() << std::endl;
        return;
    }


    //TODO: MOVE TO INITLOGIC
    spaceship = std::make_shared<Spaceship>(1, 30, 500, 500, 500, 500, 1, 1);
}

std::shared_ptr<Star> generateStar(int windowWidth,
                                   int windowHeight,
                                   int width,
                                   int height,
                                   int minSpeed,
                                   int maxSpeed,
                                   int point) {
  int x = Util::getRandomNumber(0, windowWidth);
  int y = Util::getRandomNumber(-windowHeight*2, (0-windowHeight)/2);
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
  int y = Util::getRandomNumber(-windowHeight*3, (0-windowHeight)/2);
  return std::make_shared<Asteroid>(maxHp, x, y, width, height, minSpeed, maxSpeed, points);
}

void Game::initOneKindOfStars(int numberOfStars,
                              int windowWidth,
                              int windowHeight,
                              int starWidth,
                              int starHeight,
                              int minSpeed,
                              int maxSpeed,
                              int point,
                              std::vector<std::shared_ptr<Star>>& starVector) {
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

void Game::initLogic() {
  constexpr int STAR_HEIGHT = 125;
  constexpr int STAR_WIDTH = 50;

  constexpr int NUMBER_OF_PINK_STARS = 5;
  constexpr int NUMBER_OF_GREEN_STARS = 4;
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

  constexpr int MAX_SPEED_FOR_PINK_STARS = 7;
  constexpr int MAX_SPEED_FOR_GREEN_STARS = 10;
  constexpr int MAX_SPEED_FOR_BLUE_STARS = 20;
  constexpr int MAX_SPEED_FOR_GOLD_STARS = 30;
  constexpr int MAX_SPEED_FOR_RED_STARS = 35;

  constexpr int SMALL_ASTEROID_HEIGHT = 70;
  constexpr int MEDIUM_ASTEROID_HEIGHT = 120;
  constexpr int LARGE_ASTEROID_HEIGHT = 170;

  constexpr int NUMBER_OF_SMALL_ASTEROIDS = 25;
  constexpr int NUMBER_OF_MEDIUM_ASTEROIDS = 15;
  constexpr int NUMBER_OF_LARGE_ASTEROIDS = 5;

  constexpr int HEALTH_OF_SMALL_ASTEROIDS = 1;
  constexpr int HEALTH_OF_MEDIUM_ASTEROIDS = 3;
  constexpr int HEALTH_OF_LARGE_ASTEROIDS = 5;

  constexpr int POINT_FOR_SMALL_ASTEROIDS = 1;
  constexpr int POINT_FOR_MEDIUM_ASTEROIDS = 3;
  constexpr int POINT_FOR_LARGE_ASTEROIDS = 5;

  constexpr int MIN_SPEED_FOR_ASTEROIDS = 1;
  constexpr int MAX_SPEED_FOR_ASTEROIDS = 15;

  int windowWidth = SDL_GetWindowSurface(window)->w;
  int windowHeight = SDL_GetWindowSurface(window)->h;

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

}

void Game::handleEvent() {
  while (SDL_PollEvent(&event)) {
    if (event.type == SDL_QUIT || event.key.keysym.sym == SDLK_ESCAPE) {
      isRunning = false;
    }

    switch (event.key.keysym.sym) {
      case SDLK_DOWN: spaceship->moveDown();
        break;
      case SDLK_UP: spaceship->moveUp();
        break;
      case SDLK_RIGHT: spaceship->moveRight();
        break;
      case SDLK_LEFT: spaceship->moveLeft();
        break;
      default:;
    }

  }
}

void Game::initTexture() {

    initStarTextures();
    initAsteroidTextures();

    spaceshipTexture = std::make_unique<SpaceshipTexture>(renderer, spaceship);
}

void Game::initAsteroidTextures() {
    std::string ASTEROID_IMG = "../ui/textures/asteroid";
    for(const std::shared_ptr<Asteroid>& asteroid : asteroids) {
        int randomIndex = Util::getRandomNumber(1, 5);
        std::string filepath = ASTEROID_IMG + std::to_string(randomIndex) + ".png";
        std::shared_ptr<AsteroidTexture> asteroidTexture = std::make_shared<AsteroidTexture>(renderer, asteroid, filepath);
        asteroidTextures.push_back(asteroidTexture);
    }
}

void Game::initStarTextures() {
    std::string BLUESTAR_IMG = "../ui/textures/bluestar.png";
    std::string GREENSTAR_IMG = "../ui/textures/greenstar.png";
    std::string PINKSTAR_IMG = "../ui/textures/pinkstar.png";
    std::string GOLDSTAR_IMG = "../ui/textures/goldstar.png";
    std::string REDSTAR_IMG = "../ui/textures/redstar.png";

    for(const std::shared_ptr<Star>& bluestar : blueStars) {
        std::shared_ptr<StarTexture> starTexture = std::make_shared<StarTexture>(renderer, bluestar, BLUESTAR_IMG);
        starTextures.push_back(starTexture);
    }
    for(const std::shared_ptr<Star>& greenstar : greenStars) {
        std::shared_ptr<StarTexture> starTexture = std::make_shared<StarTexture>(renderer, greenstar, GREENSTAR_IMG);
        starTextures.push_back(starTexture);
    }
    for(const std::shared_ptr<Star>& pinkStar : pinkStars) {
        std::shared_ptr<StarTexture> starTexture = std::make_shared<StarTexture>(renderer, pinkStar, PINKSTAR_IMG);
        starTextures.push_back(starTexture);
    }
    for(const std::shared_ptr<Star>& goldstar : goldStars) {
        std::shared_ptr<StarTexture> starTexture = std::make_shared<StarTexture>(renderer, goldstar, GOLDSTAR_IMG);
        starTextures.push_back(starTexture);
    }
    for(const std::shared_ptr<Star>& redstar : redStars) {
        std::shared_ptr<StarTexture> starTexture = std::make_shared<StarTexture>(renderer, redstar, REDSTAR_IMG);
        starTextures.push_back(starTexture);
    }
}
