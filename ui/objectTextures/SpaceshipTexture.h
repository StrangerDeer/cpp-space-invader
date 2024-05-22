#ifndef CPP_SPACE_INVADER_SPACESHIPTEXTURE_H
#define CPP_SPACE_INVADER_SPACESHIPTEXTURE_H

#include <utility>

#include "../PNGTexture.h"
#include "../../objects/Spaceship.h"
#include "../DamageTexture.h"

class SpaceshipTexture : public DamageTexture {

public:
    SpaceshipTexture(SDL_Renderer* renderer, const std::shared_ptr<Spaceship>& spaceship) :
        DamageTexture(renderer, "../ui/textures/spaceship.png", "../ui/textures/spaceshipdamage.png")
    {
        if(!spaceship){
            std::cerr << "Spaceship doesn't exist!" << std::endl;
        } else {
            this->spaceship = spaceship;
        }
    };

    void print(SDL_Renderer*  renderer, Uint32 ticks) override;

private:
    std::shared_ptr<Spaceship> spaceship{nullptr};
};


#endif //CPP_SPACE_INVADER_SPACESHIPTEXTURE_H
