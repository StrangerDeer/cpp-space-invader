#ifndef CPP_SPACE_INVADER_TEXTURECREATORFROMPNG_H
#define CPP_SPACE_INVADER_TEXTURECREATORFROMPNG_H


#include <SDL.h>
#include <iostream>
#include <utility>
#include <string>
#include <SDL_image.h>

class TextureCreatorFromPNG {
public:
    TextureCreatorFromPNG(SDL_Renderer* renderer,  const std::string& filePath)
    {
        loadTexture(renderer,  filePath);
    }

    ~TextureCreatorFromPNG(){
        if(texture){
            SDL_DestroyTexture(texture);
        }
    }

    virtual void print(SDL_Renderer* renderer){};

protected:
    SDL_Texture* texture{nullptr};

    void loadTexture(SDL_Renderer* renderer,  const std::string& filePath);
};


#endif //CPP_SPACE_INVADER_TEXTURECREATORFROMPNG_H
