#pragma once
#include <vector>
#include "DimensionalObject.h"
#include "FlyingObject.h"
#include "HealthObject.h"
#include "SpaceshipBullet.h"
#include "../Util.h"

class Spaceship : public DimensionalObject, public FlyingObject, public HealthObject
{
public:
    Spaceship(int health, int speed, int x, int y, int width, int height, int fireRate) :
            HealthObject(health), FlyingObject(speed), DimensionalObject(x, y, width, height), fireRate(fireRate),
            linesOfFire(1), bulletSpeed(10), gunLvl(1), travelSpeed(23500) {
        points = 0;
    };

    std::vector<std::shared_ptr<SpaceshipBullet>> bullets;

    void increasePoints(int pts) {
        points += pts;
    }

    [[nodiscard]] int getPoints() const {
        return points;
    }

  [[nodiscard]] int getFirerate() const {
    return fireRate;
  }

    void moveLeft(){
        rect.x -= speed;
    }

    std::vector<std::shared_ptr<SpaceshipBullet>> shoot(){
      int x = rect.x + width / 2;
      int y = rect.y + height / 2;

      std::vector<std::shared_ptr<SpaceshipBullet>> newBullets;

      for (int i = 1; i <= linesOfFire; i++) {
          std::shared_ptr<SpaceshipBullet> bullet = std::make_shared<SpaceshipBullet>(x, y, bulletSpeed, i, linesOfFire);
          bullets.push_back(bullet);
          newBullets.push_back(bullet);
      }

      return newBullets;
    }

    void moveRight(){ rect.x += speed; }
    void moveUp(){ rect.y -= speed;}
    void moveDown(){ rect.y += speed;}

    void recieveHealing(int amount) {
        health += amount;
    }

    void increaseFireRate() {
        fireRate+=2;
        bulletSpeed+=2;
        gunLvl++;
    }

    void increaseLinesOfFire() {
        linesOfFire++;
    }

    int getLinesOfFire() {
        return linesOfFire;
    }

    int getGunLvl() const {
        return gunLvl;
    }

    void increaseTravelSpeed() {
        int randomNum = Util::getRandomNumber(12000, 15000);
        travelSpeed += randomNum;
    }

    int getTravelSpeed() const {
        return travelSpeed;
    }

private:
    int travelSpeed;
    int points;
    int fireRate;
    int bulletSpeed;
    int gunLvl;
    int linesOfFire;
};

