#include "OpenStage.h"

void OpenStage::initGameTexts(SDL_Renderer* renderer) {

    texts.push_back(std::make_shared<GameText>(
        "STELLAR STORM",
        DEFAULT_GAME_TEXT_FONT_PATH,
        DEFAULT_GAME_TEXT_FONT_SIZE_LARGE,
        DEFAULT_GAME_TEXT_COLOR,
        Config::windowWidth * 0.125,
        Config::windowHeight * 0.25,
        renderer
        ));

    texts.push_back(std::make_shared<GameTextChangeColorAnim>(
        "PRESS SPACE TO START",
        DEFAULT_GAME_TEXT_FONT_PATH,
        DEFAULT_GAME_TEXT_FONT_SIZE,
        DEFAULT_GAME_TEXT_COLOR,
        DEFAULT_GAME_TEXT_COLOR_2,
        Config::windowWidth * 0.35,
        (Config::windowHeight * 0.5) + 50,
        40,
        renderer
        ));
}

void OpenStage::run(SDL_Renderer* renderer) {
    handleEvent();
    printer(renderer);
}

void OpenStage::handleEvent() {
  while (SDL_PollEvent(&event)) {
    if (event.type == QUIT || event.key.keysym.sym == QUIT_BUTTON) {
      *isRunning = QUIT_VALUE;
    }

    if (event.type == SDL_KEYDOWN) {
        switch (event.key.keysym.sym) {
            case SDLK_SPACE:
                Util::setTimeBegin(((double)clock()) / (double)CLOCKS_PER_SEC);
                *isRunning = MIDDLE_GAME_STAGE_VALUE;
                break;
            case NUMBER_1:
                currentSpaceshipTexture = spaceshipTexture1;
                break;
            case NUMBER_2:
                currentSpaceshipTexture = spaceshipTexture2;
                break;
            case NUMBER_3:
                currentSpaceshipTexture = spaceshipTexture3;
                break;
            default:
                break;
        }
    }
  }
}

void OpenStage::printer(SDL_Renderer* renderer) {
  SDL_RenderClear(renderer);
  for(const std::shared_ptr<GameText> text : texts){
    text->print(renderer);
  }

  if(!itemTextures.empty()){
    for(const std::shared_ptr<PNGTexture> texture : itemTextures){
      texture->print(renderer, SDL_GetTicks());
    }
  }

  currentSpaceshipTexture->print(renderer, SDL_GetTicks());

  SDL_RenderPresent(renderer);
}

void OpenStage::initSpaceshipTextures(SDL_Renderer *renderer) {
    spaceshipTexture1 = std::make_shared<SpaceshipTexture>(renderer, spaceship, SPACESHIP1_FILEPATH, SPACESHIP1_DAMAGE_FILEPATH);
    spaceshipTexture2 = std::make_shared<SpaceshipTexture>(renderer, spaceship, SPACESHIP2_FILEPATH, SPACESHIP2_DAMAGE_FILEPATH);
    spaceshipTexture3 = std::make_shared<SpaceshipTexture>(renderer, spaceship, SPACESHIP3_FILEPATH, SPACESHIP3_DAMAGE_FILEPATH);
}
