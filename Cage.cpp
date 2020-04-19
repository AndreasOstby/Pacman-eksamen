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

void Cage::update(double dt) {
    Entity::update(dt);

}

void Cage::spawnghost(Map &map) {
    //Spawns ghosts outside cage
    if (cooldown <= 0&& index < map.ghost.size()){
        map.ghost[index]->getPosition().x = position.x + floor(position.w/2);
        map.ghost[index]->getPosition().y = position.y - map.scl*2;
        map.ghost[index]->velocity.x = 1;
        map.ghost[index]->velocity.y = 0;
        cooldown = 33*4;
        index++;
    }
}
