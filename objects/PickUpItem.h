#pragma once

#include "FallingObject.h"
#include "../ConfigGameItems.h"

class PickUpItem : public FallingObject {
public:
    PickUpItem(int x, int y, int spawnObjectWidth, int spawnObjectHeight) :
            FallingObject(x, y, 70, 130, 5, 5, true, DEFAULT_Y_MULTIPLIER), spawnObjectWidth(spawnObjectWidth), spawnObjectHeight(spawnObjectHeight) {
        removeFromScreen();
    };

    void placeAtSpawnPos(int x, int y) {
        setRandomSpeed();
        rect.x = x + spawnObjectWidth / 2 - width / 2;
        rect.y = y + spawnObjectHeight / 2 - height / 2;
    };

    void removeFromScreen() {
        currentSpeed = 0;
        rect.x = -width;
        rect.y = -height;
    }

protected:
    int spawnObjectWidth, spawnObjectHeight;
};