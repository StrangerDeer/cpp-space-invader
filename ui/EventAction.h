#pragma once
#include <functional>
#include <string>
#include <SDL2/SDL_events.h>

class EventAction
{
public:
	EventAction(std::function<void(const SDL_Event& e)> fn, std::string n = "", int prio = 0);
	void operator()(const SDL_Event& e) const;
	[[nodiscard]] const std::string& getName() const;
	[[nodiscard]] int getPriority() const;

private:
	std::function<void(const SDL_Event& e)> function;
	std::string name;
	int priority;
};
