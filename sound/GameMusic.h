#pragma once

#include <SDL_mixer.h>
#include <iostream>

class GameMusic {

public:
    GameMusic(const std::string& filePath){
        init(filePath);
    }

    ~GameMusic(){
        Mix_Quit();
        Mix_HaltMusic();
    }

    void playMusic(){
        Mix_PlayMusic(music, 1);
    }

private:
    Mix_Music* music{nullptr};
    void init(const std::string& filePath);

};

