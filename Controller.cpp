//
// Created by Baste Angelfoss on 30/03/2020.
//

#include "Controller.h"

void Controller::setCharacter(std::shared_ptr<Character> c) {
    character = std::move(c);

}
