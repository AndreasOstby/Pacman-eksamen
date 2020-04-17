//
// Created by Andreas Østby on 17/04/2020.
//

#ifndef PACMAN_EKSAMEN_BLINKY_H
#define PACMAN_EKSAMEN_BLINKY_H


#include "Ghost.h"

class Blinky : public Ghost {
public:
    explicit Blinky(Map &newMap);
    void ai() override;

};



#endif //PACMAN_EKSAMEN_BLINKY_H
