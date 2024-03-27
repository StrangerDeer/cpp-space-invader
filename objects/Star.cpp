#include "Star.h"

void Star::fall() {
  FallingObject::fall();

  if (rect.y > Config::windowHeight + 300) {
    placeAtStartingPos();
  }
}
