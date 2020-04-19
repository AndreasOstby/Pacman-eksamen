//
// Created by Baste Angelfoss on 30/03/2020.
//

#ifndef PACMAN_EKSAMEN_GAMEMANAGER_H
#define PACMAN_EKSAMEN_GAMEMANAGER_H
#include <vector>
#include <iostream>
#include <chrono>
#include <fstream>
#include <thread>
#include <sstream>

#include "Map.h"
#include "Entity.h"
#include "Controller.h"
#include "Screen.h"
#include "PlayerController.h"
#include "Sprite.h"
#include "Pacman.h"
#include "Wall.h"
#include "Pellet.h"
#include "PowerPellet.h"
#include "Ghost.h"


class GameManager {
    std::chrono::time_point<std::chrono::steady_clock> currentFrame =
            std::chrono::high_resolution_clock::now();

    double frameDuration = 0;
    double framerate = 30;

public:
    Map map;
    std::vector <std::unique_ptr<Controller>> players;

    void setup();
    bool setMap(int id);
    void run();
    void update();
    Screen screen;
    void render();
    void getTime();
    void gameover();
    void nextLevel();


};


#endif //PACMAN_EKSAMEN_GAMEMANAGER_H
