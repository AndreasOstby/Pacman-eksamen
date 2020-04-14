//
// Created by Baste Angelfoss on 02/04/2020.
//

#ifndef PACMAN_EKSAMEN_PACMAN_H
#define PACMAN_EKSAMEN_PACMAN_H


#include <iostream>
#include <map>
#include "Character.h"

class Pacman: public Character  {

    void calculateMove(int &pos, int &vel, double &distanceLeft, Screen &screen);
    void atIntersection(double &distanceLeft, Screen &screen);
    bool checkWallCollision(SDL_Point&, Screen &screen);
    int &scl;

public:
    explicit Pacman(std::vector <std::vector<std::unique_ptr<Entity>>>& newMap, int &sscl);
    void move(long dt, Screen &screen);
    void update(long dt, Screen &screen) override;
    void updateVelocity() override;

};


#endif //PACMAN_EKSAMEN_PACMAN_H
