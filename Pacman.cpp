//
// Created by Baste Angelfoss on 02/04/2020.
//

#include <vector>
#include "Pacman.h"
#include "Screen.h"
#include "Wall.h"


Pacman::Pacman(std::vector <std::vector<std::unique_ptr<Entity>>>& newMap, int &sscl): Character(newMap), scl(sscl) {

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
    position.x = scl*2;
    position.y = scl*2;
    position.w = scl*2;
    position.h = scl*2;


}

void Pacman::move(long dt, Screen &screen) {
    if(velocity.x == 0 && velocity.y ==0){
        updateVelocity();
        return;
    }
    double distanceLeft = dt*speed;
    //std::cout << "x: " << newvel << "  y:" << newVelocity.y << std::endl;
    while (distanceLeft > 0){
        if (velocity.x != 0) {
            calculateMove(position.x, velocity.x, distanceLeft, screen);
        } else if (velocity.y != 0) {
            calculateMove(position.y, velocity.y, distanceLeft, screen);
        }
    }
}

void Pacman::calculateMove(int &pos, int &vel, double &distanceLeft, Screen &screen) {
    double diff = (vel*(scl)-(pos%(scl)))%(scl);

    /*std::cout << "pos: " << pos << std::endl;
    std::cout << "velocity: " << vel << std::endl;
    std::cout << "diffX: " << diff << std::endl;
    std::cout << "mLeft: " << distanceLeft << std::endl;*/

    if(distanceLeft >= abs(diff) && diff != 0){
        pos+=diff;
        atIntersection(distanceLeft, screen);
        //updateVelocity();
        distanceLeft -= abs(diff);

        //std::cout << "newVelocity: " << distanceLeft << std::endl;
    } else {
        pos += distanceLeft*vel;
        distanceLeft = 0;
    }
}

void Pacman::atIntersection(double &distanceLeft, Screen &screen) {

    /* std::cout<<mapX<<"mapX"<<std::endl;
    std::cout<<mapY<<"mapY"<<std::endl;
    std::cout<<map.size()<<"SizeX"<<std::endl;
    std::cout<<map[mapX].size()<<"SizeY"<<std::endl;
    */

    if (!checkWallCollision(newVelocity, screen)) {
        updateVelocity();
    }
    if (checkWallCollision(velocity, screen)) {
        newVelocity.x = 0;
        newVelocity.y = 0;
        distanceLeft = 0;
        updateVelocity();
    }

}

bool Pacman::checkWallCollision(SDL_Point& vel, Screen &screen) {
    for (int x = 0; x < 1 + abs(vel.y); ++x) {
        for (int y = 0; y < 1 + abs(vel.x); ++y) {

            int mapX = floor(position.x/scl) + vel.x*2+x + std::max(vel.x*-1, 0);
            int mapY = floor(position.y/scl) + vel.y*2+y + std::max(vel.y*-1, 0);


            SDL_Rect rect;
            rect.x = mapX*scl;
            rect.y = mapY*scl;
            rect.w = scl;
            rect.h = scl;

            SDL_SetRenderDrawColor(screen.renderer, 255, 50, 50, 255);
            SDL_RenderFillRect(screen.renderer, &rect);

            if(mapX >= map.size() || mapY >= map[mapX].size() || mapX < 0 || mapY < 0){
                continue;
            }


            if (map[mapX][mapY] != nullptr) {
                if (dynamic_cast<Wall *>(map[mapX][mapY].get())) {
                    return true;
                }
            }
        }
    }
    return false;
}



void Pacman::update(long dt, Screen &screen) {
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

