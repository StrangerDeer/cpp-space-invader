#pragma once

#include <memory>
#include "HealthObject.h"
#include "Spaceship.h"

class Shield : public HealthObject, public DimensionalObject {
    Shield(std::shared_ptr<Spaceship>& ship) : spaceship(ship), maxHealth(3), HealthObject(maxHealth), DimensionalObject(0, 0, 100, 100), isEnabled(false) {
    }

    void takeDamage() {
      health--;
      if (health <= 0) {
        removeShield();
      }
    }

    void updateLocation() {
      rect.x = spaceship->rect.x;
      rect.y = spaceship->rect.y;
    }

    void addShield() {
      isEnabled = true;
      health = maxHealth;
      spaceship->enableShield();
    }

    void removeShield() {
      isEnabled = false;
      spaceship->disableShield();
    }

    bool isActive() {
      return isEnabled;
    }

private:
    std::shared_ptr<Spaceship>& spaceship;
    int maxHealth;
    bool isEnabled;
};