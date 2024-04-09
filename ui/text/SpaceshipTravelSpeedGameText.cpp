#include "SpaceshipTravelSpeedGameText.h"

void SpaceshipTravelSpeedGameText::print(SDL_Renderer *renderer) {
    if(spaceship->getTravelSpeed() != currentValue){
        message = std::to_string(spaceship->getTravelSpeed()) + " km/h";
        currentValue = spaceship->getTravelSpeed();
        loadFont(renderer);
    }
    GameText::print(renderer);
}