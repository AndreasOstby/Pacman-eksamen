//
// Created by Andreas Østby on 15/04/2020.
//

#ifndef PACMAN_EKSAMEN_MAP_H
#define PACMAN_EKSAMEN_MAP_H


#include <vector>
#include "Entity.h"
#include "Pacman.h"
#include "Ghost.h"

struct Map {
    std::vector <std::vector<std::unique_ptr<Entity>>> tileset;
    std::vector <Pacman> pacman;
    std::vector <Ghost> ghost;
    SDL_Point spawnPoint{0, 0};
    SDL_Rect cage{0, 0, 0, 0};
    int scl = 0;
    Map(int newScl);
};


#endif //PACMAN_EKSAMEN_MAP_H
