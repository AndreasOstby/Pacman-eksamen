//
// Created by Andreas Østby on 17/04/2020.
//

#ifndef PACMAN_EKSAMEN_CAGE_H
#define PACMAN_EKSAMEN_CAGE_H


#include "Entity.h"

class Cage: public Entity {
public:
    Cage(double x, double y, int w, int h);
    void update(double dt, Screen &screen) override;
};


#endif //PACMAN_EKSAMEN_CAGE_H
