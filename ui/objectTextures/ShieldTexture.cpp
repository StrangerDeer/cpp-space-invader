#include "ShieldTexture.h"

void ShieldTexture::print(SDL_Renderer *renderer, Uint32 ticks) {
  if(!shield){
    std::cerr << "shield's texture doesn't exist!" << std::endl;
    return;
  }

  SDL_QueryTexture(currentTexture, nullptr, nullptr, &shield->rect.w, &shield->rect.h);
  SDL_Rect dstrect = { shield->rect.x, shield->rect.y, shield->width, shield->height };
  SDL_RenderCopyEx(renderer, currentTexture, nullptr, &dstrect, 45, nullptr, SDL_FLIP_NONE);
}
