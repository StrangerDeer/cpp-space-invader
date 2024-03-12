#pragma once

#include "FallingObject.h"
#include "ScoreObject.h"

class Asteroid : public FallingObject, public ScoreObject, public HealthObject
{
public:
    Asteroid(int maxHp, int x, int y, int width, int height, int minSpeed, int maxSpeed, bool resettable, int points) :
            HealthObject(maxHp), FallingObject(x, y, width, height, minSpeed, maxSpeed, resettable),
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

    [[nodiscard]] double getRotation() const {return angleRotation;}

private:
    int maxHealth;
    double angleRotation;

    void getRandomRotation() {
        int rotation = Util::getRandomNumber(1, 30);
        angleRotation = (double)rotation / 10;
    }

    void reset() {
        placeAtStartingPos();
        health = maxHealth;
        getRandomRotation();
    }
};

