//
// Created by Deer on 13/03/2024.
//

#include "SpaceshipPointGameText.h"

void SpaceshipPointGameText::print(SDL_Renderer *renderer) {
    if(spaceship->getPoints() != currentValue){
        message = std::to_string(spaceship->getPoints());
        currentValue = spaceship->getPoints();
        loadFont(renderer);
    }
  GameText::print(renderer);
}
