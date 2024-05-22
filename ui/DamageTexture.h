#pragma once
#include <windows.h>
#include <SDL_render.h>
#include <string>
#include "PNGTexture.h"

class DamageTexture : public PNGTexture {
public:
    DamageTexture(SDL_Renderer* renderer, const std::string& originalFilePath, const std::string& damageFilePath) :
            PNGTexture(renderer, originalFilePath)
    {
        loadTexture(renderer,  originalFilePath, currentTexture);
        loadTexture(renderer, damageFilePath, damageTexture);
        originalTexture = currentTexture;
    }

    ~DamageTexture(){
        if(damageTexture){
            SDL_DestroyTexture(damageTexture);
        }
        if(originalTexture){
            SDL_DestroyTexture(originalTexture);
        }
        if(currentTexture){
            SDL_DestroyTexture(currentTexture);
        }
    }

    void swapTexture();
    void updateTexture();

protected:
    SDL_Texture* damageTexture{nullptr};
    SDL_Texture* originalTexture{nullptr};
    Uint32 swapStartTime{0};
    bool isSwapped{false};

};