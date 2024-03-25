#pragma once

#include <memory>
#include <vector>
#include "DimensionalObject.h"
#include "HealthObject.h"
#include "AlienBullet.h"
#include "FallingObject.h"
#include "ScoreObject.h"

class Alien : public HealthObject, public FallingObject, public ScoreObject {
public:
    Alien(int maxHp, int minSpeed, int maxSpeed, int x, int y, int width, int height, int points, int windowW, int windowH) :
            ScoreObject(points), HealthObject(maxHp), FallingObject(x, y, width, height, minSpeed, maxSpeed, true),
            maxHealth(maxHp), windowWidth(windowW), windowHeight(windowH){};

    std::vector<std::shared_ptr<AlienBullet>> bullets;

    std::shared_ptr<AlienBullet> shoot(int spaceshipWidth, int spaceshipHeight){
        int x = rect.x + spaceshipWidth / 2;
        int y = rect.y + spaceshipHeight / 2;

        std::shared_ptr<AlienBullet> bullet = std::make_shared<AlienBullet>(x, y);
        bullets.push_back(bullet);
        return bullet;
    }

    void fall() override {
        if (rect.y < 50) {
            rect.y += currentSpeed;
        }
    }

    bool isDead() {
        if (health <= 0) {
            reset();
            return true;
        }
        return false;
    };

    void reset() {
        placeAtStartingPos(windowWidth, windowHeight);
        health = maxHealth;
    }

protected:
    int maxHealth;
    int windowWidth, windowHeight;
};