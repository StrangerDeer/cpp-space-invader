#pragma once


#include "../HiddenTexture.h"
#include "../../objects/ShieldItem.h"

class ShieldItemTexture : public PNGTexture {

    ShieldItemTexture(SDL_Renderer* renderer, const std::shared_ptr<ShieldItem>& shieldItem) :
            PNGTexture(renderer, "../ui/textures/shielditem.png") {
      if(!shieldItem){
        std::cerr << "shieldItem doesn't exist!" << std::endl;
      } else {
        this->shieldItem = shieldItem;
      }
    };

    void print(SDL_Renderer*  renderer, Uint32 ticks) override;

private:
    std::shared_ptr<ShieldItem> shieldItem{nullptr};
};
