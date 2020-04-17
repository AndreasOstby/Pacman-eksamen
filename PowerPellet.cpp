//
// Created by Andreas Østby on 12/04/2020.
//

#include "PowerPellet.h"

PowerPellet::PowerPellet(int x, int y, double scl) : Pellet(x, y, scl) {
    position.x = x;
    position.y = y;
    position.w = scl;
    position.h = scl;

    spriteSheet = "entities";

    std::vector<SDL_Rect> values;
    int tileSize = 32;
    values.emplace_back(SDL_Rect{0,tileSize*9, tileSize, tileSize});
    animations["default"] = values;

    state = "default";
}

void PowerPellet::update(double dt, Screen &screen) {
    Pellet::update(dt, screen);
}
