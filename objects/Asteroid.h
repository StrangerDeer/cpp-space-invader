#pragma once

#include "FallingObject.h"
#include "ScoreObject.h"

class Asteroid : public FallingObject, public ScoreObject, public HealthObject {
 public:
  Asteroid(int maxHp, int width, int height, int minSpeed, int maxSpeed, int points) :
      HealthObject(maxHp), FallingObject(Util::getRandomNumber(0, Config::windowWidth),
                                         Util::getRandomNumber(-Config::windowHeight * 3, (0 - Config::windowHeight) / 2),
                                         width, height, minSpeed, maxSpeed, true),
      ScoreObject(points), maxHealth(maxHp) {
        getRandomRotation();
  };

  bool isDead() {
    if (health <= 0) {
      reset();
      return true;
    }
    return false;
  };

  void reset() {
    placeAtStartingPos();
    health = maxHealth;
    getRandomRotation();
  }

  [[nodiscard]] double getRotation() const { return angleRotation; }

  void fall() override;

 private:
  int maxHealth;
  double angleRotation;

  void getRandomRotation() {
    int rotation = Util::getRandomNumber(1, 7);
    angleRotation = (double) rotation / 10;
  }
};

