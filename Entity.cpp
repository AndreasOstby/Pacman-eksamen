//
// Created by Baste Angelfoss on 30/03/2020.
//

#include "Entity.h"
#include "Character.h"

bool Entity::isColliding(Character character) {
    return false;
}

void Entity::render(Screen& screen) {
    screen.draw(spriteSheet, &position, &animations[state][frame]);

}

void Entity::action(Character character) {

}

void Entity::update() {
    frame++;
    frame %= animations[state].size();
}

Entity::Entity() {

}







