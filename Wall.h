//
// Created by Baste Angelfoss on 12/04/2020.
//

#ifndef PACMAN_EKSAMEN_WALL_H
#define PACMAN_EKSAMEN_WALL_H

#include "Entity.h"

class Wall: public Entity {

public:
    ~Wall(){

    }
    Wall(int x, int y, int scl);
    void update(double dt, Screen &screen) override;

};


#endif //PACMAN_EKSAMEN_WALL_H
