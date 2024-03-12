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

    [[nodiscard]] const SDL_Rect* getRect() const {return &rect;}

    SDL_Rect rect{ 0, 0, 0, 0 };
};

