#include "SdlUi.h"

#include <iostream>
#include <stdexcept>

SdlUi::SdlUi(std::string text, const int w, const int h) : window(nullptr), renderer(nullptr),
                                                           windowText(std::move(text)),
                                                           windowWidth(w), windowHeight(h)
{
}

SdlUi::~SdlUi()
{
	SDL_DestroyRenderer(renderer);
	SDL_DestroyWindow(window);
	SDL_Quit();
}

int SdlUi::run()
{
	try
	{
		init();
		do
		{
			SDL_RenderClear(renderer);
			for (const auto& component : components)
				component->render(renderer);
			SDL_RenderPresent(renderer);
		}
		while (!handleEvents());
		return 0;
	}
	catch (const std::runtime_error& error)
	{
		std::cout << error.what() << "\n";
		return 1;
	}
}

void SdlUi::addHandler(const std::shared_ptr<EventHandler>& handler)
{
	eventHandlers.push_back(handler);
}

void SdlUi::removeHandler(const std::shared_ptr<EventHandler>& handler)
{
	eventHandlers.erase(std::remove(eventHandlers.begin(), eventHandlers.end(), handler), eventHandlers.end());
}

void SdlUi::addComponent(const std::shared_ptr<Component>& comp)
{
	components.insert(comp);
}

void SdlUi::removeComponent(const std::shared_ptr<Component>& comp)
{
	components.erase(comp);
}


void SdlUi::init()
{
	//Init SDL libraries
	if (SDL_Init(SDL_INIT_VIDEO) != 0) throw std::runtime_error("Error while initializing SDL libraries");

	//Create window
	window = SDL_CreateWindow(windowText.c_str(), 0, 0, windowWidth, windowHeight, SDL_WINDOW_HIDDEN);
	if (!window) throw std::runtime_error(SDL_GetError());
	SDL_SetWindowPosition(window, SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED);
	SDL_ShowWindow(window);

	//Create renderer
	renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);
	if (!renderer) throw std::runtime_error(SDL_GetError());
}

bool SdlUi::handleEvents() const
{
	bool quit{false};
	SDL_Event e;
	while (SDL_PollEvent(&e) != 0)
	{
		quit = e.type == SDL_QUIT;
		for (const auto& handler : eventHandlers)
		{
			handler->executeAction(e);
		}
	}
	return quit;
}
