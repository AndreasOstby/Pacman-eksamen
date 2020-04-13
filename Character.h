//
// Created by Baste Angelfoss on 30/03/2020.
//

#ifndef PACMAN_EKSAMEN_CHARACTER_H
#define PACMAN_EKSAMEN_CHARACTER_H
#include "Entity.h"


class Character: public Entity {

protected:
    SDL_Point velocity {
        1,0
    };
    SDL_Point newVelocity {
        1,0
    };
    float speed = 1;
    std::vector <std::vector<std::unique_ptr<Entity>>>& map;

public:
    Character(std::vector <std::vector<std::unique_ptr<Entity>>>& newMap);
    void setVelocity(int x,int y);
    virtual void updateVelocity();
    ~Character(){};

};


#endif //PACMAN_EKSAMEN_CHARACTER_H
