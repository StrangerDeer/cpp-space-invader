#pragma once

#include <utility>
#include <vector>
#include "../Config.h"
#include "../ui/text/GameText.h"
#include "../ui/text/GameTextChangeColorAnim.h"
#include "../objects/Spaceship.h"
#include "../ui/PNGTexture.h"
#include "../ui/objectTextures/SpaceshipTexture.h"

class OpenStage {
public:
    OpenStage(SDL_Renderer* renderer, std::shared_ptr<int> isRunning, std::shared_ptr<SpaceshipTexture>& currSpaceshipTexture, std::shared_ptr<Spaceship> spaceshipObj, std::shared_ptr<SDL_Color>& currBulletColor) :
            isRunning(std::move(isRunning)), currentSpaceshipTexture(currSpaceshipTexture), spaceship(std::move(spaceshipObj)), currentSpaceshipBulletColor(currBulletColor)
    {
        initGameTexts(renderer);
        initSpaceshipTextures(renderer);
        currentSpaceshipTexture = spaceshipTexture1;
        currentSpaceshipBulletColor = bulletColor1;
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
    std::shared_ptr<SpaceshipTexture>& currentSpaceshipTexture;
    std::shared_ptr<SDL_Color>& currentSpaceshipBulletColor;

    std::vector<std::shared_ptr<GameText>> texts;
    std::vector<std::shared_ptr<PNGTexture>> itemTextures;

    std::shared_ptr<SpaceshipTexture> spaceshipTexture1{nullptr};
    std::shared_ptr<SpaceshipTexture> spaceshipTexture2{nullptr};
    std::shared_ptr<SpaceshipTexture> spaceshipTexture3{nullptr};

    std::shared_ptr<SDL_Color> bulletColor1{nullptr};
    std::shared_ptr<SDL_Color> bulletColor2{nullptr};
    std::shared_ptr<SDL_Color> bulletColor3{nullptr};

    std::shared_ptr<Spaceship> spaceship;


    void initGameTexts(SDL_Renderer* renderer);
    void initSpaceshipTextures(SDL_Renderer* renderer);
    void handleEvent();
    void printer(SDL_Renderer* renderer);
};
