#pragma once

#include "../TextureCreator.h"
#include "../../objects/SpaceshipBullet.h"

class BulletTexture : public TextureCreator {

 public:
  BulletTexture(SDL_Renderer* renderer, const std::shared_ptr<SpaceshipBullet>& bullet) :
      TextureCreator(renderer, bullet->bulletRect.w, bullet->bulletRect.h, SDL_Color{255,255,255,255}),
      bullet(bullet)
  {}

  void print(SDL_Renderer* renderer) override;

 private:
  std::shared_ptr<SpaceshipBullet> bullet;
};
