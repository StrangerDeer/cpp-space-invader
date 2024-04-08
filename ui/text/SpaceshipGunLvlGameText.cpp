#include "SpaceshipGunLvlGameText.h"

void SpaceshipGunLvlGameText::print(SDL_Renderer *renderer) {
    if(spaceship->getGunLvl() != currentValue){
        message = std::to_string(spaceship->getGunLvl());
        currentValue = spaceship->getGunLvl();
        loadFont(renderer);
    }
    GameText::print(renderer);
}