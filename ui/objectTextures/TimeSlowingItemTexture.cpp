#include "TimeSlowingItemTexture.h"

void TimeSlowingItemTexture::print(SDL_Renderer *renderer, Uint32 ticks) {
  if(!timeSlowItem){
    std::cerr << "timeSlowItem's texture doesn't exist!" << std::endl;
    return;
  }

  SDL_QueryTexture(currentTexture, nullptr, nullptr, &timeSlowItem->rect.w, &timeSlowItem->rect.h);
  SDL_Rect dstrect = { timeSlowItem->rect.x, timeSlowItem->rect.y, timeSlowItem->width, timeSlowItem->height };
  SDL_RenderCopy(renderer, currentTexture, nullptr, &dstrect);
}
