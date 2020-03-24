#include <iostream>
#include <SDL.h>

int main() {
    SDL_Init(SDL_INIT_VIDEO); // Init.
    SDL_Window* window = nullptr; // Pointer to Window// Lag et vindu med gitte settings// For alle mulige konfigurasjonsalternativer, se: http://goo.gl/8vDJN
    window = SDL_CreateWindow ( "Et awesome SDL2-vindu!",SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, 550, 400,SDL_WINDOW_SHOWN|SDL_WINDOW_OPENGL);

    SDL_Event event;
    while (SDL_PollEvent(&event)) {

    }
    SDL_Delay(3000);
    return 0;
}