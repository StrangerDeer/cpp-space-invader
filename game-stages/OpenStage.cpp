#include <array>
#include "OpenStage.h"

void OpenStage::initGameTexts(SDL_Renderer* renderer) {
    std::vector<GameText> textsObj = {
            {"SPACE INVADER",
             DEFAULT_GAME_TEXT_FONT_PATH,
             DEFAULT_GAME_TEXT_FONT_SIZE,
             DEFAULT_GAME_TEXT_COLOR,
             Config::windowWidth / 2,
             Config::windowHeight / 2,
             renderer},
            {"PRESS SPACE TO START",
             DEFAULT_GAME_TEXT_FONT_PATH,
             DEFAULT_GAME_TEXT_FONT_SIZE,
             DEFAULT_GAME_TEXT_COLOR,
             Config::windowWidth / 2,
             (Config::windowHeight / 2) + 50,
             renderer},
            {"PRESS SPACE TO START",
             DEFAULT_GAME_TEXT_FONT_PATH,
             DEFAULT_GAME_TEXT_FONT_SIZE,
             DEFAULT_GAME_TEXT_COLOR_2,
             Config::windowWidth / 2,
             (Config::windowHeight / 2) + 50,
             renderer}};

    for(int i = 0; i < textsObj.size(); i++){
        std::shared_ptr<GameText> text_ptr = std::make_shared<GameText>(textsObj.at(i));
        texts.push_back(text_ptr);
    }
}
