#pragma once


#include <memory>
#include "SDL_render.h"
#include "../../objects/Explosion.h"
#include "../PNGTexture.h"

class ExplosionTexture : public PNGTexture {
public:
    ExplosionTexture(SDL_Renderer* renderer, const std::shared_ptr<Explosion>& starItem) :
    PNGTexture(renderer, "../ui/textures/explosion.png")
    {
      if(!explosion){
        std::cerr << "explosion doesn't exist!" << std::endl;
      } else {
        this->explosion = starItem;
      }
    };

    void print(SDL_Renderer*  renderer, Uint32 ticks) override;

private:
    std::shared_ptr<Explosion> explosion{nullptr};
};