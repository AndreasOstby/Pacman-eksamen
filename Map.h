//
// Created by Andreas Østby on 15/04/2020.
//

#ifndef PACMAN_EKSAMEN_MAP_H
#define PACMAN_EKSAMEN_MAP_H


#include <vector>
#include "Entity.h"
#include "Character.h"
class Character;
struct Map {
    std::vector <std::vector<std::unique_ptr<Entity>>> tileset;
    std::vector <std::shared_ptr<Character>> pacman;
    std::vector <std::shared_ptr<Character>> ghost;
    SDL_Point spawnPoint{0, 0};
    SDL_Rect cage{0, 0, 0, 0};
    double scl = 20;
    Map(int newScl);
    Map();
};


#endif //PACMAN_EKSAMEN_MAP_H
