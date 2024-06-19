#pragma once

#include "DimensionalObject.h"

class Explosion : public DimensionalObject {
public:
    Explosion(int x, int y, int width, int height, Uint32 ticks) :
      DimensionalObject(x, y, width, height), beginTicks(ticks) {
    }

    bool checkIfShouldBeDestroyed(Uint32 ticks) const {
      if (ticks - beginTicks >= 1500) {
        return true;
      } else {
        return false;
      }
    }

private:
    Uint32 beginTicks;
};