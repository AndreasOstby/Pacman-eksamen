//
// Created by Andreas Østby on 15/04/2020.
//

#include "Ghost.h"

Ghost::Ghost(Map &newMap): Character(newMap) {
    spriteSheet = "entities";

    position.x = map.cage.x;
    position.y = map.cage.y;
    position.w = map.scl*2;
    position.h = map.scl*2;
}

void Ghost::update(double dt, Screen &screen) {
    move(dt, screen);
    Entity::update(dt,screen);
}

void Ghost::updateVelocity() {
    Character::updateVelocity();

    if (velocity.x > 0) {
        state = "moveRight";
    }
    if (velocity.x < 0) {
        state = "moveLeft";
    }
    if (velocity.y > 0) {
        state = "moveDown";
    }
    if (velocity.y < 0) {
        state = "moveUp";
    }
}

void Ghost::toCheckEveryStep() {
    //std::cout << "FPS: " << 2 << std::endl;

    for (auto & pac : map.pacman) {
        if(pac->isCollision(*this)) {
            pac->isDead = true;

        }
          //  std::cout << "a: " << pac->isCollision(*this) << std::endl;
    }

}
