//
// Created by Andreas Østby on 17/04/2020.
//

#include "Blinky.h"



void Blinky::ai() {
    std::shared_ptr<Character> closest;
    double pDistance = 1000;//std::max(map.w, map.h);
    for (int i = 0; i < map.pacman.size(); ++i) {
        double currentDistance = map.pacman[i]->getDistance(position, velocity);
        if(currentDistance < pDistance){
            closest = map.pacman[i];
            pDistance = currentDistance;
        }
    }
    if (aiState == "Chasing") {
        pathfind(closest->getPosition());
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

Blinky::Blinky(Map &newMap) : Ghost(newMap) {
    std::vector<SDL_Rect> valuesRight;
    int tileSize = 32;
    valuesRight.emplace_back(SDL_Rect{0,tileSize*2, tileSize,tileSize});
    valuesRight.emplace_back(SDL_Rect{tileSize,tileSize*2,tileSize,tileSize});
    animations["moveRight"] = valuesRight;

    state = "moveRight";

    std::vector<SDL_Rect> valuesLeft;
    valuesLeft.emplace_back(SDL_Rect{tileSize*4,tileSize*2,tileSize,tileSize});
    valuesLeft.emplace_back(SDL_Rect{tileSize*5,tileSize*2,tileSize,tileSize});
    animations["moveLeft"] = valuesLeft;

    std::vector<SDL_Rect> valuesUp;
    valuesUp.emplace_back(SDL_Rect{tileSize*6,tileSize*2,tileSize,tileSize});
    valuesUp.emplace_back(SDL_Rect{tileSize*7,tileSize*2,tileSize,tileSize});
    animations["moveUp"] = valuesUp;

    std::vector<SDL_Rect> valuesDown;
    valuesDown.emplace_back(SDL_Rect{tileSize*2,tileSize*2,tileSize,tileSize});
    valuesDown.emplace_back(SDL_Rect{tileSize*3,tileSize*2,tileSize,tileSize});
    animations["moveDown"] = valuesDown;
}
