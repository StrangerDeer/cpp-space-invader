#include "AlienTexture.h"


void AlienTexture::print(SDL_Renderer *renderer, Uint32 ticks) {

    if(!alien){
        std::cerr << "Alien's texture doesn't exist!" << std::endl;
        return;
    }

    SDL_QueryTexture(texture, nullptr, nullptr, &alien->rect.w, &alien->rect.h);
    Uint32 sprite = (ticks / 100) % 7;
    SDL_Rect srcrect = { static_cast<int>(sprite * 500), 0, 500, 500 };
    SDL_Rect dstrect = { alien->rect.x, alien->rect.y, alien->width, alien->height };
    //SDL_RenderCopy(renderer, texture, &srcrect, &dstrect);
    SDL_RenderCopyEx(renderer, texture, &srcrect, &dstrect, 225, nullptr, SDL_FLIP_NONE);
}