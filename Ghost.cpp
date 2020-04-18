//
// Created by Andreas Østby on 15/04/2020.
//

#include "Ghost.h"

Ghost::Ghost(Map &newMap): Character(newMap) {
    spriteSheet = "entities";

    position.x = map.cage->getPosition().x + floor(map.cage->getPosition().w/2);
    position.y = map.cage->getPosition().y - map.scl*2;
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
    dvalues.emplace_back(SDL_Rect{0,tileSize*8, tileSize,tileSize});
    animations["EatenDown"] = dvalues;

    std::vector<SDL_Rect> lvalues;
    lvalues.emplace_back(SDL_Rect{0,tileSize*10, tileSize,tileSize});
    animations["EatenLeft"] = values;

    std::vector<SDL_Rect> uvalues;
    uvalues.emplace_back(SDL_Rect{0,tileSize*12, tileSize,tileSize});
    animations["EatenUp"] = uvalues;

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
            else
            {
                pac->kill();
            }
        }

    }

}

void Ghost::kill() {
    setAiState("Eaten");
}
