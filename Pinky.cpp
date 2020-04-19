//
// Created by Andreas Østby on 17/04/2020.
//

#include "Pinky.h"



Pinky::Pinky(Map &newMap) : Ghost(newMap) {
    std::vector<SDL_Rect> valuesRight;
    int tileSize = 32;
    valuesRight.emplace_back(SDL_Rect{0,tileSize*3, tileSize,tileSize});
    valuesRight.emplace_back(SDL_Rect{tileSize,tileSize*3,tileSize,tileSize});
    animations["moveRight"] = valuesRight;

    state = "moveRight";

    std::vector<SDL_Rect> valuesLeft;
    valuesLeft.emplace_back(SDL_Rect{tileSize*4,tileSize*3,tileSize,tileSize});
    valuesLeft.emplace_back(SDL_Rect{tileSize*5,tileSize*3,tileSize,tileSize});
    animations["moveLeft"] = valuesLeft;

    std::vector<SDL_Rect> valuesUp;
    valuesUp.emplace_back(SDL_Rect{tileSize*6,tileSize*3,tileSize,tileSize});
    valuesUp.emplace_back(SDL_Rect{tileSize*7,tileSize*3,tileSize,tileSize});
    animations["moveUp"] = valuesUp;

    std::vector<SDL_Rect> valuesDown;
    valuesDown.emplace_back(SDL_Rect{tileSize*2,tileSize*3,tileSize,tileSize});
    valuesDown.emplace_back(SDL_Rect{tileSize*3,tileSize*3,tileSize,tileSize});
    animations["moveDown"] = valuesDown;
}

void Pinky::aiChase() {
    std::shared_ptr<Character> closest = getClosestPacman();

    Rect rect{
            closest->getPosition().x - closest->velocity.x*map.scl*8,
            closest->getPosition().y - closest->velocity.y*map.scl*8,
            closest->getPosition().w,
            closest->getPosition().h
    };
    pathfind(rect);
}

void Pinky::aiScatter() {
    Rect rect{0, 0};
    pathfind(rect);
}
