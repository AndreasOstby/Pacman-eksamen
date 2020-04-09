//
// Created by Baste Angelfoss on 30/03/2020.
//

#ifndef PACMAN_EKSAMEN_CHARACTER_H
#define PACMAN_EKSAMEN_CHARACTER_H
#include "Entity.h"


class Character: public Entity {

protected:
    SDL_Point velocity {
        0,0
    };
    SDL_Point newVelocity {
        0,0
    };
    float speed = 1;
public:
    Character();
    void setVelocity(int x,int y);
    ~Character(){};

};


#endif //PACMAN_EKSAMEN_CHARACTER_H
