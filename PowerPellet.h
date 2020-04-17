//
// Created by Andreas Østby on 12/04/2020.
//

#ifndef PACMAN_EKSAMEN_POWERPELLET_H
#define PACMAN_EKSAMEN_POWERPELLET_H


#include "Pellet.h"

class PowerPellet: public Pellet {
public:
    PowerPellet(int x, int y, double scl);
    void update(double dt, Screen &screen) override;
};


#endif //PACMAN_EKSAMEN_POWERPELLET_H
