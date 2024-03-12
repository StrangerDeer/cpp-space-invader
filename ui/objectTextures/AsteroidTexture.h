#pragma once

#include <SDL_render.h>
#include <memory>
#include "../TextureCreatorFromPNG.h"
#include "../../objects/Star.h"
#include "../../objects/Asteroid.h"

class AsteroidTexture : public TextureCreatorFromPNG {

public:
    AsteroidTexture(SDL_Renderer* renderer, const std::shared_ptr<Asteroid>& asteroid1, double angleRotation) :
            TextureCreatorFromPNG(renderer, "../ui/textures/asteroid1.png")
    {
        if(!asteroid1){
            std::cerr << "Asteroid1 doesn't exist!" << std::endl;
        } else {
            this->asteroid = asteroid1;
        }
        this->angleRotation = angleRotation;
    };

    void print(SDL_Renderer* renderer, Uint32 ticks) override;

private:
    std::shared_ptr<Asteroid> asteroid{nullptr};
    double angleRotation;
    double angle = 0.0;
};
