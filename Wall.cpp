//
// Created by Baste Angelfoss on 12/04/2020.
//

#include "Wall.h"

Wall::Wall(int x, int y) {
    spriteSheet = "entities";

    std::vector<SDL_Rect> valuesRight;
    int xOffset = 0;
    valuesRight.emplace_back(SDL_Rect{0 + xOffset,0,32-xOffset-1,32-xOffset});
    valuesRight.emplace_back(SDL_Rect{32 + xOffset,0,32-xOffset-1,32-xOffset});
    animations["default"] = valuesRight;

    state = "default";
    position.x = x;
    position.y = y;
    position.w = 20;
    position.h = 20;
}

void Wall::update(long dt) {
    Entity::update(dt);
}
