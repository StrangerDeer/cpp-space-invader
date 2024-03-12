#include "SpaceshipTexture.h"

void SpaceshipTexture::print(SDL_Renderer *renderer, Uint32 ticks) {

    if(!spaceship){
        std::cerr << "Spaceship's texture doesn't exist!" << std::endl;
        return;
    }

    SDL_QueryTexture(texture, nullptr, nullptr, &spaceship->rect.w, &spaceship->rect.h);
    Uint32 sprite = (ticks / 100) % 3;
    SDL_Rect srcrect = { static_cast<int>(sprite * 400), 0, 400, 500 };
    SDL_Rect dstrect = { 10, 10, spaceship->width, spaceship->height };
    SDL_RenderCopy(renderer, texture, &srcrect, &dstrect);
}
