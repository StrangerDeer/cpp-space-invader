#include "HiddenTexture.h"

void HiddenTexture::hideTexture() {
  currentTexture = hiddenTexture;
}

void HiddenTexture::enableTexture() {
  currentTexture = originalTexture;
}
