#pragma once

#include "FallingObject.h"
#include "../ConfigGameItems.h"

class PickUpItem : public FallingObject {
public:
    PickUpItem(int x, int y, int alienWidth, int alienHeight) :
            FallingObject(x, y, 70, 130, 5, 5, true, DEFAULT_Y_MULTIPLIER), alienWidth(alienWidth), alienHeight(alienHeight) {
        removeFromScreen();
    };

    void placeAtSpawnPos(int x, int y) {
        setRandomSpeed();
        rect.x = x + alienWidth / 2 - width / 2;
        rect.y = y + alienHeight / 2 - height / 2;
    };

    void removeFromScreen() {
        currentSpeed = 0;
        rect.x = -width;
        rect.y = -height;
    }

protected:
    int alienWidth, alienHeight;
};