#include "OpenStage.h"

void OpenStage::initGameTexts(SDL_Renderer* renderer) {

    texts.push_back(std::make_shared<GameText>(
        "STELLAR STORM",
        DEFAULT_GAME_TEXT_FONT_PATH,
        200,
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
      if (event.key.keysym.sym == SDLK_SPACE) {
          Util::setTimeBegin(((double)clock()) / (double)CLOCKS_PER_SEC);
        *isRunning = MIDDLE_GAME_STAGE_VALUE;
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

  SDL_RenderPresent(renderer);
}
