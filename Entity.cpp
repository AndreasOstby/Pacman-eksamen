//
// Created by Baste Angelfoss on 30/03/2020.
//

#include "Entity.h"


bool Entity::isColliding(Entity &entity) {
    return false;
}

void Entity::render(Screen& screen) {
    screen.draw(spriteSheet, &position, &animations[state][frame]);

}

void Entity::action(Entity &entity) {

}

void Entity::update(long dt, Screen &screen) {
    frame++;
    frame %= animations[state].size();
}

Entity::Entity() {

}







