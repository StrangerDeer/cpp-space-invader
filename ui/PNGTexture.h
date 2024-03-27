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
        loadTexture(renderer,  filePath);
    }

    ~PNGTexture(){
        if(texture){
            SDL_DestroyTexture(texture);
        }
    }

    virtual void print(SDL_Renderer* renderer, Uint32 ticks){};

protected:
    SDL_Texture* texture{nullptr};

    void loadTexture(SDL_Renderer* renderer,  const std::string& filePath);
};


#endif //CPP_SPACE_INVADER_TEXTURECREATORFROMPNG_H
