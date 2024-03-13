#pragma once

#include "FallingObject.h"
#include "ScoreObject.h"

class Asteroid : public FallingObject, public ScoreObject, public HealthObject {
 public:
  Asteroid(int maxHp, int x, int y, int width, int height, int minSpeed, int maxSpeed, int points) :
      HealthObject(maxHp), FallingObject(x, y, width, height, minSpeed, maxSpeed, true),
            ScoreObject(points), maxHealth(maxHp) {
        getRandomRotation();
  };

  bool isDead() {
    if (health <= 0) {
      //TODO: set reset arguments according to window
      reset(0, 0);
      return true;
    }
    return false;
  };

  void reset(int windowWidth, int windowHeight) {
    placeAtStartingPos(windowWidth, windowHeight);
    health = maxHealth;
    getRandomRotation();
  }

  [[nodiscard]] double getRotation() const { return angleRotation; }

 private:
  int maxHealth;
  double angleRotation;

  void getRandomRotation() {
    int rotation = Util::getRandomNumber(1, 30);
    angleRotation = (double) rotation / 10;
  }
};

