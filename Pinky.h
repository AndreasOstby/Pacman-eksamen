//
// Created by Andreas Østby on 17/04/2020.
//

#ifndef PACMAN_EKSAMEN_PINKY_H
#define PACMAN_EKSAMEN_PINKY_H


#include "Ghost.h"

class Pinky  : public Ghost {
public:
    Pinky(Map &newMap);
    void ai() override;

};



#endif //PACMAN_EKSAMEN_PINKY_H
