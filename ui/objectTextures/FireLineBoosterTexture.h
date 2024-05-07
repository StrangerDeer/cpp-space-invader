#pragma once


#include <memory>
#include <iostream>
#include "../../objects/FireLineItem.h"
#include "../PNGTexture.h"

class FireLineBoosterTexture : public PNGTexture {
public:
    FireLineBoosterTexture(SDL_Renderer* renderer, const std::shared_ptr<FireLineItem>& fireLineBooster) :
    PNGTexture(renderer, "../ui/textures/firelinebooster.png")
    {
        if(!fireLineBooster){
            std::cerr << "FireLineItem doesn't exist!" << std::endl;
        } else {
            this->fireLineBooster = fireLineBooster;
        }
    };

    void print(SDL_Renderer*  renderer, Uint32 ticks) override;

private:
    std::shared_ptr<FireLineItem> fireLineBooster{nullptr};
};