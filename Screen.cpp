//
// Created by Baste Angelfoss on 24/03/2020.
//

#include "Screen.h"
#include <SDL.h>

Screen::Screen() {
}

bool Screen::Init(const char *title, int width, int height) {
    if(SDL_Init(SDL_INIT_VIDEO)!= 0 ){
        return true;
    }
    window = SDL_CreateWindow(title, 0, 0, width, height,SDL_WINDOW_SHOWN|SDL_WINDOW_OPENGL);
    if(window == nullptr){
        return true;
    }
    renderer = SDL_CreateRenderer(window, -1, 0);
    if(renderer == nullptr){
        return true;
    }
    SDL_SetRenderDrawColor(renderer, 255,255,255,255);

}
