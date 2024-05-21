#pragma once

#include "PickUpItem.h"
#include "ScoreObject.h"

class StarItem : public PickUpItem, public ScoreObject {
public:
    StarItem(int x, int y, int alienWidth, int alienHeight) :
            PickUpItem(x, y, 70, 130), ScoreObject(100) {
        removeFromScreen();
    };
};