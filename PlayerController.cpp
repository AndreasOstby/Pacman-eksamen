//
// Created by Baste Angelfoss on 30/03/2020.
//

#include "PlayerController.h"
#include "Screen.h"
PlayerController::PlayerController(int keyUp, int keyDown, int keyLeft, int keyRight)
:up(keyUp),down(keyDown), left(keyLeft), right(keyRight) {

}

void PlayerController::move(const Uint8 *keys) {
    if (keys[right] != 0){
        character->setVelocity(1,0);
    }
    if (keys[left] != 0){
        character->setVelocity(-1,0);
    }
    if (keys[down] != 0){
        character->setVelocity(0,1);
    }
    if (keys[up] != 0){
        character->setVelocity(0,-1);
    }
}

