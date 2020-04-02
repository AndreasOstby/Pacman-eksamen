//
// Created by Baste Angelfoss on 02/04/2020.
//

#include <vector>
#include "Pacman.h"



Pacman::Pacman(): Sprite("../resources/entitySheet.png"), Character(), Entity() {
    std::string key = "moveLeft";

    std::vector<SDL_Rect> values;
    animations [key] = values;
}
