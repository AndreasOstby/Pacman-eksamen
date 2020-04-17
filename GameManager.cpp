//
// Created by Baste Angelfoss on 30/03/2020.
//
#include "GameManager.h"
#include "NpcController.h"
#include "Blinky.h"


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

                case '.':
                    row.emplace_back(std::make_unique<Pellet>(indexX*map.scl,indexY*map.scl, map.scl));
                    //std::cout << "FPS: " << 123 << ", deltaTime " << 123 << std::endl;
                    break;

                case '*':
                    row.emplace_back(std::make_unique<PowerPellet>(indexX*map.scl,indexY*map.scl, map.scl));
                    break;

                case 'o':
                    map.spawnPoint.x = indexX*map.scl;
                    map.spawnPoint.y = indexY*map.scl;
                    row.emplace_back(nullptr);
                    break;

                case 'c':
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
        map.tileset.emplace_back(std::move(row));

    }

    //flips the tileset so it is in the right direction

   /* for (int x = 0; x < map.tileset.size(); ++x) {
        std::vector<std::unique_ptr<Entity>> col;
        for (int y = 0; y < map.tileset[x].size(); ++y) {
            col.emplace_back(std::move(tileset[x][y]));
        }
        map.tileset.emplace_back(std::move(col));
    }*/

    mapFile.close();
    return true;
}

void GameManager::update() {
    for (int i = 0; i<players.size(); i++){
        players[i]->move(screen.keys);
        players[i]->character->update(frameDuration, screen);
    }
}


void GameManager::run() {
    std::unique_ptr<Controller> player = std::make_unique<PlayerController>(
            SDL_SCANCODE_W,SDL_SCANCODE_S,SDL_SCANCODE_A,SDL_SCANCODE_D
            );
    auto character = std::make_shared<Pacman>(map);
    player->setCharacter(character);
    players.emplace_back(std::move(player));
    map.pacman.push_back(character);


    std::unique_ptr<Controller> npc = std::make_unique<NpcController>();
    npc->setCharacter(std::make_shared<Blinky>(map));
    players.emplace_back(std::move(npc));


    currentFrame = std::chrono::high_resolution_clock::now();
    while(!screen.gameOver){
        screen.handleEvents();
        update();
        render();
        getTime();

    }

}

void GameManager::render() {

    for (int x = 0; x < map.tileset.size(); ++x) {
        for (int y = 0; y < map.tileset[x].size(); ++y) {
        if(map.tileset[x][y] != nullptr && !map.tileset[x][y]->isDead)
            map.tileset[x][y]->render(screen);
           // map.tileset[x][y]->update(1,screen);

        }
    }


    for (int i = 0; i<players.size(); i++) {
        if (!players[i]->character->isDead)
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
            //SDL_RenderFillRect(screen.renderer, &rect);
        }
    }
    screen.render();
    screen.clear();
}

void  GameManager::getTime() {
    using std::chrono::high_resolution_clock;
    using namespace std::chrono_literals;
    //auto lastFrame = currentFrame;

    auto timeSpan = std::chrono::duration_cast<std::chrono::microseconds> (high_resolution_clock::now() - currentFrame);
    int millisPerFrame = (1/framerate)*1000;
    auto toSleepFor = std::chrono::milliseconds(millisPerFrame)-timeSpan;
    if (toSleepFor.count() > 0) {
        std::this_thread::sleep_for(toSleepFor);
        frameDuration = 1;
    } else {
        frameDuration = (timeSpan.count()/1000)/millisPerFrame;
    }
    std::cout << "FPS: " << toSleepFor.count()/1000 << ", deltaTime " << frameDuration << std::endl;
    currentFrame = high_resolution_clock::now();
    //std::this_thread::sleep_for(std::chrono::milliseconds(100));


}

