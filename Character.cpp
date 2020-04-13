//
// Created by Baste Angelfoss on 30/03/2020.
//

#include "Character.h"

Character::Character(std::vector <std::vector<std::unique_ptr<Entity>>>& newMap): map(newMap) {

}

void Character::setVelocity(int x, int y) {
    newVelocity.x = x;
    newVelocity.y = y;
}

void Character::updateVelocity() {

    velocity = newVelocity;

}

