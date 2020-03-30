//
// Created by Baste Angelfoss on 30/03/2020.
//

#ifndef PACMAN_EKSAMEN_PLAYERCONTROLLER_H
#define PACMAN_EKSAMEN_PLAYERCONTROLLER_H


#include "Screen.h"
#include "Controller.h"

class PlayerController: public Controller {

private:
    int up = 0;
    int down = 0;
    int left = 0;
    int right = 0;

public:
    PlayerController(int keyUp, int keyDown, int keyLeft, int keyRight);
    void move(const Uint8 *keys);



};


#endif //PACMAN_EKSAMEN_PLAYERCONTROLLER_H
