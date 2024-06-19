#include "PNGTexture.h"

void PNGTexture::loadTexture(SDL_Renderer *renderer, const std::string& filePath, SDL_Texture*& texture) {
    SDL_Surface* surface = IMG_Load(filePath.c_str());

    if(!surface){
        std::cerr << "Error: Image surface: " << SDL_GetError() << std::endl;
        return;
    }

    texture = SDL_CreateTextureFromSurface(renderer, surface);

    if(!texture){
        std::cerr << "Error: Image currentTexture: " << SDL_GetError() << std::endl;
        SDL_FreeSurface(surface);
        return;
    }

  SDL_FreeSurface(surface);
}
