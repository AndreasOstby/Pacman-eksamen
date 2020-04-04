//
// Created by Baste Angelfoss on 30/03/2020.
//

#include "GameManager.h"
#include "Screen.h"
#include "PlayerController.h"
#include "Sprite.h"
#include "Pacman.h"

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
    PlayerController player(
            SDL_SCANCODE_W,SDL_SCANCODE_S,SDL_SCANCODE_A,SDL_SCANCODE_D
            );
    Pacman p();
    player.setCharacter(reinterpret_cast<Character &&>(p));
    players.emplace_back(std::make_unique<PlayerController> (player));

    while(!screen.gameOver){
        screen.handleEvents();
        update();
        screen.render();

    }

}
