//
// Created by Baste Angelfoss on 30/03/2020.
//

#include "Controller.h"

void Controller::setCharacter(std::unique_ptr<Character> c) {
    character = std::move(c);


}
