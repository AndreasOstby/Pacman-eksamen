//
// Created by Baste Angelfoss on 02/04/2020.
//

#ifndef PACMAN_EKSAMEN_PACMAN_H
#define PACMAN_EKSAMEN_PACMAN_H


#include <iostream>
#include <map>
#include "Character.h"

class Pacman: public Character  {

    void calculateMove(int &pos, int &vel, double &distanceLeft);
    void atIntersection();

public:
    explicit Pacman(std::vector <std::vector<std::unique_ptr<Entity>>>& newMap);
    void move(long dt);
    void update(long dt) override;
    void updateVelocity() override;

};


#endif //PACMAN_EKSAMEN_PACMAN_H
