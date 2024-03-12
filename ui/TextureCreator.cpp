#include "TextureCreator.h"

void TextureCreator::loadTexture(SDL_Renderer *renderer, int width, int height, SDL_Color color) {
    SDL_Surface* textureSurface = SDL_CreateRGBSurface(0, width, height, 32, 0, 0, 0, 0);

    if (!textureSurface) {
        std::cerr << "Error: Unable to create SDL texture surface: " << SDL_GetError() << std::endl;
        return;
    }

    SDL_SetSurfaceColorMod(textureSurface, color.r, color.g, color.b);
    SDL_SetSurfaceAlphaMod(textureSurface, color.a);

    SDL_FillRect(textureSurface, nullptr, SDL_MapRGBA(textureSurface->format, color.r, color.g, color.b, color.a));

    texture = SDL_CreateTextureFromSurface(renderer, textureSurface);

    if (!texture) {
        std::cerr << "Error: Unable to create SDL texture: " << SDL_GetError() << std::endl;
        return;
    }

    SDL_SetTextureBlendMode(texture, SDL_BLENDMODE_BLEND);

    SDL_FreeSurface(textureSurface);

}