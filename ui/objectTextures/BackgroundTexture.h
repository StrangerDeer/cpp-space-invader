#pragma once


#include "../PNGTexture.h"
#include "../../objects/FallingObject.h"

class BackgroundTexture : public PNGTexture {

public:
    BackgroundTexture(SDL_Renderer* renderer, const std::shared_ptr<FallingObject>& backgroundElem, const std::string& filepath) :
        PNGTexture(renderer, filepath)
    {
        if(!backgroundElem){
            std::cerr << "BackgroundElem doesn't exist!" << std::endl;
        } else {
            this->elem = backgroundElem;
        }
    };

    void print(SDL_Renderer*  renderer, Uint32 ticks) override;

private:
    std::shared_ptr<FallingObject> elem{nullptr};
};