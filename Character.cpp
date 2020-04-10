//
// Created by Baste Angelfoss on 30/03/2020.
//

#include "Character.h"

Character::Character() {

}

void Character::setVelocity(int x, int y) {
    newVelocity.x = x;
    newVelocity.y = y;
}

void Character::updateVelocity() {

    velocity = newVelocity;

}

