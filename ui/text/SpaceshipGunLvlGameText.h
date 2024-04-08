#pragma once


#include "GameText.h"
#include "../../objects/Spaceship.h"

class SpaceshipGunLvlGameText : public GameText {
public:
    SpaceshipGunLvlGameText(SDL_Renderer* renderer, std::shared_ptr<Spaceship> spaceship, const std::string& fontPath, int fontSize, SDL_Color color, int x, int y) :
    GameText(std::to_string(spaceship->getGunLvl()), fontPath, fontSize, color, x,y,renderer),
    spaceship(spaceship),
            currentValue(spaceship->getGunLvl())
    {};

    void print(SDL_Renderer* renderer) override;

private:
    int currentValue;
    std::shared_ptr<Spaceship> spaceship;

};
