//
// Created by Baste Angelfoss on 02/04/2020.
//

#include <vector>
#include "Pacman.h"



Pacman::Pacman(): Character(), Entity() {



    std::string key = "moveLeft";

    std::vector<SDL_Rect> values;
    values.emplace_back(SDL_Rect{0,0,16,16});
    values.emplace_back(SDL_Rect{16,0,16,16});
    animations [key] = values;
    sprite =  Sprite("../resources/entitySheet.png", animations);



}

void Pacman::move(int dt) {
    int mLeft = dt*speed;
    while (mLeft > 0){
        int diffX = (velocity.x*(scl*2)-position.x)%(scl*2);
        if(mLeft >= abs(diffX)){
            position.x+=diffX;
            velocity = newVelocity;
            mLeft -= abs(diffX);
        } else {
            position.x += mLeft*velocity.x;
            break;
        }
    }
    sprite.render()
}
