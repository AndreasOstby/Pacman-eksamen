//
// Created by Baste Angelfoss on 24/03/2020.
//

#ifndef PACMAN_EKSAMEN_SCREEN_H
#define PACMAN_EKSAMEN_SCREEN_H


#include <SDL.h>

class Screen {
public:
    Screen ();
    bool Init (const char* title, int width, int height);
    SDL_Window *window;
    SDL_Renderer *renderer;
};


#endif //PACMAN_EKSAMEN_SCREEN_H
