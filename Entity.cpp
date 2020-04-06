//
// Created by Baste Angelfoss on 30/03/2020.
//

#include "Entity.h"
#include "Character.h"

bool Entity::isColliding(Character character) {
    return false;
}

void Entity::action(Character character) {

}

void Entity::update() {

}


Entity::Entity(){

}

void Entity::render(SDL_Renderer *renderer) {
    sprite.render(renderer, &position);

}







