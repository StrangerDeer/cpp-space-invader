#pragma once

#include "../TextureCreator.h"
#include "../../objects/SpaceshipBullet.h"

class BulletTexture : public TextureCreator {

 public:
  BulletTexture(SDL_Renderer* renderer, const std::shared_ptr<SpaceshipBullet>& bullet, SDL_Color color) :
      TextureCreator(renderer, bullet->bulletRect.w, bullet->bulletRect.h, color),
      bullet(bullet)
  {}

  void print(SDL_Renderer* renderer) override;

 private:
  std::shared_ptr<SpaceshipBullet> bullet;
};
