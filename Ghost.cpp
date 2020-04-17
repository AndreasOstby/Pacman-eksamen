//
// Created by Andreas Østby on 15/04/2020.
//

#include "Ghost.h"

Ghost::Ghost(Map &newMap): Character(newMap) {
    spriteSheet = "entities";

    position.x = map.cage->getPosition().x;
    position.y = map.cage->getPosition().y;
    position.w = map.scl*2;
    position.h = map.scl*2;

    std::vector<SDL_Rect> valuesRight;
    int tileSize = 32;
    valuesRight.emplace_back(SDL_Rect{0,tileSize*7, tileSize,tileSize});
    valuesRight.emplace_back(SDL_Rect{tileSize,tileSize*7,tileSize,tileSize});
    valuesRight.emplace_back(SDL_Rect{tileSize*2,tileSize*7, tileSize,tileSize});
    valuesRight.emplace_back(SDL_Rect{tileSize*3,tileSize*7,tileSize,tileSize});
    animations["Frightened"] = valuesRight;



}

void Ghost::update(double dt, Screen &screen) {
    move(dt, screen);
    Entity::update(dt,screen);
}

void Ghost::updateVelocity() {
    Character::updateVelocity();
    if(aiState == "Frightened"){
        state = aiState;
    }
    else if (velocity.x > 0) {
        state = "moveRight";
    }
    else if (velocity.x < 0) {
        state = "moveLeft";
    }
    else if (velocity.y > 0) {
        state = "moveDown";
    }
    else if (velocity.y < 0) {
        state = "moveUp";
    }
}

void Ghost::toCheckEveryStep() {
    //std::cout << "FPS: " << 2 << std::endl;

    for (auto & pac : map.pacman) {
        if(pac->isCollision(*this) && !isDead) {
            if(aiState == "Frightened") {
                kill();

            }
            else
            {
                pac->kill();
            }
        }
          //  std::cout << "a: " << pac->isCollision(*this) << std::endl;
    }

}
