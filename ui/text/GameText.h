//
// Created by Deer on 13/03/2024.
//

#ifndef CPP_SPACE_INVADER_GAMETEXT_H
#define CPP_SPACE_INVADER_GAMETEXT_H

#include <SDL.h>
#include <SDL_ttf.h>
#include <string>
#include <iostream>
#include <utility>

class GameText {
public:
    GameText(SDL_Renderer* renderer,std::string  fontPath, int fontSize, std::string  message, const SDL_Color& color, int x, int y) :
            textTexture(nullptr), renderer(renderer), fontPath(std::move(fontPath)), fontSize(fontSize), message(std::move(message)),
            textColor(color)
    {
        if(TTF_Init() < 0){
            std::cerr << "Error: TTF_Init(): " << TTF_GetError() << std::endl;
        } else {
            loadFont();
        }
        textRect.x = x;
        textRect.y = y;
    };

    GameText(const GameText& other) = delete;

    ~GameText(){
        if (textTexture) {
            SDL_DestroyTexture(textTexture);
        }

        TTF_Quit();
    };

    virtual void display(SDL_Renderer* renderer);

    std::string message;

protected:
    SDL_Renderer* renderer;
    std::string fontPath;
    int fontSize;
    SDL_Color textColor;
    SDL_Texture* textTexture;
    SDL_Rect textRect{};

    void loadFont();
};


#endif //CPP_SPACE_INVADER_GAMETEXT_H
