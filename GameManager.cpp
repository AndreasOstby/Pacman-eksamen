//
// Created by Baste Angelfoss on 30/03/2020.
//

#include "GameManager.h"
#include "Screen.h"
#include "PlayerController.h"

void GameManager::setup() {
    screen.init("Game Window", 600, 600);
    players.emplace_back(std::make_unique<PlayerController>(0,0,0,0));
}

void GameManager::setMap() {

}

void GameManager::update() {

    while(!screen.gameOver){
        screen.handleEvents();
        screen.render();
    }

}
