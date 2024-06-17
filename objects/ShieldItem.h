#pragma once

#include "PickUpItem.h"
#include "HealthObject.h"
#include "Spaceship.h"

class ShieldItem : public PickUpItem {
    ShieldItem(int x, int y, int spawnObjectWidth, int spawnObjectHeight) :
            PickUpItem(x, y, 70, 130) {
      removeFromScreen();
    }
};