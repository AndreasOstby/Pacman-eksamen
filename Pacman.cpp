//
// Created by Baste Angelfoss on 02/04/2020.
//

#include <vector>
#include "Pacman.h"
#include "Screen.h"
#include "Wall.h"


Pacman::Pacman(std::vector <std::vector<std::unique_ptr<Entity>>>& newMap): Character(newMap) {

    spriteSheet = "entities";

    std::vector<SDL_Rect> valuesRight;
    int xOffset = 0;
    valuesRight.emplace_back(SDL_Rect{0 + xOffset,0,32-xOffset-1,32-xOffset});
    valuesRight.emplace_back(SDL_Rect{32 + xOffset,0,32-xOffset-1,32-xOffset});
    animations["moveRight"] = valuesRight;

    state = "moveRight";

    std::vector<SDL_Rect> valuesLeft;
    valuesLeft.emplace_back(SDL_Rect{32*4 + xOffset,0,32-xOffset-1,32-xOffset});
    valuesLeft.emplace_back(SDL_Rect{32*3 + xOffset,0,32-xOffset-1,32-xOffset});
    animations["moveLeft"] = valuesLeft;

    std::vector<SDL_Rect> valuesUp;
    valuesUp.emplace_back(SDL_Rect{32*5 + xOffset,0,32-xOffset-1,32-xOffset});
    valuesUp.emplace_back(SDL_Rect{32*6 + xOffset,0,32-xOffset-1,32-xOffset});
    animations["moveUp"] = valuesUp;

    std::vector<SDL_Rect> valuesDown;
    valuesDown.emplace_back(SDL_Rect{32*7 + xOffset,0,32-xOffset-1,32-xOffset});
    valuesDown.emplace_back(SDL_Rect{32*8 + xOffset,0,32-xOffset-1,32-xOffset});
    animations["moveDown"] = valuesDown;

  /*  std::string dir = "../resources/entitySheet_1.png"; // .c_str();
    char* dirChar = const_cast<char *>(dir.c_str());
    sprite = Sprite(dirChar, renderer, animations);
    sprite.setState(key);
*/
    position.x = 40;
    position.y = 40;
    position.w = 40;
    position.h = 40;


}

void Pacman::move(long dt) {
    if(velocity.x == 0 && velocity.y ==0){
        updateVelocity();
        return;
    }
    double distanceLeft = dt*speed;
    //std::cout << "x: " << newvel << "  y:" << newVelocity.y << std::endl;
    while (distanceLeft > 0){
        if (velocity.x != 0) {
            calculateMove(position.x, velocity.x, distanceLeft);
        } else if (velocity.y != 0) {
            calculateMove(position.y, velocity.y, distanceLeft);
        }
    }
}

void Pacman::calculateMove(int &pos, int &vel, double &distanceLeft) {
    double diff = (vel*(20*2)-(pos%(20*2)))%(20*2);

    /*std::cout << "pos: " << pos << std::endl;
    std::cout << "velocity: " << vel << std::endl;
    std::cout << "diffX: " << diff << std::endl;
    std::cout << "mLeft: " << distanceLeft << std::endl;*/

    if(distanceLeft >= abs(diff) && diff != 0){
        pos+=diff;
        atIntersection(distanceLeft);
        updateVelocity();
        distanceLeft -= abs(diff);

        //std::cout << "newVelocity: " << distanceLeft << std::endl;
    } else {
        pos += distanceLeft*vel;
        distanceLeft = 0;
    }
}

void Pacman::update(long dt) {
    move(dt);
    Entity::update(dt);
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

void Pacman::atIntersection(double &distanceLeft) {

    /* std::cout<<mapX<<"mapX"<<std::endl;
    std::cout<<mapY<<"mapY"<<std::endl;
    std::cout<<map.size()<<"SizeX"<<std::endl;
    std::cout<<map[mapX].size()<<"SizeY"<<std::endl;
    */
    for (int x = 0; x < 2; ++x)
    {
        for (int y = 0; y < 2; ++y) {

            int mapX = floor(position.x/20)+velocity.x*2+x;
            int mapY = floor(position.y/20) + velocity.y*2+y;
            if(mapX >= map.size() || mapY >= map[mapX].size() || mapX < 0 || mapY < 0){
                continue;
            }


            if (map[mapX][mapY] != nullptr) {
                if (dynamic_cast<Wall *>(map[mapX][mapY].get())) {
                    newVelocity.x = 0;
                    newVelocity.y = 0;
                    distanceLeft = 0;
                }
            }
        }
    }


}



