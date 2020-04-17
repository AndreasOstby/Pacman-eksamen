//
// Created by Andreas Østby on 15/04/2020.
//

#ifndef PACMAN_EKSAMEN_GHOST_H
#define PACMAN_EKSAMEN_GHOST_H


#include "Character.h"

class Ghost:public Character{



public:
    explicit Ghost(Map& newMap);
    void update(double dt, Screen &screen) override;
    void updateVelocity() override;
    void toCheckEveryStep() override;
};


#endif //PACMAN_EKSAMEN_GHOST_H
