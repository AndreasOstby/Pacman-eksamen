//
// Created by Andreas Østby on 12/04/2020.
//

#ifndef PACMAN_EKSAMEN_PELLET_H
#define PACMAN_EKSAMEN_PELLET_H


#include "Entity.h"

class Pellet: public Entity{

public:
    Pellet(int x, int y, double scl);
    void update(double dt) override;
    void onCollision(Character &character) override;
};


#endif //PACMAN_EKSAMEN_PELLET_H
