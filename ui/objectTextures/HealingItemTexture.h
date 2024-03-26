#pragma once


#include "../TextureCreatorFromPNG.h"
#include "../../objects/HealingItem.h"

class HealingItemTexture : public TextureCreatorFromPNG {
public:
    HealingItemTexture(SDL_Renderer* renderer, const std::shared_ptr<HealingItem>& healingItem) :
    TextureCreatorFromPNG(renderer, "../ui/textures/spaceship.png")
    {
        if(!healingItem){
            std::cerr << "HealingItem doesn't exist!" << std::endl;
        } else {
            this->healingItem = healingItem;
        }
    };

    void print(SDL_Renderer*  renderer, Uint32 ticks) override;

private:
    std::shared_ptr<HealingItem> healingItem{nullptr};

};

