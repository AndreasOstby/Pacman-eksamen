//
// Created by Andreas Østby on 17/04/2020.
//

#ifndef PACMAN_EKSAMEN_INKY_H
#define PACMAN_EKSAMEN_INKY_H


#include "Ghost.h"

class Inky : public Ghost {
public:
    explicit Inky(Map &newMap);
    void aiChase() override;
    void aiScatter() override;
};


#endif //PACMAN_EKSAMEN_INKY_H
