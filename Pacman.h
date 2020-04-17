//
// Created by Baste Angelfoss on 02/04/2020.
//

#ifndef PACMAN_EKSAMEN_PACMAN_H
#define PACMAN_EKSAMEN_PACMAN_H


#include <iostream>
#include <vector>
#include <cmath>
#include <map>
#include "Character.h"
#include "Map.h"
#include "Screen.h"
#include "Wall.h"

class Pacman: public Character  {

public:
    explicit Pacman(Map& newMap);
    void update(double dt, Screen &screen) override;
    void updateVelocity() override;
    void toCheckEveryStep() override;
    void ai() override ;
};


#endif //PACMAN_EKSAMEN_PACMAN_H
