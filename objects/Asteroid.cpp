#include "Asteroid.h"

void Asteroid::fall() {
  FallingObject::fall();
  if (rect.y > Config::windowHeight + 300) {
    placeAtStartingPos();
  }
}
