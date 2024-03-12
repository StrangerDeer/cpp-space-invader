#ifndef CPP_SPACE_INVADER_TEXTURECREATOR_H
#define CPP_SPACE_INVADER_TEXTURECREATOR_H

#include <SDL.h>
#include <iostream>

class TextureCreator {
public:
    TextureCreator(SDL_Renderer* renderer, int width, int height, SDL_Color color)
    {
        loadTexture(renderer, width, height, color);
    }

    ~TextureCreator(){
        if(texture){
            SDL_DestroyTexture(texture);
        }
    }

    virtual void print(SDL_Renderer* renderer){};

protected:
    SDL_Texture* texture{nullptr};

    void loadTexture(SDL_Renderer* renderer, int width, int height, SDL_Color color);
};

#endif //CPP_SPACE_INVADER_TEXTURECREATOR_H
