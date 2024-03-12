#include "SpaceshipTexture.h"

void SpaceshipTexture::print(SDL_Renderer *renderer) {

    if(!spaceship){
        std::cerr << "Spaceship's texture doesn't exist!" << std::endl;
        return;
    }

    SDL_QueryTexture(texture, nullptr, nullptr, &spaceship->rect.w, &spaceship->rect.h);

    SDL_RenderCopy(renderer, texture, nullptr, &spaceship->rect);
}
