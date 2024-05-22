#include "AlienTexture.h"


void AlienTexture::print(SDL_Renderer *renderer, Uint32 ticks) {

    if(!alien){
        std::cerr << "Alien's texture doesn't exist!" << std::endl;
        return;
    }

    SDL_QueryTexture(currentTexture, nullptr, nullptr, &alien->rect.w, &alien->rect.h);
    Uint32 sprite = (ticks / 100) % 6;
    SDL_Rect srcrect = { static_cast<int>(sprite * 600), 0, 600, 400 };
    SDL_Rect dstrect = { alien->rect.x, alien->rect.y, alien->width, alien->height };
    SDL_RenderCopyEx(renderer, currentTexture, &srcrect, &dstrect, 0, nullptr, SDL_FLIP_NONE);
}