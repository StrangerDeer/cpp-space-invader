#pragma once
#include <vector>
#include "DimensionalObject.h"
#include "FlyingObject.h"
#include "HealthObject.h"
#include "SpaceshipBullet.h"

class Spaceship : public DimensionalObject, public FlyingObject, public HealthObject
{
public:
    Spaceship(int health, int speed, int x, int y, int width, int height, int fireRate, int lineOfFire) :
            HealthObject(health), FlyingObject(speed), DimensionalObject(x, y, width, height), fireRate(fireRate),
            lineOfFire(lineOfFire), bulletSpeed(10), gunLvl(1) {
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

    std::shared_ptr<SpaceshipBullet> shoot(){
      int x = rect.x + width / 2;
      int y = rect.y + height / 2;

      std::shared_ptr<SpaceshipBullet> bullet = std::make_shared<SpaceshipBullet>(x, y, bulletSpeed);

      bullets.push_back(bullet);

      return bullet;
    }

    void moveRight(){ rect.x += speed; }
    void moveUp(){ rect.y -= speed;}
    void moveDown(){ rect.y += speed;}

    void recieveHealing(int amount) {
        health += amount;
    }

    void increaseFireRate() {
        fireRate++;
        bulletSpeed++;
        gunLvl++;
    }

    int getGunLvl() {
        return gunLvl;
    }

private:
    int points;
    int fireRate;
    int bulletSpeed;
    int gunLvl;
    int lineOfFire;
};

