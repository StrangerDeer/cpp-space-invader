#include "ShieldItemTexture.h"

void ShieldItemTexture::print(SDL_Renderer *renderer, Uint32 ticks) {
  if(!shieldItem){
    std::cerr << "shieldItem's texture doesn't exist!" << std::endl;
    return;
  }

  SDL_QueryTexture(currentTexture, nullptr, nullptr, &shieldItem->rect.w, &shieldItem->rect.h);
  SDL_Rect dstrect = { shieldItem->rect.x, shieldItem->rect.y, shieldItem->width, shieldItem->height };
  SDL_RenderCopy(renderer, currentTexture, nullptr, &dstrect);
}