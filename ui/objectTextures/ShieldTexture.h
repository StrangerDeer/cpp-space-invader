#pragma once


#include "../HiddenTexture.h"
#include "../../objects/Shield.h"

class ShieldTexture : public HiddenTexture {
public:
    ShieldTexture(SDL_Renderer* renderer, const std::shared_ptr<Shield>& shield) :
      HiddenTexture(renderer, "../ui/textures/shield.png")
    {
      if(!shield){
        std::cerr << "shield doesn't exist!" << std::endl;
      } else {
        this->shield = shield;
      }
    };

    void print(SDL_Renderer*  renderer, Uint32 ticks) override;

private:
    std::shared_ptr<Shield> shield{nullptr};
};