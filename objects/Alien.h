#pragma once

#include <memory>
#include <vector>
#include <string>
#include "DimensionalObject.h"
#include "HealthObject.h"
#include "AlienBullet.h"
#include "FallingObject.h"
#include "ScoreObject.h"
#include "../ConfigGameItems.h"

class Alien : public HealthObject, public FallingObject, public ScoreObject {
public:
    Alien(int maxHp, int x, int y, int points) :
            ScoreObject(points), HealthObject(maxHp), FallingObject(x, y, 180, 120, 2, 15, true, DEFAULT_Y_MULTIPLIER),
            maxHealth(maxHp), fallingSpeed(5), shootCounter(0), shootLimit(30) {
        chooseDestination();
    };

    std::vector<std::shared_ptr<AlienBullet>> bullets;

    std::shared_ptr<AlienBullet> shoot(){
        int x = rect.x + width / 2;
        int y = rect.y + height / 2;

        std::shared_ptr<AlienBullet> bullet = std::make_shared<AlienBullet>(x, y);
        bullets.push_back(bullet);
        return bullet;
    }

    bool decideIfShooting() {
        if (shootCounter == shootLimit) {
            shootCounter = 0;
            int willShoot = Util::getRandomNumber(0, 1);
            if (willShoot == 1) {
                return true;
            }
            return false;
        }
        return false;
    }

    void fall() override {
        if (rect.y < Config::windowHeight * 0.005) {
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
        placeAtStartingPos();
        health = maxHealth;
    }

    void placeAtStartingPos() override {
      setRandomSpeed();
      rect.x = Util::getRandomNumber(0, Config::windowWidth - width);
      rect.y = Util::getRandomNumber(-Config::windowHeight * 9, 0 - rect.h);
    }

    void increaseDifficulty() {
        maxHealth = maxHealth + 1;
        shootLimit = shootLimit - 1;
    }

protected:
    int maxHealth;
    int fallingSpeed;
    int chosenDestination;
    int shootCounter, shootLimit;

    void move() {
        if (rect.x <= chosenDestination + currentSpeed && rect.x >= chosenDestination - currentSpeed) {
            chooseDestination();
        }
        if (rect.x < chosenDestination) {
            rect.x += currentSpeed;
        } else if (rect.x > chosenDestination) {
            rect.x -= currentSpeed;
        }
        shootCounter++;
    }

    void chooseDestination() {
        setRandomSpeed();
        if (rect.x >= Config::windowWidth / 2) {
            chosenDestination = Util::getRandomNumber(0, Config::windowWidth / 2);
        } else {
            chosenDestination = Util::getRandomNumber(Config::windowWidth / 2, Config::windowWidth - width);
        }
    }
};