#pragma once
#include "DimensionalObject.h"
#include "../Util.h"
#include "../Config.h"

class FallingObject : public DimensionalObject {
 public:
  FallingObject(int x, int y, int width, int height, int minSpeed, int maxSpeed, bool resettable, int yMulti) :
      DimensionalObject(x, y, width, height), minSpeed(minSpeed), maxSpeed(maxSpeed), isResettable(resettable), yMultiplier(yMulti) {
    setRandomSpeed();
  };

  virtual void placeAtStartingPos() {
    setRandomSpeed();
    rect.x = Util::getRandomNumber(0, Config::windowWidth - width);
    rect.y = Util::getRandomNumber(-Config::windowHeight * yMultiplier, 0 - rect.h);
  };

  void setRandomSpeed() {
    currentSpeed = Util::getRandomNumber(minSpeed, maxSpeed);
  }

  virtual void fall() {
    rect.y += currentSpeed;
  }

  void increaseSpeed() {
      minSpeed = minSpeed + 1;
      maxSpeed = maxSpeed + 1;
  }

  void reduceSpeed() {
    if (minSpeed > 1) {
      minSpeed = minSpeed - 2;
    }
    if (maxSpeed > 5) {
      maxSpeed = maxSpeed - 2;
    }
  }

 protected:
  int minSpeed;
  int maxSpeed;
  int yMultiplier;
  int currentSpeed{};
  bool isResettable;
};

