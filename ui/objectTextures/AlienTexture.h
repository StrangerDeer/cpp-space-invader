#pragma once


#include <iostream>
#include "../../objects/Alien.h"
#include "../TextureCreatorFromPNG.h"

class AlienTexture : public TextureCreatorFromPNG {

public:
    AlienTexture(SDL_Renderer* renderer, const std::shared_ptr<Alien>& alien) :
    TextureCreatorFromPNG(renderer, "../ui/textures/spaceship.png")
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
