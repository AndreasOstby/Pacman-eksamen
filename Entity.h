//
// Created by Baste Angelfoss on 30/03/2020.
//

#ifndef PACMAN_EKSAMEN_ENTITY_H
#define PACMAN_EKSAMEN_ENTITY_H

#include "Sprite.h"



class Character;
class Entity {

protected:
    SDL_Rect position{
        0,0,0,0
    };
    static int scl;



public:
    Entity();
    bool isColliding(Character character);
    void action(Character character);
    void update();
    Sprite sprite;
    void render(SDL_Renderer *renderer);
};

int Entity::scl = 20;


#endif //PACMAN_EKSAMEN_ENTITY_H
