#pragma once
#include <SDL2/SDL.h>

class DimensionalObject
{
public:
    DimensionalObject(int x, int y, int width, int height) {
        rect.x = x;
        rect.y = y;
        rect.w = width;
        rect.h = height;
    }

    SDL_Rect getRect() {return rect;};

protected:
    SDL_Rect rect{ 0, 0, 0, 0 };
};

