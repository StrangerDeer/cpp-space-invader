#include "ExplosionTexture.h"

void ExplosionTexture::print(SDL_Renderer *renderer, Uint32 ticks) {
  if(!explosion){
    std::cerr << "explosion's texture doesn't exist!" << std::endl;
    return;
  }

  if (!currentTexture) {
    std::cerr << "Error: Current texture is not loaded!" << std::endl;
    return;
  }

  //SDL_QueryTexture(currentTexture, nullptr, nullptr, &explosion->rect.w, &explosion->rect.h);
  SDL_Rect dstrect = { explosion->rect.x, explosion->rect.y, explosion->width, explosion->height };
  SDL_RenderCopy(renderer, currentTexture, nullptr, &dstrect);
}

