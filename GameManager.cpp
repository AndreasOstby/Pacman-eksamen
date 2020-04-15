//
// Created by Baste Angelfoss on 30/03/2020.
//
#include "GameManager.h"



void GameManager::setup() {
    screen.init("Game Window", 600, 600);
    screen.loadSprite("../resources/entitySheet_1.png", "entities");

    setMap(0);
}

bool GameManager::setMap(int id) {

    std::ifstream mapFile ("../Maps/0.txt");
    if (!mapFile.is_open())
    {
        return false;
    }

    std::vector <std::vector<std::unique_ptr<Entity>>> tileset;

    int indexY = 0;
    std::string line;
    while (std::getline(mapFile, line)) {
        std::vector<std::unique_ptr<Entity>> row;
        int indexX = 0;
        for (char x : line) {

            switch (x) {
                case 'w':
                    row.emplace_back(std::make_unique<Wall>(indexX*map.scl,indexY*map.scl));
                    break;

                case 'p':
                    row.emplace_back(std::make_unique<Pellet>());
                    break;

                case 'P':
                    row.emplace_back(std::make_unique<PowerPellet>());
                    break;

                case 'o': //We want it to leak to the default
                    map.spawnPoint.x = indexX*map.scl;
                    map.spawnPoint.y = indexY*map.scl;
                    row.emplace_back(nullptr);
                    break;

                case 'c': //We want it to leak to the default
                    map.cage.x = indexX*map.scl;
                    map.cage.y = indexY*map.scl;
                    row.emplace_back(nullptr);
                    break;

                default:
                    row.emplace_back(nullptr);

            }
            indexX++;
        }
        indexY++;
        tileset.emplace_back(std::move(row));
    }

    //flips the tileset so it is in the right direction

    for (int x = 0; x < map.tileset.size(); ++x) {
        for (int y = 0; y < map.tileset[x].size(); ++y) {
            map.tileset[y][x] = std::move(tileset[x][y]);
        }
    }

    mapFile.close();
    return true;
}

void GameManager::update() {
    for (int i = 0; i<players.size(); i++){
        players[i]->move(screen.keys);
        players[i]->character->update(1, screen);
    }
}


void GameManager::run() {
    std::unique_ptr<Controller> player = std::make_unique<PlayerController>(
            SDL_SCANCODE_W,SDL_SCANCODE_S,SDL_SCANCODE_A,SDL_SCANCODE_D
            );
    player->setCharacter(std::make_unique<Pacman>(map));
    players.emplace_back(std::move(player));

    while(!screen.gameOver){
        screen.handleEvents();
        update();
        render();
    }

}

void GameManager::render() {

    for (int x = 0; x < map.tileset.size(); ++x) {
        for (int y = 0; y < map.tileset[x].size(); ++y) {
        if(map.tileset[x][y] != nullptr)
            map.tileset[x][y]->render(screen);
        }
    }


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
    screen.clear();
}

std::chrono::milliseconds GameManager::getTime() {
    return std::chrono::duration_cast<std::chrono::milliseconds >(
            std::chrono::system_clock::now().time_since_epoch()
    );
}

