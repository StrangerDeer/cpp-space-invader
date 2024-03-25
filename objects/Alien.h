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
    Alien(int maxHp, int x, int y, int width, int height, int points, int windowW, int windowH) :
            ScoreObject(points), HealthObject(maxHp), FallingObject(x, y, width, height, 10, 20, true),
            maxHealth(maxHp), windowWidth(windowW), windowHeight(windowH), fallingSpeed(5) {};

    std::vector<std::shared_ptr<AlienBullet>> bullets;

    std::shared_ptr<AlienBullet> shoot(int spaceshipWidth, int spaceshipHeight){
        int x = rect.x + spaceshipWidth / 2;
        int y = rect.y + spaceshipHeight / 2;

        std::shared_ptr<AlienBullet> bullet = std::make_shared<AlienBullet>(x, y);
        bullets.push_back(bullet);
        return bullet;
    }

    void fall() override {
        if (rect.y < windowHeight * 0.035) {
            rect.y += fallingSpeed;
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
    int fallingSpeed;
    int windowWidth, windowHeight;
};