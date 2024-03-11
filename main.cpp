#define SDL_MAIN_HANDLED

#include "ui/SdlUi.h"

int main()
{
    SDL_SetMainReady();

    SdlUi ui("Sdl Window", 500, 300);
    return ui.run();
}
