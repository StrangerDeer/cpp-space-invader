#pragma once
#include <SDL2/SDL.h>

class DimensionalObject
{
public:
    DimensionalObject(int x, int y, int width, int height) {
        rect.x = x;
        rect.y = y;
        rect.w = width;
        this->width = width;
        this->height = height;
        rect.h = height;
    }

    int width;
    int height;
    SDL_Rect rect{ 0, 0, 0, 0 };
};

