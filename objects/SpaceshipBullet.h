#pragma once

#include <SDL_rect.h>

class SpaceshipBullet {

 public:

  SpaceshipBullet(int x, int y, int speed, int lineNumber, int maxAmountLines) :
  speed(speed), width(10), height(25), damage(1), line(lineNumber), maxLines(maxAmountLines)
  {
    bulletRect.x = x-5;
    bulletRect.y = y;
    bulletRect.w = width;
    bulletRect.h = height;
  }

  virtual void move();

  int width, height, damage, line, maxLines;
  SDL_Rect bulletRect{0,0,0,0};

protected:
  int speed;
};
