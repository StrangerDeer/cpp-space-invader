#pragma once


#include <memory>
#include "../../objects/GunBoosterItem.h"
#include "../PNGTexture.h"

class GunBoosterTexture : public PNGTexture {
public:
    GunBoosterTexture(SDL_Renderer* renderer, const std::shared_ptr<GunBoosterItem>& gunBoosterItem) :
        PNGTexture(renderer, "../ui/textures/spaceship.png")
    {
    if(!gunBoosterItem){
        std::cerr << "GunBooster doesn't exist!" << std::endl;
    } else {
        this->gunBoosterItem = gunBoosterItem;
    }
};

    void print(SDL_Renderer*  renderer, Uint32 ticks) override;

private:
    std::shared_ptr<GunBoosterItem> gunBoosterItem{nullptr};
};