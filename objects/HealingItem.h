#pragma once

#include <memory>
#include "FallingObject.h"
#include "Spaceship.h"

class HealingItem : public FallingObject {
public:
    HealingItem(int x, int y, int width, int height, int alienWidth, int alienHeight) :
    FallingObject(x, y, width, height, 3, 3, true), healAmount(1), alienWidth(alienWidth), alienHeight(alienHeight) {
        removeFromScreen();
    };

    void placeAtSpawnPos(int x, int y) {
        setRandomSpeed();
        rect.x = x + alienWidth / 2;
        rect.y = y + alienHeight / 2;
    };

    void removeFromScreen() {
        currentSpeed = 0;
        rect.x = -width;
        rect.y = -height;
    }

    void healSpaceship(std::shared_ptr<Spaceship> spaceship) const {
        spaceship->recieveHealing(healAmount);
    }

private:
    int healAmount;
    int alienWidth, alienHeight;
};