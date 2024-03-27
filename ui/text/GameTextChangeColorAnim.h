#pragma once

#include "GameText.h"

class GameTextChangeColorAnim : public GameText {
 public:
  GameTextChangeColorAnim(const std::string& message,
                          const std::string&  fontPath,
                          int fontSize,
                          const SDL_Color& color,
                          const SDL_Color& color2,
                          int x,
                          int y,
                          int frameRate,
                          SDL_Renderer* renderer) :
      GameText(message, fontPath, fontSize, color, x,y, renderer),
      texture2(message, fontPath, fontSize, color2, x,y,renderer),
      frameRate(frameRate),
      counter(0)
      {}

      void print(SDL_Renderer* renderer) override;

 private:
  int counter, frameRate;
  GameText texture2;
};
