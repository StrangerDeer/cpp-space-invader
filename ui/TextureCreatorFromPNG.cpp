#include "TextureCreatorFromPNG.h"

void TextureCreatorFromPNG::loadTexture(SDL_Renderer *renderer,  const std::string& filePath) {
    SDL_Surface* surface = IMG_Load(filePath.c_str());

    if(!surface){
        std::cerr << "Error: Image surface: " << SDL_GetError() << std::endl;
        return;
    }

    texture = SDL_CreateTextureFromSurface(renderer,surface);

    if(!texture){
        std::cerr << "Error: Image texture: " << SDL_GetError() << std::endl;
        return;
    }
}
