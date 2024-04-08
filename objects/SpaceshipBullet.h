#pragma once

#include <SDL_rect.h>

class SpaceshipBullet {

 public:

  SpaceshipBullet(int x, int y, int speed) :
  speed(speed), width(10), height(25), damage(1)
  {
    bulletRect.x = x;
    bulletRect.y = y;
    bulletRect.w = width;
    bulletRect.h = height;
  }

  virtual void move(){
    bulletRect.y -= speed;
  }

  int width, height, damage;
  SDL_Rect bulletRect{0,0,0,0};

protected:
  int speed;
};
