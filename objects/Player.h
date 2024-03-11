#pragma once
#include "DimensionalObject.h"
#include "FlyingObject.h"
#include "HealthObject.h"

class Player : public DimensionalObject, public FlyingObject, public HealthObject
{
public:
    Player(int health, int speed, int x, int y, int width, int height, int fireRate, int lineOfFire) :
            HealthObject(health), FlyingObject(speed), DimensionalObject(x, y, width, height), fireRate(fireRate),
            lineOfFire(lineOfFire) {
        points = 0;
    };

    void increasePoints(int pts) {
        points += pts;
    }

    [[nodiscard]] int getPoints() const {
        return points;
    }

private:
    int points;
    int fireRate;
    int lineOfFire;
};

