//
// Created by Baste Angelfoss on 30/03/2020.
//

#include "Entity.h"


void Entity::render(Screen& screen) {
    SDL_Rect pos = position.getSDLRect();
    screen.draw(spriteSheet, &pos, &animations[state][floor(frame)]);
}

void Entity::action(Entity &entity) {

}

void Entity::update(double dt, Screen &screen) {
    if (cooldown > 0)
        cooldown -= dt;
    frame+=.25;
    frame = std::fmod(frame, animations[state].size());
}

Entity::Entity() {

}

void Entity::onCollision(Character &character) {

}

bool Entity::isCollision(Entity &entity, Rect extraOffset) {


    return  position.x + offset.x + extraOffset.x < entity.position.x + entity.offset.x + entity.position.w + entity.offset.w&&
            position.x + offset.x + position.w + offset.w +extraOffset.x> entity.position.x + entity.offset.x&&
            position.y + offset.y + extraOffset.y< entity.position.y + entity.offset.y + entity.position.h + entity.offset.h&&
            position.y + offset.y + position.h + offset.h + extraOffset.y > entity.position.y + entity.offset.y;

}

Rect &Entity::getPosition() {
    return position;
}

void Entity::setPosition(double x, double y, int w, int h){
    position = Rect{x,y,w,h};
}

void Entity::kill() {
    isDead = true;

}









