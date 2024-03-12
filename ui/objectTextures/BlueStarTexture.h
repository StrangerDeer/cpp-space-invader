#pragma once


#include <SDL_render.h>
#include <memory>
#include "../TextureCreatorFromPNG.h"
#include "../../objects/Star.h"

class BlueStarTexture : public TextureCreatorFromPNG {

public:
BlueStarTexture(SDL_Renderer* renderer, const std::shared_ptr<Star>& bluestar) :
    TextureCreatorFromPNG(renderer, "../ui/textures/bluestar_spritesheet.png")
    {
        if(!bluestar){
            std::cerr << "Bluestar doesn't exist!" << std::endl;
        } else {
            this->bluestar = bluestar;
        }
    };

    void print(SDL_Renderer*  renderer, Uint32 ticks) override;

private:
    std::shared_ptr<Star> bluestar{nullptr};
};
