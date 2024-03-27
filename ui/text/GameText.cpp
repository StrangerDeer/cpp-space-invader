//
// Created by Deer on 13/03/2024.
//

#include "GameText.h"

void GameText::print(SDL_Renderer *renderer) {
    SDL_QueryTexture(textTexture, nullptr, nullptr, &textRect.w, &textRect.h);

    SDL_RenderCopy(renderer, textTexture, nullptr, &textRect);
}

void GameText::loadFont(SDL_Renderer* renderer) {
    TTF_Font* font = nullptr;
    font = TTF_OpenFont(fontPath.c_str(), fontSize);

    if (!font) {
        std::cerr << "Error: Font coudn't open: " << TTF_GetError() << std::endl;
    }

    SDL_Surface* textSurface = TTF_RenderText_Solid(font, message.c_str(), textColor);

    if (!textSurface) {
        std::cerr << "Error: Textsurface coudn't create: " << TTF_GetError() << std::endl;
        TTF_CloseFont(font);
        SDL_FreeSurface(textSurface);
    }

    SDL_Texture* newTextTexture = SDL_CreateTextureFromSurface(renderer, textSurface);

    if (!newTextTexture) {
        std::cerr << "Error: Text's Texture couldn't create: " << SDL_GetError() << std::endl;
        TTF_CloseFont(font);
    }

    if(textTexture){
        SDL_DestroyTexture(textTexture);
    }

    textTexture = newTextTexture;

    TTF_CloseFont(font);
    //SDL_FreeSurface(textSurface);

}
