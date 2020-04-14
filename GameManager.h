//
// Created by Baste Angelfoss on 30/03/2020.
//

#ifndef PACMAN_EKSAMEN_GAMEMANAGER_H
#define PACMAN_EKSAMEN_GAMEMANAGER_H
#include <vector>
#include <iostream>
#include <chrono>
#include <fstream>

#include "Entity.h"
#include "Controller.h"
#include "Screen.h"
#include "PlayerController.h"
#include "Sprite.h"
#include "Pacman.h"
#include "Wall.h"
#include "Pellet.h"
#include "PowerPellet.h"

class GameManager {
    std::chrono::milliseconds timeExpired;
    int scl = 20;

public:
    std::vector <std::vector<std::unique_ptr<Entity>>> map;
    std::vector <std::unique_ptr<Controller>> players;

    void setup();
    bool setMap(int id);
    void run();
    void update();
    Screen screen;
    void render();
    void getTimeDifference();
    std::chrono::milliseconds getTime();


};


#endif //PACMAN_EKSAMEN_GAMEMANAGER_H
