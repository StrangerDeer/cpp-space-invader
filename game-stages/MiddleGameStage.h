#pragma once

#include <SDL_events.h>

#include <utility>

#include "../Config.h"

class MiddleGameStage {
 public:
  MiddleGameStage(std::shared_ptr<int> isRunning) :
  isRunning(std::move(isRunning))
  {}

  void run();

 private:
  SDL_Event event;

  std::shared_ptr<int> isRunning;
  void handleEvent();
};
