#ifndef CPP_SPACE_INVADER_SPACESHIPTEXTURE_H
#define CPP_SPACE_INVADER_SPACESHIPTEXTURE_H

#include <utility>

#include "TextureCreatorFromPNG.h"
#include "../objects/Player.h"

class SpaceshipTexture : public TextureCreatorFromPNG {

public:
    SpaceshipTexture(SDL_Renderer* renderer, const std::shared_ptr<Player>& spaceship) :
    TextureCreatorFromPNG(renderer, "../ui/textures/ship2.png")
    {
        if(!spaceship){
            std::cerr << "Spaceship doesn't exist!" << std::endl;
        } else {
            this->spaceship = spaceship;
        }
    };

    void print(SDL_Renderer*  renderer) override;

private:
    std::shared_ptr<Player> spaceship{nullptr};
};


#endif //CPP_SPACE_INVADER_SPACESHIPTEXTURE_H
