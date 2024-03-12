#pragma once


#include <SDL_render.h>
#include <memory>
#include "../TextureCreatorFromPNG.h"
#include "../../objects/Star.h"

class StarTexture : public TextureCreatorFromPNG {

public:
StarTexture(SDL_Renderer* renderer, const std::shared_ptr<Star>& bluestar, const std::string& filePath) :
    TextureCreatorFromPNG(renderer, filePath)
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
