//
// Created by Andreas Østby on 17/04/2020.
//

#ifndef PACMAN_EKSAMEN_CAGE_H
#define PACMAN_EKSAMEN_CAGE_H
class Map;

#include "Entity.h"

class Cage: public Entity {
public:
    Cage(double x, double y, int w, int h);
    void update(double dt) override;
    int index = 0;
    void spawnghost(Map& map);
};


#endif //PACMAN_EKSAMEN_CAGE_H
