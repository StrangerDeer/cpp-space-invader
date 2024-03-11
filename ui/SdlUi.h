#pragma once

#include <memory>
#include <string>
#include <vector>
#include <SDL2/SDL.h>

#include "Component.h"
#include "EventHandler.h"

class SdlUi
{
public:
	SdlUi(std::string text, int w, int h);
	~SdlUi();
	int run();
	void addHandler(const std::shared_ptr<EventHandler>& handler);
	void removeHandler(const std::shared_ptr<EventHandler>& handler);
	void addComponent(const std::shared_ptr<Component>& comp);
	void removeComponent(const std::shared_ptr<Component>& comp);

private:
	struct ComponentComp
	{
		bool operator()(const std::shared_ptr<Component>& c1, const std::shared_ptr<Component>& c2) const
		{
			return c1->getLayer() < c2->getLayer();
		}
	};

	void init();
	[[nodiscard]] bool handleEvents() const;
	SDL_Window* window;
	SDL_Renderer* renderer;
	std::string windowText;
	int windowWidth;
	int windowHeight;
	std::vector<std::shared_ptr<EventHandler>> eventHandlers;
	std::multiset<std::shared_ptr<Component>, ComponentComp> components;
};
