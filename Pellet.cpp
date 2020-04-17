//
// Created by Andreas Østby on 12/04/2020.
//

#include "Pellet.h"

Pellet::Pellet(int x, int y, double scl) {

    position.x = x;
    position.y = y;
    position.w = scl*2;
    position.h = scl*2;

    offset.x = scl/2-scl/4;
    offset.y = scl/2-scl/4;
    offset.w = -scl/2;
    offset.h = -scl/2;

    spriteSheet = "entities";

    std::vector<SDL_Rect> values;
    int tileSize = 32;
    values.emplace_back(SDL_Rect{tileSize,tileSize*9, tileSize, tileSize});
    animations["default"] = values;

    state = "default";

}

void Pellet::update(double dt, Screen &screen) {
    Entity::update(dt, screen);
    /*SDL_Rect rect;
    rect.x = position.x + offset.x;
    rect.y = position.y + offset.y;
    rect.w = position.w + offset.w;
    rect.h = position.h + offset.h;

    SDL_SetRenderDrawColor(screen.renderer, 50, 255, 50, 255);
    SDL_RenderFillRect(screen.renderer, &rect);*/
}

void Pellet::onCollision(Character &character) {
    character.points += 100;
    isDead = true;
}


