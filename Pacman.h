//
// Created by Baste Angelfoss on 02/04/2020.
//

#ifndef PACMAN_EKSAMEN_PACMAN_H
#define PACMAN_EKSAMEN_PACMAN_H


#include <iostream>
#include <map>
#include "Character.h"

class Pacman: public Character  {


public:
    explicit Pacman();
    void move(int dt);
};


#endif //PACMAN_EKSAMEN_PACMAN_H
