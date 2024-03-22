#pragma once

#include "GameSoundEffect.h"

void GameSoundEffect::initSoundEffect(const std::string &filePath) {
  effect = Mix_LoadWAV(filePath.c_str());

  if(!effect){
    std::cerr << "Sound effect load error:" << Mix_GetError() << std::endl;
    return;
  }
}
