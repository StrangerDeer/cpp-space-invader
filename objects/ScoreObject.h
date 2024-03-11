#pragma once

#include <memory>
#include "Player.h"

class ScoreObject
{
public:
    ScoreObject(int points) : points(points) {};
    void givePoints(std::shared_ptr<Player> player) const {
        player->increasePoints(points);
    }


protected:
    int points;
};

