//
// Created by Andreas Østby on 15/04/2020.
//

#ifndef PACMAN_EKSAMEN_MAP_H
#define PACMAN_EKSAMEN_MAP_H


#include <vector>
#include "Entity.h"
#include "Cage.h"
#include "Character.h"
class Character;
class Cage;
struct Map {
    std::vector <std::vector<std::shared_ptr<Entity>>> tileset;
    std::vector <std::shared_ptr<Character>> pacman;
    std::vector <std::shared_ptr<Character>> ghost;
    SDL_Point spawnPoint{0, 0};
    std::shared_ptr<Cage> cage;
    double scl = 20;
    double w = 0;
    double h = 0;
    int id = 0;
    Map(int newScl);
    Map();
};


#endif //PACMAN_EKSAMEN_MAP_H
