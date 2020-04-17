//
// Created by Andreas Østby on 15/04/2020.
//

#include "Rect.h"

SDL_Rect Rect::getSDLRect() {
    return SDL_Rect{
        static_cast<int>(x),
        static_cast<int>(y),
        w,
        h
    };
}
