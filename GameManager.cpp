//
// Created by Baste Angelfoss on 30/03/2020.
//

#include "GameManager.h"
#include "Screen.h"
#include "PlayerController.h"
#include "Sprite.h"

void GameManager::setup() {
    screen.init("Game Window", 600, 600);
    players.emplace_back(std::make_unique<PlayerController>(0,0,0,0));
}

void GameManager::setMap() {

}

void GameManager::update() {
    for (int i = 0; i<players.size(); i++){
        players[i]->move(screen.keys);
    }
}

void GameManager::run() {

    while(!screen.gameOver){
        screen.handleEvents();
        update();
        screen.render();

    }

}
