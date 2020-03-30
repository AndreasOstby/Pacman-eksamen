//
// Created by Baste Angelfoss on 30/03/2020.
//

#include "PlayerController.h"

PlayerController::PlayerController(int keyUp, int keyDown, int keyLeft, int keyRight)
:up(keyUp),down(keyDown), left(keyLeft), right(keyRight) {

}

void PlayerController::move() {
    Controller::move();
}

PlayerController::PlayerController() {

}
