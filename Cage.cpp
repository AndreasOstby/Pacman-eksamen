//
// Created by Andreas Østby on 17/04/2020.
//

#include "Cage.h"

Cage::Cage(double x, double y, int w, int h) {
    setPosition(x, y, w, h);

    spriteSheet = "cage";

    std::vector<SDL_Rect> valuesRight;
    valuesRight.emplace_back(SDL_Rect{0,0, 322,192});
    animations["default"] = valuesRight;

    state = "default";
}

void Cage::update(double dt, Screen &screen) {
    Entity::update(dt, screen);
}
