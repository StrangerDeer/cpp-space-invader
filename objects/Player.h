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

    void moveLeft(){ rect.x -= speed;}
    void moveRight(){ rect.x += speed; }
    void moveUp(){ rect.y -= speed;}
    void moveDown(){ rect.y += speed;}

private:
    int points;
    int fireRate;
    int lineOfFire;
};

