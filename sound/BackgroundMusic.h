#ifndef CPP_SPACE_INVADER_BACKGROUNDMUSIC_H
#define CPP_SPACE_INVADER_BACKGROUNDMUSIC_H

#include <SDL_mixer.h>
#include <iostream>

class BackgroundMusic {

public:
    BackgroundMusic(){
        init();
    }

    ~BackgroundMusic(){
        Mix_Quit();
        Mix_HaltMusic();
    }

    void playBackgroundMusic(){
        Mix_PlayMusic(music, 1);
    }

private:
    Mix_Music* music{nullptr};
    void init();

};


#endif //CPP_SPACE_INVADER_BACKGROUNDMUSIC_H
