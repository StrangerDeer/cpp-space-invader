//
// Created by AsusTuf on 2024. 03. 12..
//

#include "StarTexture.h"

void StarTexture::print(SDL_Renderer *renderer, Uint32 ticks) {
    if(!bluestar){
        std::cerr << "Bluestar's texture doesn't exist!" << std::endl;
        return;
    }

    SDL_QueryTexture(texture, nullptr, nullptr, &bluestar->rect.w, &bluestar->rect.h);
    Uint32 sprite = (ticks / 100) % 6;
    SDL_Rect srcrect = { static_cast<int>(sprite * 195), 0, 195, 500 };
    SDL_Rect dstrect = { bluestar->rect.x, bluestar->rect.y, bluestar->width, bluestar->height };
    SDL_RenderCopy(renderer, texture, &srcrect, &dstrect);
}
