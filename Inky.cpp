//
// Created by Andreas Østby on 17/04/2020.
//

#include "Inky.h"


Inky::Inky(Map &newMap) : Ghost(newMap) {

    // Setting animations
    int tileSize = 32;
    std::vector<SDL_Rect> valuesRight;
    valuesRight.emplace_back(SDL_Rect{0,tileSize*4, tileSize,tileSize});
    valuesRight.emplace_back(SDL_Rect{tileSize,tileSize*4,tileSize,tileSize});
    animations["moveRight"] = valuesRight;

    state = "moveRight";

    std::vector<SDL_Rect> valuesLeft;
    valuesLeft.emplace_back(SDL_Rect{tileSize*4,tileSize*4,tileSize,tileSize});
    valuesLeft.emplace_back(SDL_Rect{tileSize*5,tileSize*4,tileSize,tileSize});
    animations["moveLeft"] = valuesLeft;

    std::vector<SDL_Rect> valuesUp;
    valuesUp.emplace_back(SDL_Rect{tileSize*6,tileSize*4,tileSize,tileSize});
    valuesUp.emplace_back(SDL_Rect{tileSize*7,tileSize*4,tileSize,tileSize});
    animations["moveUp"] = valuesUp;

    std::vector<SDL_Rect> valuesDown;
    valuesDown.emplace_back(SDL_Rect{tileSize*2,tileSize*4,tileSize,tileSize});
    valuesDown.emplace_back(SDL_Rect{tileSize*3,tileSize*4,tileSize,tileSize});
    animations["moveDown"] = valuesDown;
}

void Inky::aiChase() {
    std::shared_ptr<Character> closest = getClosestPacman();

    Rect rect{
        closest->getPosition().x + closest->velocity.x*map.scl*8,
        closest->getPosition().y + closest->velocity.y*map.scl*8,
        closest->getPosition().w,
        closest->getPosition().h
    };
    pathfind(rect);
}

void Inky::aiScatter() {
    Rect rect{map.scl*map.w, map.scl*map.h};
    pathfind(rect);
}
