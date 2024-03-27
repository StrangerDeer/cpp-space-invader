#pragma once

#include "GameTextChangeColorAnim.h"

void GameTextChangeColorAnim::print(SDL_Renderer *renderer) {

  if(counter < frameRate) {
    GameText::print(renderer);
  } else if (counter <= frameRate * 2){
    texture2.print(renderer);
  } else {
    texture2.print(renderer);
    counter = 0;
  }

  counter++;
}

