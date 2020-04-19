//
// Created by Andreas Østby on 15/04/2020.
//

#include "Ghost.h"

Ghost::Ghost(Map &newMap): Character(newMap) {
    spriteSheet = "entities";

    position.x = map.cage->getPosition().x + floor(map.cage->getPosition().w/2);
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

    std::vector<SDL_Rect> values;
    values.emplace_back(SDL_Rect{0,tileSize*6, tileSize,tileSize});
    animations["EatenRight"] = values;

    std::vector<SDL_Rect> dvalues;
    dvalues.emplace_back(SDL_Rect{tileSize*2,tileSize*6, tileSize,tileSize});
    animations["EatenDown"] = dvalues;

    std::vector<SDL_Rect> lvalues;
    lvalues.emplace_back(SDL_Rect{tileSize*4,tileSize*6, tileSize,tileSize});
    animations["EatenLeft"] = values;

    std::vector<SDL_Rect> uvalues;
    uvalues.emplace_back(SDL_Rect{tileSize*6,tileSize*6, tileSize,tileSize});
    animations["EatenUp"] = uvalues;

}

void Ghost::update(double dt, Screen &screen) {
    move(dt, screen);
    Entity::update(dt,screen);
    if(aiState == "Frightened" && cooldown <= 0){
        setAiState("Chasing");
    }
}

void Ghost::updateVelocity() {
    Character::updateVelocity();
    if(aiState == "Frightened"){
        state = aiState;
    }
    else if (aiState == "Eaten"){
        if (velocity.x > 0) {
            state = "EatenRight";
        }
        else if (velocity.x < 0) {
            state = "EatenLeft";
        }
        else if (velocity.y > 0) {
            state = "EatenDown";
        }
        else if (velocity.y < 0) {
            state = "EatenUp";
        }
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
        if(pac->isCollision(*this, {0,0}) && !isDead) {
            if(aiState == "Frightened" || aiState == "Eaten") {
                kill();

            }
            else if (!pac->isDead)
            {
                pac->kill();
            }
        }

    }

}

void Ghost::kill() {
    setAiState("Eaten");
    speed = initSpeed*3;
}

void Ghost::ai() {

    if (aiState == "Chasing") {
        aiChase();
    } else if (aiState == "Frightened" ) {
        std::random_device rd;
        std::mt19937 mt(rd());
        std::uniform_int_distribution<int>dist (0,3);
        int random = dist(mt);
        SDL_Point vel{
                0,1
        };

        if(random == 1){
            vel.x = 1;
            vel.y = 0;
        }

        if(random == 2){
            vel.x = 0;
            vel.y = -1;
        }

        if(random == 3){
            vel.x = -1;
            vel.y = 0;
        }

        Rect rect = position;
        rect.x += vel.x*map.scl;
        rect.y += vel.y*map.scl;
        pathfind(rect);


    }else if (aiState == "Eaten"){
        pathfind(map.cage->getPosition());
        if (position.x-map.scl/2 <= map.cage->getPosition().x &&
            position.x+map.scl/2 >= map.cage->getPosition().x &&
            position.y-map.scl/2 <= map.cage->getPosition().y-map.scl &&
            position.y +map.scl/2 >= map.cage->getPosition().x) {
            setAiState("Chasing");
            speed = initSpeed;
        }
    }

}
