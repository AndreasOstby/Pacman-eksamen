#include <iostream>
#include <SDL.h>
#include "Screen.h"

int main() {
    Screen screen;
    screen.Init("Game WindoW", 600, 600);
    SDL_Delay(3000);
    SDL_DestroyWindow(screen.window);
    SDL_Quit();
}