#include "StarItemTexture.h"

void StarItemTexture::print(SDL_Renderer *renderer, Uint32 ticks) {
    if(!starItem){
        std::cerr << "starItem's texture doesn't exist!" << std::endl;
        return;
    }

    SDL_QueryTexture(texture, nullptr, nullptr, &starItem->rect.w, &starItem->rect.h);
    SDL_Rect dstrect = { starItem->rect.x, starItem->rect.y, starItem->width, starItem->height };
    SDL_RenderCopy(renderer, texture, nullptr, &dstrect);
}
