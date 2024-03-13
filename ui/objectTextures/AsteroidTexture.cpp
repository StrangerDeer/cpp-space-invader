#include "AsteroidTexture.h"

void AsteroidTexture::print(SDL_Renderer *renderer, Uint32 ticks) {
    if(!asteroid){
        std::cerr << "Asteroid1's texture doesn't exist!" << std::endl;
        return;
    }

    SDL_QueryTexture(texture, nullptr, nullptr, &asteroid->rect.w, &asteroid->rect.h);
    SDL_Rect dstrect = { asteroid->rect.x, asteroid->rect.y, asteroid->width, asteroid->height};
    SDL_RenderCopyEx(renderer, texture, nullptr, &dstrect, angle, nullptr, SDL_FLIP_NONE);
    angle += asteroid->getRotation();
}
