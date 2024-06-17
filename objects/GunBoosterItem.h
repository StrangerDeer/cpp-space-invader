#pragma once

#include "PickUpItem.h"
#include "Spaceship.h"

class GunBoosterItem : public PickUpItem {
public:
    GunBoosterItem(int x, int y, int spawnObjectWidth, int spawnObjectHeight) :
    PickUpItem(x, y, 70, 130) {
        removeFromScreen();
    };

    void increaseSpaceshipFireRate(std::shared_ptr<Spaceship> spaceship) const {
        spaceship->increaseFireRate();
    }
};