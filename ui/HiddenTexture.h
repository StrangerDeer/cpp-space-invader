#pragma once


#include "PNGTexture.h"

class HiddenTexture : public PNGTexture {
public:
    HiddenTexture(SDL_Renderer* renderer, const std::string& originalFilePath) :
    PNGTexture(renderer, originalFilePath)
    {
      loadTexture(renderer,  originalFilePath, currentTexture);
      loadTexture(renderer, "../ui/textures/hidden.png", hiddenTexture);
      originalTexture = currentTexture;
    }

    ~HiddenTexture(){
      if(hiddenTexture){
        SDL_DestroyTexture(hiddenTexture);
      }
      if(originalTexture){
        SDL_DestroyTexture(originalTexture);
      }
      if(currentTexture){
        SDL_DestroyTexture(currentTexture);
      }
    }

    void hideTexture();

    void enableTexture();

protected:
    SDL_Texture* hiddenTexture{nullptr};
    SDL_Texture* originalTexture{nullptr};
    Uint32 swapStartTime{0};
    bool isSwapped{false};

};
