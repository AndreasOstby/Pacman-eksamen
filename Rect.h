//
// Created by Andreas Østby on 15/04/2020.
//

#ifndef PACMAN_EKSAMEN_RECT_H
#define PACMAN_EKSAMEN_RECT_H


#include <SDL.h>

struct Rect {
    double x = 0;
    double y = 0;
    int w = 0;
    int h = 0;
    SDL_Rect getSDLRect();
};


#endif //PACMAN_EKSAMEN_RECT_H
