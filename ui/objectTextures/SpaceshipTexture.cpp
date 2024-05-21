#include "SpaceshipTexture.h"

void SpaceshipTexture::print(SDL_Renderer *renderer, Uint32 ticks) {

    if(!spaceship){
        std::cerr << "Spaceship's texture doesn't exist!" << std::endl;
        return;
    }

    SDL_QueryTexture(texture, nullptr, nullptr, &spaceship->rect.w, &spaceship->rect.h);
    Uint32 sprite = (ticks / 100) % 7;
    SDL_Rect srcrect = { static_cast<int>(sprite * 500), 0, 500, 500 };
    SDL_Rect dstrect = { spaceship->rect.x, spaceship->rect.y, spaceship->width, spaceship->height };
    SDL_RenderCopyEx(renderer, texture, &srcrect, &dstrect, 45, nullptr, SDL_FLIP_NONE);
}
