#include "FireLineBoosterTexture.h"

void FireLineBoosterTexture::print(SDL_Renderer *renderer, Uint32 ticks) {
    if(!fireLineBooster){
        std::cerr << "fireLineBooster's texture doesn't exist!" << std::endl;
        return;
    }

    SDL_QueryTexture(texture, nullptr, nullptr, &fireLineBooster->rect.w, &fireLineBooster->rect.h);
    SDL_Rect dstrect = { fireLineBooster->rect.x, fireLineBooster->rect.y, fireLineBooster->width, fireLineBooster->height };
    SDL_RenderCopy(renderer, texture, nullptr, &dstrect);
}
