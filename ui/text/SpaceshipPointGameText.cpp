//
// Created by Deer on 13/03/2024.
//

#include "SpaceshipPointGameText.h"

void SpaceshipPointGameText::display(SDL_Renderer *renderer) {
    if(spaceship->getPoints() != currentValue){
        message = std::to_string(spaceship->getPoints());
        currentValue = spaceship->getPoints();
        loadFont();
    }
    GameText::display(renderer);
}
