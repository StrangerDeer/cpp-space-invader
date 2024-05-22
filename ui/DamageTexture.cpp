#include "DamageTexture.h"
#include <synchapi.h>

void DamageTexture::swapTexture() {
    if (!isSwapped) {
        currentTexture = damageTexture;
        swapStartTime = SDL_GetTicks();
        isSwapped = true;
    }
}

void DamageTexture::updateTexture(int ticks) {
    if (isSwapped && (ticks - swapStartTime) >= 150) {
        currentTexture = originalTexture;
        isSwapped = false;
    }
}
