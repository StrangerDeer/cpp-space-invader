#include "HealingItemTexture.h"

void HealingItemTexture::print(SDL_Renderer *renderer, Uint32 ticks) {
    if(!healingItem){
        std::cerr << "healingItem's texture doesn't exist!" << std::endl;
        return;
    }

    SDL_QueryTexture(texture, nullptr, nullptr, &healingItem->rect.w, &healingItem->rect.h);
    Uint32 sprite = (ticks / 100) % 7;
    SDL_Rect srcrect = { static_cast<int>(sprite * 500), 0, 500, 500 };
    SDL_Rect dstrect = { healingItem->rect.x, healingItem->rect.y, healingItem->width, healingItem->height };
    //SDL_RenderCopy(renderer, texture, &srcrect, &dstrect);
    SDL_RenderCopyEx(renderer, texture, &srcrect, &dstrect, 0, nullptr, SDL_FLIP_NONE);
}
