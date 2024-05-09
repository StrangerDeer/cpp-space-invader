#pragma once

#include "../Config.h"
#include "FallingObject.h"
#include "../ConfigGameItems.h"
#include "ScoreObject.h"

class Star : public FallingObject, public ScoreObject
{
public:
    Star(int textureId, int width, int height, int minSpeed, int maxSpeed, int points) :
            textureId(textureId),FallingObject(Util::getRandomNumber(0, Config::windowWidth),
                                               Util::getRandomNumber(-Config::windowHeight * 2, (0 - Config::windowHeight) / 2),
                                               width,
                                               height,
                                               minSpeed,
                                               maxSpeed,
                                               true,
                                               DEFAULT_Y_MULTIPLIER),
                                               ScoreObject(points) {};
    int textureId;

    void fall() override;
};

