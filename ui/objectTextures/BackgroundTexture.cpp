#include "BackgroundTexture.h"

void BackgroundTexture::print(SDL_Renderer *renderer, Uint32 ticks) {
    if(!elem){
        std::cerr << "BackgroundElem's texture doesn't exist!" << std::endl;
        return;
    }

    SDL_QueryTexture(texture, nullptr, nullptr, &elem->rect.w, &elem->rect.h);
    SDL_Rect dstrect = { elem->rect.x, elem->rect.y, elem->width, elem->height};
    SDL_RenderCopy(renderer, texture, nullptr, &dstrect);
}
