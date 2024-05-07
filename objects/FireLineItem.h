#pragma once

#include <memory>
#include "Spaceship.h"
#include "PickUpItem.h"

class FireLineItem : public PickUpItem {
public:
    FireLineItem(int x, int y, int alienWidth, int alienHeight) :
            PickUpItem(x, y, 70, 130) {
        removeFromScreen();
    };

    void increaseSpaceshipFireLine(std::shared_ptr<Spaceship> spaceship) const {
        spaceship->increaseLinesOfFire();
    }

private:
};