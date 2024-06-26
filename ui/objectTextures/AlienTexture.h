#pragma once


#include <iostream>
#include "../../objects/Alien.h"
#include "../PNGTexture.h"
#include "../DamageTexture.h"

class AlienTexture : public DamageTexture{

public:
    AlienTexture(SDL_Renderer* renderer, const std::shared_ptr<Alien>& alien) :
        DamageTexture(renderer, "../ui/textures/alien.png", "../ui/textures/aliendamage.png")
    {
        if(!alien){
            std::cerr << "Alien doesn't exist!" << std::endl;
        } else {
            this->alien = alien;
        }
    };

    void print(SDL_Renderer*  renderer, Uint32 ticks) override;

private:
    std::shared_ptr<Alien> alien{nullptr};
};
