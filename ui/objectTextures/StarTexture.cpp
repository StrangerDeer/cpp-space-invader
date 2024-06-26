//
// Created by AsusTuf on 2024. 03. 12..
//

#include "StarTexture.h"

void StarTexture::print(SDL_Renderer *renderer, Uint32 ticks) {
    if(!star){
        std::cerr << "Bluestar's texture doesn't exist!" << std::endl;
        return;
    }

    SDL_QueryTexture(currentTexture, nullptr, nullptr, &star->rect.w, &star->rect.h);
    Uint32 sprite = (ticks / 100) % 6;
    SDL_Rect srcrect = { static_cast<int>(sprite * 195), 0, 195, 500 };
    SDL_Rect dstrect = {star->rect.x, star->rect.y, star->width, star->height };
    SDL_RenderCopy(renderer, currentTexture, &srcrect, &dstrect);
}
