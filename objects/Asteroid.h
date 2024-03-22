#pragma once

#include "FallingObject.h"
#include "ScoreObject.h"

class Asteroid : public FallingObject, public ScoreObject, public HealthObject {
 public:
  Asteroid(int maxHp, int x, int y, int width, int height, int minSpeed, int maxSpeed, int points, int windowWidth, int windowHeight) :
      HealthObject(maxHp), FallingObject(x, y, width, height, minSpeed, maxSpeed, true),
      ScoreObject(points), maxHealth(maxHp), windowWidth(windowWidth), windowHeight(windowHeight) {
        getRandomRotation();
  };

  bool isDead() {
    if (health <= 0) {
      //TODO: set reset arguments according to window
      reset();
      return true;
    }
    return false;
  };

  void reset() {
    placeAtStartingPos(windowWidth, windowHeight);
    health = maxHealth;
    getRandomRotation();
  }

  void reduceHp(int value){health -= value;}

  [[nodiscard]] double getRotation() const { return angleRotation; }

 private:
  int maxHealth;
  double angleRotation;
  int windowWidth, windowHeight;

  void getRandomRotation() {
    int rotation = Util::getRandomNumber(1, 30);
    angleRotation = (double) rotation / 10;
  }
};

