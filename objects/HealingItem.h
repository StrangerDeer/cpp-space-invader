#pragma once

#include <memory>
#include "FallingObject.h"
#include "Spaceship.h"
#include "PickUpItem.h"

class HealingItem : public PickUpItem {
public:
    HealingItem(int x, int y, int alienWidth, int alienHeight) :
    PickUpItem(x, y, 70, 130), healAmount(3) {
        removeFromScreen();
    };

    void healSpaceship(std::shared_ptr<Spaceship> spaceship) const {
        spaceship->recieveHealing(healAmount);
    }

private:
    int healAmount;
};