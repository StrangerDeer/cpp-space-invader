#include "EventAction.h"


EventAction::EventAction(std::function<void(const SDL_Event& e)> fn, std::string n, const int prio):
	function(std::move(fn)),
	name(std::move(n)), priority(prio)
{
}

void EventAction::operator()(const SDL_Event& e) const
{
	function(e);
}

const std::string& EventAction::getName() const
{
	return name;
}

int EventAction::getPriority() const
{
	return priority;
}
