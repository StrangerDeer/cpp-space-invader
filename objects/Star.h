#pragma once

#include "FallingObject.h"
#include "ScoreObject.h"

class Star : public FallingObject, public ScoreObject
{
public:
    Star(int x, int y, int width, int height, int minSpeed, int maxSpeed, bool resettable, int points) :
            FallingObject(x, y, width, height, minSpeed, maxSpeed, resettable), ScoreObject(points) {};

protected:
};

