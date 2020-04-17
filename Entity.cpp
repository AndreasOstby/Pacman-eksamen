//
// Created by Baste Angelfoss on 30/03/2020.
//

#include "Entity.h"


void Entity::render(Screen& screen) {
    SDL_Rect pos = position.getSDLRect();
    screen.draw(spriteSheet, &pos, &animations[state][frame]);
}

void Entity::action(Entity &entity) {

}

void Entity::update(double dt, Screen &screen) {
    frame++;
    frame %= animations[state].size();
}

Entity::Entity() {

}

void Entity::onCollision(Character &character) {

}

bool Entity::isCollision(Entity &entity) {

    std::cout << "1. x: " << position.x + offset.x << " y: " << position.y + offset.y << " w: " << position.w + offset.w << " h: " << position.h + offset.h << std::endl;
    std::cout << "2. x: " << entity.position.x + entity.offset.x << " y: " << entity.position.y + entity.offset.y << " w: " << entity.position.w + entity.offset.w << " h: " << entity.position.h + entity.offset.h << std::endl;


    return  position.x + offset.x <= entity.position.x + entity.offset.x + entity.position.w + entity.offset.w&&
            position.x + offset.x + position.w + offset.w >= entity.position.x + entity.offset.x&&
            position.y + offset.y <= entity.position.y + entity.offset.y + entity.position.h + entity.offset.h&&
            position.y + offset.y + position.h + offset.h >= entity.position.y + entity.offset.y;

}

Rect &Entity::getPosition() {
    return position;
}

void Entity::setPosition(double x, double y, int w, int h){
    position = Rect{x,y,w,h};
}









