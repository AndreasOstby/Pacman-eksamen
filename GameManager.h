//
// Created by Baste Angelfoss on 30/03/2020.
//

#ifndef PACMAN_EKSAMEN_GAMEMANAGER_H
#define PACMAN_EKSAMEN_GAMEMANAGER_H
#include <vector>
#include <iostream>
#include "Entity.h"
#include "Controller.h"
#include "Screen.h"

class GameManager {

public:
    Entity map [28] [31];
    std::vector <std::unique_ptr<Controller>> players;
    void setup();
    void setMap();
    void update();
    Screen screen;



};


#endif //PACMAN_EKSAMEN_GAMEMANAGER_H
