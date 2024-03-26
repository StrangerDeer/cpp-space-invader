#pragma once

#include <memory>
#include "FallingObject.h"
#include "Spaceship.h"

class HealingItem : public FallingObject {
public:
    HealingItem(int x, int y, int width, int height) :
    FallingObject(x, y, width, height, 3, 3, true), healAmount(3) {
        removeFromScreen();
    };

    void placeAtStartingPos(int x, int y) override {
        setRandomSpeed();
        rect.x = x;
        rect.y = y;
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
};