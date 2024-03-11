#include "EventHandler.h"

void EventHandler::registerAction(const Uint32 eventType, const EventAction& action)
{
	if (const auto it = actions.find(eventType); it != actions.end())
	{
		it->second.insert(action);
	}
	else
	{
		std::multiset<EventAction, ActionComp> newSet{action};
		actions.insert({eventType, newSet});
	}
}

void EventHandler::registerAction(const std::vector<Uint32>& eventTypes, const EventAction& action)
{
	for (const Uint32 eventType : eventTypes)
		registerAction(eventType, action);
}

void EventHandler::deleteAction(const Uint32 eventType, const std::string& actionName)
{
	if (const auto it = actions.find(eventType); it != actions.end())
	{
		auto arr = it->second;
		for (auto i = arr.begin(); i != arr.end();)
		{
			if (i->getName() == actionName) i = arr.erase(i);
			else ++i;
		}
		if (arr.empty()) actions.erase(it);
	}
}

void EventHandler::executeAction(const SDL_Event& e) const
{
	if (const auto it = actions.find(e.type); it != actions.end())
	{
		for (const auto& action : it->second)
			action(e);
	}
}
