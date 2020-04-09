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
    screen.loadSprite("../resources/entitySheet_1.png", "entities");
}

void GameManager::setMap() {

}

void GameManager::update() {
    for (int i = 0; i<players.size(); i++){
        players[i]->move(screen.keys);
        players[i]->character->update();
    }
}


void GameManager::run() {
    std::unique_ptr<Controller> player = std::make_unique<PlayerController>(
            SDL_SCANCODE_W,SDL_SCANCODE_S,SDL_SCANCODE_A,SDL_SCANCODE_D
            );
    player->setCharacter(std::make_unique<Pacman>());
    players.emplace_back(std::move(player));

    while(!screen.gameOver){
        screen.handleEvents();
        update();
        render();
    }

}

void GameManager::render() {
    screen.clear();
    for (int i = 0; i<players.size(); i++) {
        players[i]->character->render(screen);
    }
    screen.render();

}

