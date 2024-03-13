#pragma once


#include <SDL_render.h>
#include <memory>
#include "../TextureCreatorFromPNG.h"
#include "../../objects/Star.h"

class StarTexture : public TextureCreatorFromPNG {

public:
StarTexture(SDL_Renderer* renderer, const std::shared_ptr<Star>& star, const std::string& filePath) :
    TextureCreatorFromPNG(renderer, filePath)
    {
        if(!star){
            std::cerr << "Star doesn't exist!" << std::endl;
        } else {
            this->star = star;
        }
    };

    void print(SDL_Renderer*  renderer, Uint32 ticks) override;

private:
    std::shared_ptr<Star> star{nullptr};
};
