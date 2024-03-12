#pragma once

#include <memory>
#include "Spaceship.h"

class ScoreObject
{
public:
    ScoreObject(int points) : points(points) {};
    void givePoints(std::shared_ptr<Spaceship> spaceship) const {
        spaceship->increasePoints(points);
    }


protected:
    int points;
};

