#pragma once

#include <utility>
#include <vector>
#include "../Config.h"
#include "../ui/text/GameText.h"
#include "../ui/text/GameTextChangeColorAnim.h"
#include "../objects/Spaceship.h"
#include "../ui/PNGTexture.h"

class OpenStage {
public:
    OpenStage(SDL_Renderer* renderer, std::shared_ptr<int> isRunning) :
      isRunning(std::move(isRunning))
    {
        initGameTexts(renderer);
    }

    void run(SDL_Renderer* renderer);

    void addTexture(const std::shared_ptr<PNGTexture> texture){

      if(!texture){
        std::cerr << "Open Stage Error: Texture does not exist!" << std::endl;
        return;
      }

      itemTextures.push_back(texture);
    }

private:

    SDL_Event event;

    std::shared_ptr<int> isRunning;
    std::vector<std::shared_ptr<GameText>> texts;
    std::vector<std::shared_ptr<PNGTexture>> itemTextures;

    void initGameTexts(SDL_Renderer* renderer);
    void handleEvent();
    void printer(SDL_Renderer* renderer);
};
