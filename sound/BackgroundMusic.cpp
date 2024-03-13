//
// Created by Deer on 13/03/2024.
//

#include "BackgroundMusic.h"

void BackgroundMusic::init() {
    Mix_Init(MIX_INIT_MP3 | MIX_INIT_OPUS | MIX_INIT_OGG);

    Mix_OpenAudio(MIX_DEFAULT_FREQUENCY, AUDIO_S16SYS, MIX_DEFAULT_CHANNELS, 4096);

    music = Mix_LoadMUS("../sound/background.wav");

    if(!music){
        std::cerr << "Background music error:" << Mix_GetError() << std::endl;
    }

}
