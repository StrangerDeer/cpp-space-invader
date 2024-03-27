#pragma once
#include "DimensionalObject.h"
#include "../Util.h"
#include "../Config.h"

class FallingObject : public DimensionalObject {
 public:
  FallingObject(int x, int y, int width, int height, int minSpeed, int maxSpeed, bool resettable) :
      DimensionalObject(x, y, width, height), minSpeed(minSpeed), maxSpeed(maxSpeed), isResettable(resettable) {
    setRandomSpeed();
  };

  virtual void placeAtStartingPos() {
    setRandomSpeed();
    rect.x = Util::getRandomNumber(0, Config::windowWidth);
    rect.y = Util::getRandomNumber(-Config::windowHeight * 3, 0 - rect.h);
  };

  void setRandomSpeed() {
    currentSpeed = Util::getRandomNumber(minSpeed, maxSpeed);
  }

  virtual void fall() {
    rect.y += currentSpeed;
  }

 protected:
  int minSpeed;
  int maxSpeed;
  int currentSpeed{};
  bool isResettable;
};

