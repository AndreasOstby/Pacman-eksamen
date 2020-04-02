//
// Created by Baste Angelfoss on 30/03/2020.
//

#ifndef PACMAN_EKSAMEN_CHARACTER_H
#define PACMAN_EKSAMEN_CHARACTER_H
#include "Entity.h"

class Character: virtual public Entity {

    SDL_Point velocity {
        0,0
    };
    SDL_Point newVelocity {
        0,0
    };
    float Speed = 1;
public:
    Character();


};


#endif //PACMAN_EKSAMEN_CHARACTER_H
