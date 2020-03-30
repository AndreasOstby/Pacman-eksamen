//
// Created by Baste Angelfoss on 30/03/2020.
//

#include "Sprite.h"

Sprite::Sprite(char *dir, SDL_Renderer &renderer) {
    SDL_Surface *surface = IMG_Load(dir);
    if (surface == nullptr) {
    }
    image = SDL_CreateTextureFromSurface(&renderer, surface);
    position.x = 0;
    position.y = 0;
    position.w = 40;
    position.h = 50;
    SDL_FreeSurface(surface);
}

void Sprite::render(Screen screen) {
    screen.draw(image, &position);
}
