//
// Created by Andreas Østby on 15/04/2020.
//

#ifndef PACMAN_EKSAMEN_GHOST_H
#define PACMAN_EKSAMEN_GHOST_H


#include "Character.h"

class Ghost:public Character{



public:
    explicit Ghost(Map& newMap);
    void update(double dt) override;
    void updateVelocity() override;
    void toCheckEveryStep() override;
    void kill() override;
    void ai()override;
    virtual void aiScatter() = 0;
    virtual void aiChase() = 0;
    int getClosestPacman();
};


#endif //PACMAN_EKSAMEN_GHOST_H
