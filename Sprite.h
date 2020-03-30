//
// Created by Baste Angelfoss on 30/03/2020.
//

#ifndef PACMAN_EKSAMEN_SPRITE_H
#define PACMAN_EKSAMEN_SPRITE_H


#include <SDL.h>

class Sprite {

private:
    SDL_Texture *image;
    SDL_Rect position;

public:
    Sprite(char *dir, SDL_Renderer &renderer);
};


#endif //PACMAN_EKSAMEN_SPRITE_H
