#pragma once


#include <memory>
#include <iostream>
#include "../../objects/StarItem.h"
#include "../PNGTexture.h"

class StarItemTexture : public PNGTexture {
public:
    StarItemTexture(SDL_Renderer* renderer, const std::shared_ptr<StarItem>& starItem) :
    PNGTexture(renderer, "../ui/textures/staritem.png")
    {
        if(!starItem){
            std::cerr << "starItem doesn't exist!" << std::endl;
        } else {
            this->starItem = starItem;
        }
    };

    void print(SDL_Renderer*  renderer, Uint32 ticks) override;

private:
    std::shared_ptr<StarItem> starItem{nullptr};
};