//
// Created by Baste Angelfoss on 30/03/2020.
//

#ifndef PACMAN_EKSAMEN_CONTROLLER_H
#define PACMAN_EKSAMEN_CONTROLLER_H
#include "Character.h"

class Controller {

public:
    void setCharacter(Character c);

    virtual void move();

private:
    Character character;


};


#endif //PACMAN_EKSAMEN_CONTROLLER_H
