#pragma once

#include <vector>
#include <memory>
#include "FallingObject.h"

class BackgroundElement : public FallingObject {
public:
    BackgroundElement(int x, int y, int width, int height, int minSpeed, int maxSpeed, bool resettable);

    void placeAtStartingPos(int windowWidth, int windowsHeight) override;

};