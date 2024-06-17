#pragma once

#include "PickUpItem.h"
#include "HealthObject.h"
#include "Spaceship.h"

class ShieldItem : public PickUpItem, public HealthObject {
    ShieldItem(int x, int y, int spawnObjectWidth, int spawnObjectHeight) :
            PickUpItem(x, y, 70, 130), HealthObject(3) {
    }

    void addShield(std::shared_ptr<Spaceship> spaceship) {
        spaceship->enableShield();
    }

    void removeShield(std::shared_ptr<Spaceship> spaceship) {
      spaceship->disableShield();
    }
};
