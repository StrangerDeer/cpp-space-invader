#pragma once

#include <SDL_render.h>
#include <memory>
#include "../PNGTexture.h"
#include "../../objects/Star.h"
#include "../../objects/Asteroid.h"

class AsteroidTexture : public PNGTexture {

public:
    AsteroidTexture(SDL_Renderer* renderer, const std::shared_ptr<Asteroid>& asteroid1, const std::string& filepath) :
        PNGTexture(renderer, filepath)
    {
        if(!asteroid1){
            std::cerr << "Asteroid1 doesn't exist!" << std::endl;
        } else {
            this->asteroid = asteroid1;
        }
    };

    void print(SDL_Renderer* renderer, Uint32 ticks) override;

private:
    std::shared_ptr<Asteroid> asteroid{nullptr};
    double angle = 0.0;
};
