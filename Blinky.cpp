//
// Created by Andreas Østby on 17/04/2020.
//

#include "Blinky.h"

Blinky::Blinky(Map &newMap) : Ghost(newMap) {

    // Setting animations
    int tileSize = 32;
    std::vector<SDL_Rect> valuesRight;
    valuesRight.emplace_back(SDL_Rect{0,tileSize*2, tileSize,tileSize});
    valuesRight.emplace_back(SDL_Rect{tileSize,tileSize*2,tileSize,tileSize});
    animations["moveRight"] = valuesRight;

    state = "moveRight";

    std::vector<SDL_Rect> valuesLeft;
    valuesLeft.emplace_back(SDL_Rect{tileSize*4,tileSize*2,tileSize,tileSize});
    valuesLeft.emplace_back(SDL_Rect{tileSize*5,tileSize*2,tileSize,tileSize});
    animations["moveLeft"] = valuesLeft;

    std::vector<SDL_Rect> valuesUp;
    valuesUp.emplace_back(SDL_Rect{tileSize*6,tileSize*2,tileSize,tileSize});
    valuesUp.emplace_back(SDL_Rect{tileSize*7,tileSize*2,tileSize,tileSize});
    animations["moveUp"] = valuesUp;

    std::vector<SDL_Rect> valuesDown;
    valuesDown.emplace_back(SDL_Rect{tileSize*2,tileSize*2,tileSize,tileSize});
    valuesDown.emplace_back(SDL_Rect{tileSize*3,tileSize*2,tileSize,tileSize});
    animations["moveDown"] = valuesDown;
}

void Blinky::aiChase() {
    int closest = getClosestPacman();
    pathfind(map.pacman[closest]->getPosition());
}



void Blinky::aiScatter() {
    Rect rect{map.scl*map.w, 0};
    pathfind(rect);
}
