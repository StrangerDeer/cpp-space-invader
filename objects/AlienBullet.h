#pragma once

#include "SpaceshipBullet.h"

class AlienBullet : public SpaceshipBullet {
public:
    AlienBullet(int x, int y) : SpaceshipBullet(x, y, 15, 0, 0){};

    void move() override {
        bulletRect.y += speed;
    }
};