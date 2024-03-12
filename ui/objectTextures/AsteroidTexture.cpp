#include "AsteroidTexture.h"

void AsteroidTexture::print(SDL_Renderer *renderer, Uint32 ticks) {
    if(!asteroid){
        std::cerr << "Asteroid1's texture doesn't exist!" << std::endl;
        return;
    }

    SDL_QueryTexture(texture, nullptr, nullptr, &asteroid->rect.w, &asteroid->rect.h);
    SDL_RenderCopyEx(renderer, texture, nullptr, &asteroid->rect, angle, nullptr, SDL_FLIP_NONE);
    angle++;
}
