#include "HealingItemTexture.h"

void HealingItemTexture::print(SDL_Renderer *renderer, Uint32 ticks) {
    if(!healingItem){
        std::cerr << "healingItem's texture doesn't exist!" << std::endl;
        return;
    }

    SDL_QueryTexture(currentTexture, nullptr, nullptr, &healingItem->rect.w, &healingItem->rect.h);
    SDL_Rect dstrect = { healingItem->rect.x, healingItem->rect.y, healingItem->width, healingItem->height };
    SDL_RenderCopy(renderer, currentTexture, nullptr, &dstrect);
}
