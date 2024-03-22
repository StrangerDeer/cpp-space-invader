#pragma once

#include <iostream>
#include <string>
#include "BackgroundElement.h"


static std::vector<std::shared_ptr<BackgroundElement>> elements;

BackgroundElement::BackgroundElement(int x, int y, int width, int height, int minSpeed, int maxSpeed, bool resettable)
        : FallingObject(x, y, width, height, minSpeed, maxSpeed, resettable) {
    elements.push_back(static_cast<const std::shared_ptr<BackgroundElement>>(this));
}

void BackgroundElement::placeAtStartingPos(int windowWidth, int windowsHeight) {
    static int yPos = -windowsHeight * 1;
    int x = Util::getRandomNumber(0, windowWidth - width);
    setRandomSpeed();
    rect.x = x;
    rect.y = yPos;
}
