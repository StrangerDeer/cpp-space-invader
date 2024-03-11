#pragma once
#include "DimensionalObject.h"
#include "../Util.h"

class FallingObject : public DimensionalObject
{
public:
    FallingObject(int x, int y, int width, int height, int minSpeed, int maxSpeed, bool resettable) :
            DimensionalObject(x, y, width, height), minSpeed(minSpeed), maxSpeed(maxSpeed), isResettable(resettable) {
        setRandomSpeed();
    };

    void placeAtStartingPos() {
        setRandomSpeed();
        rect.x = 0;
        rect.y = 0;
    };

    void setRandomSpeed() {
        currentSpeed = Util::getRandomNumber(minSpeed, maxSpeed);
    }

protected:
    int minSpeed;
    int maxSpeed;
    int currentSpeed{};
    bool isResettable;
};

