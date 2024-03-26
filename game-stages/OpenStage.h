#pragma once

#include "../Config.h"
#include <vector>
#include "../ui/text/GameText.h"

class OpenStage {
public:
    OpenStage(SDL_Renderer* renderer){
        initGameTexts(renderer);
    }

private:
    std::vector<std::shared_ptr<GameText>> texts{};

    void initGameTexts(SDL_Renderer* renderer);
};
