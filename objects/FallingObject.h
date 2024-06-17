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
    if (currentSpeed > 3) {
      currentSpeed = currentSpeed - 3;
    } else if (currentSpeed > 2) {
      currentSpeed = currentSpeed - 2;
    } else if (currentSpeed > 1) {
      currentSpeed = currentSpeed - 1;
    }
  }

 protected:
  int minSpeed;
  int maxSpeed;
  int yMultiplier;
  int currentSpeed{};
  bool isResettable;
};

