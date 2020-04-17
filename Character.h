//
// Created by Baste Angelfoss on 30/03/2020.
//

#ifndef PACMAN_EKSAMEN_CHARACTER_H
#define PACMAN_EKSAMEN_CHARACTER_H
#include "Map.h"
#include "Entity.h"
#include <cmath>

class Map;
class Character: public Entity {

protected:
    SDL_Point velocity {
        1,0
    };
    SDL_Point newVelocity {
        1,0
    };
    float speed = 3;
    Map& map;

    void calculateMove(double &pos, int &vel, double &distanceLeft, Screen &screen);
    bool stopAtIntersection(double &distanceLeft, Screen &screen);
    bool checkWallCollision(SDL_Point&, Screen &screen);
    void checkPelletCollision();

public:
    int points = 0;

    Character(Map& newMap);

    void move(double dt, Screen &screen);
    void setVelocity(int x,int y);
    virtual void updateVelocity();
    virtual void toCheckEveryStep()=0;
    virtual void ai()=0;

    virtual ~Character(){};

};


#endif //PACMAN_EKSAMEN_CHARACTER_H
