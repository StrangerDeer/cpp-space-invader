#pragma once

#include <vector>
#include <memory>
#include "../ConfigGameItems.h"
#include "FallingObject.h"

class BackgroundElement : public FallingObject {
public:
    BackgroundElement(int x, int y, int width, int height, int minSpeed, int maxSpeed, bool resettable);

    void placeAtStartingPos() override;

    void fall() override;

};