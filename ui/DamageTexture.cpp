#include "DamageTexture.h"
#include <synchapi.h>

void DamageTexture::swapTexture() {
    if (!isSwapped) {
        currentTexture = damageTexture;
        swapStartTime = SDL_GetTicks();
        isSwapped = true;
    }
}

void DamageTexture::updateTexture() {
    int ticks = SDL_GetTicks();
    if (isSwapped && (ticks - swapStartTime) >= 1000) {  // switch back after 1 second
        currentTexture = originalTexture;
        isSwapped = false;
    }
}
