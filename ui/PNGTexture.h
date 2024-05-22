#ifndef CPP_SPACE_INVADER_TEXTURECREATORFROMPNG_H
#define CPP_SPACE_INVADER_TEXTURECREATORFROMPNG_H


#include <SDL.h>
#include <iostream>
#include <utility>
#include <string>
#include <SDL_image.h>

class PNGTexture {
public:
    PNGTexture(SDL_Renderer* renderer, const std::string& filePath)
    {
        loadTexture(renderer,  filePath, currentTexture);
    }

    ~PNGTexture(){
        if(currentTexture){
            SDL_DestroyTexture(currentTexture);
        }
    }

    virtual void print(SDL_Renderer* renderer, Uint32 ticks){};

protected:
    SDL_Texture* currentTexture{nullptr};

    void loadTexture(SDL_Renderer* renderer,  const std::string& filePath, SDL_Texture*& texture);
};


#endif //CPP_SPACE_INVADER_TEXTURECREATORFROMPNG_H
