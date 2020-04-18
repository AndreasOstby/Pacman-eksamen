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

    std::vector<SDL_Rect> death;
    death.emplace_back(SDL_Rect{tileSize*0,tileSize*1,tileSize,tileSize});
    death.emplace_back(SDL_Rect{tileSize*1,tileSize*1,tileSize,tileSize});
    death.emplace_back(SDL_Rect{tileSize*2,tileSize*1,tileSize,tileSize});
    death.emplace_back(SDL_Rect{tileSize*3,tileSize*1,tileSize,tileSize});
    death.emplace_back(SDL_Rect{tileSize*4,tileSize*1,tileSize,tileSize});
    death.emplace_back(SDL_Rect{tileSize*5,tileSize*1,tileSize,tileSize});
    death.emplace_back(SDL_Rect{tileSize*6,tileSize*1,tileSize,tileSize});
    death.emplace_back(SDL_Rect{tileSize*7,tileSize*1,tileSize,tileSize});
    death.emplace_back(SDL_Rect{tileSize*8,tileSize*1,tileSize,tileSize});
    death.emplace_back(SDL_Rect{tileSize*9,tileSize*1,tileSize,tileSize});
    animations["death"] = death;

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
    if(!isDead){
        move(dt, screen);
    }
    Entity::update(dt, screen);
    if(frame == 0 && isDead){
        position.x = map.spawnPoint.x;
        position.y = map.spawnPoint.y;
        lives--;
        isDead = false;
        state = "moveUp";
        hasLost = (lives == 0);
    }
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

void Pacman::kill() {
    Entity::kill();
    frame = 0;
    state = "death";
}



