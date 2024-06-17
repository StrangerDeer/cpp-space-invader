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

    void stopMusic() {
        if(!music){
            std::cerr << "Music does not exist!" << std::endl;
            return;
        }
        Mix_PauseMusic();
    }

    void rewindMusic() {
        if(!music){
            std::cerr << "Music does not exist!" << std::endl;
            return;
        }
        Mix_RewindMusic();
    }

    void playMusic(){
        if(!music){
            std::cerr << "Music does not exist!" << std::endl;
            return;
        }

        Mix_PlayMusic(music, 999);
    }

private:
    Mix_Music* music{nullptr};
    void init(const std::string& filePath);

};

