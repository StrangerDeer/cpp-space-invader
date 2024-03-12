#pragma once

#include "FallingObject.h"
#include "ScoreObject.h"

class Asteroid : public FallingObject, public ScoreObject, public HealthObject
{
public:
    Asteroid(int maxHp, int health, int x, int y, int width, int height, int minSpeed, int maxSpeed, bool resettable, int points) :
            HealthObject(health), FallingObject(x, y, width, height, minSpeed, maxSpeed, resettable),
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

private:
    int maxHealth;
    void reset() {
        placeAtStartingPos();
        health = maxHealth;
    }
};

