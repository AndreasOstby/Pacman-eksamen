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
        //x++;
    }
    if (keys[left] != 0){
        //x--;
    }
    if (keys[down] != 0){
        //y++;
    }
    if (keys[up] != 0){
        //y--;
    }
}

