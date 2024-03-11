#pragma once
#include <SDL2/SDL_rect.h>
#include <SDL2/SDL_render.h>

class Component
{
public:
	Component(const SDL_Rect& r = {0, 0, 0, 0}, const int l = 0) : rect(r), layer(l)
	{
	}

	virtual ~Component() = default;
	virtual void render(SDL_Renderer* renderer) = 0;
	[[nodiscard]] int getLayer() const;

protected:
	SDL_Rect rect;
	int layer;
};
