#pragma once

#include <iostream>
#include <string>
#include "BackgroundElement.h"


static std::vector<std::shared_ptr<BackgroundElement>> elements;

BackgroundElement::BackgroundElement(int x, int y, int width, int height, int minSpeed, int maxSpeed, bool resettable)
        : FallingObject(x, y, width, height, minSpeed, maxSpeed, resettable, DEFAULT_Y_MULTIPLIER) {
    elements.push_back(static_cast<const std::shared_ptr<BackgroundElement>>(this));
}

void BackgroundElement::placeAtStartingPos() {
    static int yPos = -Config::windowHeight * 1;
    int x = Util::getRandomNumber(0, Config::windowWidth - width);
    setRandomSpeed();
    rect.x = x;
    rect.y = yPos;
}

void BackgroundElement::fall() {
  FallingObject::fall();
  if (rect.y > Config::windowHeight + (((height * 1.5) * NUMBER_OF_BACKGROUND_ELEMENTS) - Config::windowHeight - height)) {
    placeAtStartingPos();
  }
}
