#pragma once

#include <memory>
#include <vector>
#include <string>
#include "DimensionalObject.h"
#include "HealthObject.h"
#include "AlienBullet.h"
#include "FallingObject.h"
#include "ScoreObject.h"

class Alien : public HealthObject, public FallingObject, public ScoreObject {
public:
    Alien(int maxHp, int x, int y, int width, int height, int points, int windowW, int windowH) :
            ScoreObject(points), HealthObject(maxHp), FallingObject(x, y, width, height, 2, 15, true),
            maxHealth(maxHp), windowWidth(windowW), windowHeight(windowH), fallingSpeed(5) {
        chooseDestination();
    };

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
        } else {
            move();
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
    int chosenDestination;

    void move() {
        if (rect.x <= chosenDestination + currentSpeed && rect.x >= chosenDestination - currentSpeed) {
            chooseDestination();
        }
        if (rect.x < chosenDestination) {
            rect.x += currentSpeed;
        } else if (rect.x > chosenDestination) {
            rect.x -= currentSpeed;
        }
    }

    void chooseDestination() {
        setRandomSpeed();
        if (rect.x >= windowWidth / 2) {
            chosenDestination = Util::getRandomNumber(0, windowWidth / 2);
        } else {
            chosenDestination = Util::getRandomNumber(windowWidth / 2, windowWidth - width);
        }
    }
};