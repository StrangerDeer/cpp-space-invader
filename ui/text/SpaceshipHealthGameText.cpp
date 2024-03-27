//
// Created by Deer on 13/03/2024.
//

#include "SpaceshipHealthGameText.h"

void SpaceshipHealthGameText::print(SDL_Renderer *renderer) {
    if(spaceship->getHealth() != currentValue){
        message = std::to_string(spaceship->getHealth());
        currentValue = spaceship->getHealth();
        loadFont(renderer);
    }
  GameText::print(renderer);
}
