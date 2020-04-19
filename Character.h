//
// Created by Baste Angelfoss on 30/03/2020.
//

#ifndef PACMAN_EKSAMEN_CHARACTER_H
#define PACMAN_EKSAMEN_CHARACTER_H
#include "Map.h"
#include "Entity.h"
#include <cmath>
#include <random>

class Map;
class Character: public Entity {

protected:
    SDL_Point newVelocity {
        1,0
    };
    float initSpeed = 3;
    float speed = initSpeed;
    // Should be shared pointer
    Map& map;
    std::string aiState = "Chasing";
    void pathfind(Rect& pos);
    void calculateMove(double &pos, int &vel, double &distanceLeft);
    bool stopAtIntersection(double &distanceLeft);
    bool checkWallCollision(SDL_Point& vel);
    void checkPelletCollision();


public:
    SDL_Point velocity {
        1,0
    };
    int points = 0;
    bool isAi = false;

    Character(Map& newMap);
    void frightenGhost();
    double getDistance(Rect& rect, SDL_Point& offsetVel);
    void move(double dt);
    void setVelocity(int x,int y);
    virtual void updateVelocity();
    virtual void toCheckEveryStep()=0;
    virtual void ai()=0;
    void setAiState(std::string newState);
    virtual ~Character(){};

    void wrap();
};


#endif //PACMAN_EKSAMEN_CHARACTER_H
