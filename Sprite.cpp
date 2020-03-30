//
// Created by Baste Angelfoss on 30/03/2020.
//

#include "Sprite.h"

Sprite::Sprite(char *dir, SDL_Renderer &renderer) {
    SDL_Surface *surface = SDL_LoadBMP(dir);
    if (surface == nullptr) {
    }
    image = SDL_CreateTextureFromSurface(&renderer, surface);
    SDL_Rect coord;
    coord.x = 0;
    coord.y = 0;
    coord.w = 40;
    coord.h = 50;
    SDL_FreeSurface(surface);
}
