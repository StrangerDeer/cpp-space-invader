#include "GunBoosterTexture.h"

void GunBoosterTexture::print(SDL_Renderer *renderer, Uint32 ticks) {
    if(!gunBoosterItem){
        std::cerr << "gunBoosterItem's texture doesn't exist!" << std::endl;
        return;
    }

    SDL_QueryTexture(texture, nullptr, nullptr, &gunBoosterItem->rect.w, &gunBoosterItem->rect.h);
    SDL_Rect dstrect = { gunBoosterItem->rect.x, gunBoosterItem->rect.y, gunBoosterItem->width, gunBoosterItem->height };
    SDL_RenderCopy(renderer, texture, nullptr, &dstrect);
}
