//
// Created by Deer on 13/03/2024.
//

#ifndef CPP_SPACE_INVADER_SPACESHIPHEALTHGAMETEXT_H
#define CPP_SPACE_INVADER_SPACESHIPHEALTHGAMETEXT_H


#include "GameText.h"
#include "../../objects/Spaceship.h"

class SpaceshipHealthGameText : public GameText {
public:
    SpaceshipHealthGameText(SDL_Renderer* renderer, std::shared_ptr<Spaceship> spaceship, const std::string& fontPath, int fontSize, SDL_Color color, int x, int y) :
            GameText(std::to_string(spaceship->getHealth()), fontPath, fontSize, color, x,y,renderer),
            spaceship(spaceship),
            currentValue(spaceship->getHealth())
            {};

    void display(SDL_Renderer* renderer) override;

private:
    int currentValue;
    std::shared_ptr<Spaceship> spaceship;

};


#endif //CPP_SPACE_INVADER_SPACESHIPHEALTHGAMETEXT_H
