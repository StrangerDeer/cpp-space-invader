#pragma once

#include "FallingObject.h"
#include "ScoreObject.h"

class Asteroid : public FallingObject, public ScoreObject, public HealthObject {
 public:
  Asteroid(int maxHp, int width, int height, int minSpeed, int maxSpeed, int points, int minRot, int maxRot, int maxYMultiplier) :
      HealthObject(maxHp), FallingObject(Util::getRandomNumber(0, Config::windowWidth),
                                         Util::getRandomNumber(-Config::windowHeight * maxYMultiplier, (0 - Config::windowHeight) / 2),
                                         width, height, minSpeed, maxSpeed, true, maxYMultiplier),
      ScoreObject(points), maxHealth(maxHp), minRotation(minRot), maxRotation(maxRot) {
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

  void increaseHealth() {
      maxHealth++;
  }

 private:
  int maxHealth;
  double angleRotation;
  int minRotation, maxRotation;

  void getRandomRotation() {
    int rotation = Util::getRandomNumber(minRotation, maxRotation);
    angleRotation = (double) rotation / 10;
  }
};

