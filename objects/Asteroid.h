#pragma once

#include "FallingObject.h"
#include "ScoreObject.h"

class Asteroid : public FallingObject, public ScoreObject, public HealthObject
{
public:
    Asteroid(int maxHp, int x, int y, int width, int height, int minSpeed, int maxSpeed, int points) :
            HealthObject(maxHp), FallingObject(x, y, width, height, minSpeed, maxSpeed, true),
            ScoreObject(points) {
        maxHealth = maxHp;
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
  }

private:
    int maxHealth;
};

