//
// Created by Baste Angelfoss on 02/04/2020.
//

#include "Pacman.h"


Pacman::Pacman(Map& newMap): Character(newMap) {

    spriteSheet = "entities";

    std::vector<SDL_Rect> valuesRight;
    int tileSize = 32;
    valuesRight.emplace_back(SDL_Rect{0,0, tileSize,tileSize});
    valuesRight.emplace_back(SDL_Rect{tileSize,0,tileSize,tileSize});
    animations["moveRight"] = valuesRight;

    state = "moveRight";

    std::vector<SDL_Rect> valuesLeft;
    valuesLeft.emplace_back(SDL_Rect{tileSize*4,0,tileSize,tileSize});
    valuesLeft.emplace_back(SDL_Rect{tileSize*3,0,tileSize,tileSize});
    animations["moveLeft"] = valuesLeft;

    std::vector<SDL_Rect> valuesUp;
    valuesUp.emplace_back(SDL_Rect{tileSize*5,0,tileSize,tileSize});
    valuesUp.emplace_back(SDL_Rect{tileSize*6,0,tileSize,tileSize});
    animations["moveUp"] = valuesUp;

    std::vector<SDL_Rect> valuesDown;
    valuesDown.emplace_back(SDL_Rect{tileSize*7,0,tileSize,tileSize});
    valuesDown.emplace_back(SDL_Rect{tileSize*8,0,tileSize,tileSize});
    animations["moveDown"] = valuesDown;

  /*  std::string dir = "../resources/entitySheet_1.png"; // .c_str();
    char* dirChar = const_cast<char *>(dir.c_str());
    sprite = Sprite(dirChar, renderer, animations);
    sprite.setState(key);
*/
    position.x = map.spawnPoint.x;
    position.y = map.spawnPoint.y;
    position.w = map.scl*2;
    position.h = map.scl*2;

    /*offset.x = map.scl/5;
    offset.y = map.scl/5;
    offset.w = -map.scl/5*2;
    offset.h = -map.scl/5*2;*/


}

void Pacman::update(double dt, Screen &screen) {
    move(dt, screen);
    Entity::update(dt, screen);
}

void Pacman::updateVelocity() {
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

void Pacman::toCheckEveryStep() {
    checkPelletCollision();
}

void Pacman::ai() {

}



