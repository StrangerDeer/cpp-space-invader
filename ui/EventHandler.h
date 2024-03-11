#pragma once
#include <set>
#include <map>
#include <SDL2/SDL_events.h>

#include "EventAction.h"

class EventHandler
{
public:
	void registerAction(Uint32 eventType, const EventAction& action);
	void registerAction(const std::vector<Uint32>& eventTypes, const EventAction& action);
	void deleteAction(Uint32 eventType, const std::string& actionName);
	void executeAction(const SDL_Event& e) const;

private:
	struct ActionComp
	{
		bool operator()(const EventAction& a1, const EventAction& a2) const
		{
			return a1.getPriority() > a2.getPriority();
		}
	};

	std::map<Uint32, std::multiset<EventAction, ActionComp>> actions;
};
