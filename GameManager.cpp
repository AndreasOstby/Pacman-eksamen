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

}

void GameManager::setMap() {

}

void GameManager::update() {
    for (int i = 0; i<players.size(); i++){
        players[i]->move(screen.keys);
    }
}


void GameManager::run() {
    std::unique_ptr<Controller> player = std::make_unique<PlayerController>(
            SDL_SCANCODE_W,SDL_SCANCODE_S,SDL_SCANCODE_A,SDL_SCANCODE_D
            );
    std::unique_ptr<Character> p = std::make_unique<Pacman>();
    player->setCharacter(p);
    players.push_back(std::move(player));

    while(!screen.gameOver){
        screen.handleEvents();
        update();
        render();

    }

}

void GameManager::render() {
    for (int i = 0; i<players.size(); i++) {
        players[i]->character->render(screen.renderer);
    }
    screen.render();

}

