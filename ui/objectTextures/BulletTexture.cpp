#pragma once

#include "BulletTexture.h"

void BulletTexture::print(SDL_Renderer *renderer) {
  SDL_QueryTexture(texture, nullptr, nullptr, &bullet->bulletRect.w, &bullet->bulletRect.h);

  SDL_RenderCopy(renderer, texture, nullptr, &bullet->bulletRect);
}

