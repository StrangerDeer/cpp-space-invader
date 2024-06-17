#pragma once

#include "../PNGTexture.h"
#include "../../objects/PickUpItem.h"

class TimeSlowingItemTexture : public PNGTexture {
public:
    TimeSlowingItemTexture(SDL_Renderer* renderer, const std::shared_ptr<PickUpItem>& timeSlowItem) :
    PNGTexture(renderer, "../ui/textures/timeslowingitem.png")
    {
      if(!timeSlowItem){
        std::cerr << "timeSlowItem doesn't exist!" << std::endl;
      } else {
        this->timeSlowItem = timeSlowItem;
      }
    };

    void print(SDL_Renderer*  renderer, Uint32 ticks) override;

private:
    std::shared_ptr<PickUpItem> timeSlowItem{nullptr};
};