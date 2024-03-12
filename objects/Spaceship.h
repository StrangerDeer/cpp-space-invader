#pragma once
#include "DimensionalObject.h"
#include "FlyingObject.h"
#include "HealthObject.h"

class Spaceship : public DimensionalObject, public FlyingObject, public HealthObject
{
public:
    Spaceship(int health, int speed, int x, int y, int width, int height, int fireRate, int lineOfFire) :
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

    void moveLeft() {
        rect.x += speed;
    }

    void moveRight() {
        rect.x -= speed;
    }

private:
    int points;
    int fireRate;
    int lineOfFire;
};

