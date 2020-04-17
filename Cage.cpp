//
// Created by Andreas Østby on 17/04/2020.
//

#include "Cage.h"

Cage::Cage(double x, double y, int w, int h) {
    setPosition(x, y, w, h);

    spriteSheet = "entities";

    std::vector<SDL_Rect> valuesRight;
    int tileSize = 32;
    valuesRight.emplace_back(SDL_Rect{0,tileSize*2, tileSize,tileSize});
    valuesRight.emplace_back(SDL_Rect{tileSize,tileSize*2,tileSize,tileSize});
    animations["default"] = valuesRight;

    state = "default";
}

void Cage::update(double dt, Screen &screen) {
    Entity::update(dt, screen);
}
