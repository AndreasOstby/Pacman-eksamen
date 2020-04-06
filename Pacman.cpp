//
// Created by Baste Angelfoss on 02/04/2020.
//

#include <vector>
#include "Pacman.h"



Pacman::Pacman(): Character() {



    std::string key = "moveLeft";

    std::vector<SDL_Rect> values;
    values.emplace_back(SDL_Rect{0,0,16,16});
    values.emplace_back(SDL_Rect{16,0,16,16});
    animations [key] = values;
    std::string dir = "../resources/entitySheet.png"; // .c_str();
    char* dirChar = const_cast<char *>(dir.c_str());
    sprite = Sprite(dirChar, animations);



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

void Pacman::render(SDL_Renderer *renderer) {
    std::cout << "asd" << std::endl;
}
