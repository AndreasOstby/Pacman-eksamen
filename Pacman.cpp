//
// Created by Baste Angelfoss on 02/04/2020.
//

#include <vector>
#include "Pacman.h"
#include "Screen.h"


Pacman::Pacman(): Character(){

    spriteSheet = "entities";
    std::string key = "moveLeft";

    std::vector<SDL_Rect> values;
    int xOffset = 3;
    values.emplace_back(SDL_Rect{0 + xOffset,0,32-xOffset-1,32-xOffset});
    values.emplace_back(SDL_Rect{32 + xOffset,0,32-xOffset-1,32-xOffset});
    animations[key] = values;

    state = key;
  /*  std::string dir = "../resources/entitySheet_1.png"; // .c_str();
    char* dirChar = const_cast<char *>(dir.c_str());
    sprite = Sprite(dirChar, renderer, animations);
    sprite.setState(key);
*/
    position.x = 100;
    position.y = 100;
    position.w = 100;
    position.h = 100;


}

void Pacman::move(int dt) {
    int mLeft = dt*speed;
    while (mLeft > 0){
        int diffX = (velocity.x*(20*2)-position.x)%(20*2);
        if(mLeft >= abs(diffX)){
            position.x+=diffX;
            velocity = newVelocity;
            mLeft -= abs(diffX);
        } else {
            position.x += mLeft*velocity.x;
            break;
        }
    }
}


