//
// Created by Baste Angelfoss on 30/03/2020.
//

#include "NpcController.h"


NpcController::NpcController() {

}

void NpcController::move(const Uint8 *keys) {

}

void NpcController::setCharacter(std::shared_ptr<Character> c) {
    Controller::setCharacter(c);
    c->isAi = true;

}
