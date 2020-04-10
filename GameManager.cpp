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
        players[i]->character->update(1);
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
    for (int x = 0; x < 600; x += 40) {
        for (int y = 0; y < 600; y += 40) {
            SDL_Rect rect;
            rect.x = x-5;
            rect.y = y-5;
            rect.w = 10;
            rect.h = 10;

            SDL_SetRenderDrawColor(screen.renderer, 50, 50, 50, 255);
            SDL_RenderFillRect(screen.renderer, &rect);
        }
    }
    screen.render();

}

std::chrono::milliseconds GameManager::getTime() {
    return std::chrono::duration_cast<std::chrono::milliseconds >(
            std::chrono::system_clock::now().time_since_epoch()
    );
}

