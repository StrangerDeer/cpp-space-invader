#pragma once

#include <SDL_rect.h>

class SpaceshipBullet {

 public:

  SpaceshipBullet(int x, int y) :
  speed(20), width(10), height(10), damage(1)
  {
    bulletRect.x = x;
    bulletRect.y = y;
    bulletRect.w = width;
    bulletRect.h = height;
  }

  void move(){
    bulletRect.y -= speed;
  }

  int width, height, damage;
  SDL_Rect bulletRect{0,0,0,0};

 private:
  int speed;
};
