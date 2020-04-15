//
// Created by Baste Angelfoss on 30/03/2020.
//

#ifndef PACMAN_EKSAMEN_CHARACTER_H
#define PACMAN_EKSAMEN_CHARACTER_H
#include "Map.h"
#include "Entity.h"


class Map;
class Character: public Entity {

protected:
    SDL_Point velocity {
        1,0
    };
    SDL_Point newVelocity {
        1,0
    };
    float speed = 4;
    Map& map;

public:
    Character(Map& newMap);
    void setVelocity(int x,int y);
    virtual void updateVelocity();
    virtual ~Character(){};

};


#endif //PACMAN_EKSAMEN_CHARACTER_H
