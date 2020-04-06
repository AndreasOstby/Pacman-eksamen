//
// Created by Baste Angelfoss on 30/03/2020.
//

#ifndef PACMAN_EKSAMEN_CONTROLLER_H
#define PACMAN_EKSAMEN_CONTROLLER_H
#include "Character.h"
#include "Screen.h"

class Controller {

public:
    void setCharacter(std::unique_ptr<Character> &c);

    virtual void move(const Uint8 *keys) = 0;
    std::unique_ptr<Character> character;


};


#endif //PACMAN_EKSAMEN_CONTROLLER_H
