//
// Created by Baste Angelfoss on 02/04/2020.
//

#ifndef PACMAN_EKSAMEN_PACMAN_H
#define PACMAN_EKSAMEN_PACMAN_H


#include <iostream>
#include <vector>
#include <map>
#include "Character.h"
#include "Map.h"
#include "Screen.h"
#include "Wall.h"

class Pacman: public Character  {

    void calculateMove(int &pos, int &vel, double &distanceLeft, Screen &screen);
    bool stopAtIntersection(double &distanceLeft, Screen &screen);
    bool checkWallCollision(SDL_Point&, Screen &screen);

public:
    Pacman(Map& newMap);
    void move(long dt, Screen &screen);
    void update(long dt, Screen &screen) override;
    void updateVelocity() override;

};


#endif //PACMAN_EKSAMEN_PACMAN_H
