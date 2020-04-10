//
// Created by Baste Angelfoss on 30/03/2020.
//

#ifndef PACMAN_EKSAMEN_GAMEMANAGER_H
#define PACMAN_EKSAMEN_GAMEMANAGER_H
#include <vector>
#include <iostream>
#include <chrono>
#include "Entity.h"
#include "Controller.h"
#include "Screen.h"

class GameManager {
    std::chrono::milliseconds timeExpired;

public:
    Entity map [28] [31];
    std::vector <std::unique_ptr<Controller>> players;
    void setup();
    void setMap();
    void run();
    void update();
    Screen screen;
    void render();
    void getTimeDifference();
    std::chrono::milliseconds getTime();


};


#endif //PACMAN_EKSAMEN_GAMEMANAGER_H
