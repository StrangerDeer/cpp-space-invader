#pragma once

#include <string>
#include <iostream>
#include <SDL_mixer.h>

class GameSoundEffect {
 public:
  GameSoundEffect(const std::string& filePath){
    initSoundEffect(filePath);
  }

  ~GameSoundEffect(){
    if(effect){
      Mix_FreeChunk(effect);
    }
  }

  void playSoundEffect(){
    if(!effect){
      std::cerr << "Sound effect is not exist!" << std::endl;
      return;
    }

    Mix_PlayChannel(-1, effect, 0);
  }

 private:
  Mix_Chunk* effect{nullptr};
  void initSoundEffect(const std::string& filePath);
};
