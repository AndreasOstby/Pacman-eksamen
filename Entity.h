//
// Created by Baste Angelfoss on 30/03/2020.
//

#ifndef PACMAN_EKSAMEN_ENTITY_H
#define PACMAN_EKSAMEN_ENTITY_H

#include "Sprite.h"
#include "Character.h"


class Entity: virtual public Sprite {

public:
    Entity();
    bool isColliding(Character character);
    void action(Character character);
    void update();
};



#endif //PACMAN_EKSAMEN_ENTITY_H
