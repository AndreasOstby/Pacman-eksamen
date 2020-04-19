//
// Created by Baste Angelfoss on 30/03/2020.
//
#include "GameManager.h"
#include "NpcController.h"
#include "Blinky.h"
#include "Cage.h"
#include "Inky.h"
#include "Pinky.h"
#include "Clyde.h"


void GameManager::setup() {
    screen.init("Game Window", 600, 800);
    screen.loadSprite("../resources/entitySheet_1.png", "entities");
    screen.loadSprite("../resources/wall.png", "wall");
    screen.loadSprite("../resources/cage.png", "cage");
    screen.loadSprite("../resources/gameover.png", "gameover");
    screen.loadSprite("../resources/NextLevel.png", "nextlevel");

    setMap(0);
}

bool GameManager::setMap(int id) {

    std::stringstream text;
    text<<"../Maps/"<<id<<".txt";

    std::ifstream mapFile (text.str());
    if (!mapFile.is_open())
    {
        return false;
    }

    map.id = id;

    map.tileset.clear();

    int recordX = 0;
    int recordY = 0;

    int indexY = 0;
    std::string line;
    while (std::getline(mapFile, line)) {
        std::vector<std::shared_ptr<Entity>> row;
        int indexX = 0;
        for (char x : line) {

            switch (x) {
                case 'w':
                    row.push_back(std::make_shared<Wall>(indexX*map.scl,indexY*map.scl, map.scl));
                    break;

                case '.':
                    row.emplace_back(std::make_shared<Pellet>(indexX*map.scl,indexY*map.scl, map.scl));
                    //std::cout << "FPS: " << 123 << ", deltaTime " << 123 << std::endl;
                    break;

                case '*':
                    row.emplace_back(std::make_shared<PowerPellet>(indexX*map.scl + map.scl/2,indexY*map.scl + map.scl/2, map.scl));
                    break;

                case 'o':
                    map.spawnPoint.x = indexX*map.scl;
                    map.spawnPoint.y = indexY*map.scl;
                    for (auto & pacman : map.pacman) {
                        pacman->getPosition().x = map.spawnPoint.x;
                        pacman->getPosition().y = map.spawnPoint.y;
                    }
                    row.emplace_back(nullptr);
                    break;

                case 'c':

                    map.cage = std::make_shared<Cage>(indexX*map.scl-(3*map.scl), indexY*map.scl, map.scl*7, map.scl*4);
                    row.push_back(map.cage);
                    break;

                default:
                    row.emplace_back(nullptr);

            }
            indexX++;
            if (indexX > recordX) recordX = indexX;
        }
        indexY++;
        if (indexY > recordY) recordY = indexY;

        map.tileset.emplace_back(std::move(row));

    }

    map.w = recordX;
    map.h = recordY;

    for (auto & ghost : map.ghost) {
        ghost->setPosition(
            map.cage->getPosition().x + floor(map.cage->getPosition().w/2) - map.scl,
            map.cage->getPosition().y + map.scl,
            map.scl*2,
            map.scl*2
            );
    }

    for (auto & pacman : map.pacman) {
        Pacman* p = dynamic_cast<Pacman*>(pacman.get());
        p->lives = 3;
    }


    // Checks neighbor walls to connect the sprites
   for (int y = 0; y < map.tileset.size(); ++y) {
        for (int x = 0; x < map.tileset[y].size(); ++x) {
            Wall* w = dynamic_cast<Wall*>(map.tileset[y][x].get());
            if (w != nullptr) {
                std::stringstream state;

                if (y-1 >= 0 && x < map.tileset[y].size() && x < map.tileset[y-1].size() && dynamic_cast<Wall*>(map.tileset[y-1][x].get()) != nullptr){
                    state << "u";
                }

                if (x+1 < map.tileset[y].size() && dynamic_cast<Wall*>(map.tileset[y][x+1].get()) != nullptr){
                    state << "r";
                }

                if (y+1 < map.tileset.size() && x < map.tileset[y+1].size() && dynamic_cast<Wall*>(map.tileset[y+1][x].get()) != nullptr){
                    state << "d";
                }


                if (x-1 >= 0 && dynamic_cast<Wall*>(map.tileset[y][x-1].get()) != nullptr){
                    state << "l";
                }

                std::string newState = state.str();

                if (newState == "") {
                    newState = "b";
                }

                map.tileset[y][x]->state = newState;
            }
        }
    }

    mapFile.close();

    screen.resize(map.scl*map.w, map.scl*(map.h+2));

    return true;
}

void GameManager::update() {
    map.cage->update(frameDuration);
    map.cage->spawnghost(map);
    for (auto & player : players){
        player->move(screen.keys);
        player->character->update(frameDuration);
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
    auto blinky = std::make_shared<Blinky>(map);
    npc->setCharacter(blinky);
    players.emplace_back(std::move(npc));
    map.ghost.push_back(blinky);

    std::unique_ptr<Controller> inpc = std::make_unique<NpcController>();
    auto inky = std::make_shared<Inky>(map);
    inpc->setCharacter(inky);
    players.emplace_back(std::move(inpc));
    map.ghost.push_back(inky);

    std::unique_ptr<Controller> pnpc = std::make_unique<NpcController>();
    auto pinky = std::make_shared<Pinky>(map);
    pnpc->setCharacter(pinky);
    players.emplace_back(std::move(pnpc));
    map.ghost.push_back(pinky);

    std::unique_ptr<Controller> cnpc = std::make_unique<NpcController>();
    auto clyde = std::make_shared<Clyde>(map);
    cnpc->setCharacter(clyde);
    players.emplace_back(std::move(cnpc));
    map.ghost.push_back(clyde);

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
        }
    }

    bool isGameOver = true;
    for (auto & player : players) {
        player->character->render(screen);
    }

    for (int i = 0; i < map.pacman.size(); ++i) {
        auto* p = dynamic_cast<Pacman*>(map.pacman[i].get());
        for (int j = 0; j < p->lives; ++j) {
            SDL_Rect rect{0,0,32,32};
            SDL_Rect pos{static_cast<int>((map.scl*2)*j + (8*map.scl)*i),static_cast<int>(map.h*map.scl),static_cast<int>(map.scl*2),static_cast<int>(map.scl*2)};
            screen.draw(p->spriteSheet, &pos, &rect);
            isGameOver = false;
        }

    }


    bool isNextLevel = true;
    for (int x = 0; x < map.tileset.size(); ++x) {
        for (int y = 0; y < map.tileset[x].size(); ++y) {
            if(map.tileset[x][y] != nullptr && dynamic_cast<Pellet*>(map.tileset[x][y].get()) != nullptr && !map.tileset[x][y]->isDead)
                isNextLevel = false;
        }
    }
    if (isNextLevel) nextLevel();

    if (isGameOver)gameover();


    screen.render();
    screen.clear();
}

void  GameManager::getTime() {
    using std::chrono::high_resolution_clock;
    using namespace std::chrono_literals;

    auto timeSpan = std::chrono::duration_cast<std::chrono::microseconds> (high_resolution_clock::now() - currentFrame);
    int millisPerFrame = (1.0/framerate)*1000.0;
    auto toSleepFor = std::chrono::milliseconds(millisPerFrame)-timeSpan;
    if (toSleepFor.count() > 0) {
        std::this_thread::sleep_for(toSleepFor);
        frameDuration = 1;
    } else {
        frameDuration = (timeSpan.count()/1000.0)/millisPerFrame;
    }
    currentFrame = high_resolution_clock::now();

}

void GameManager::gameover() {
    using namespace std::chrono_literals;

    SDL_Rect rect{0,0,160,32};
    SDL_Rect pos{static_cast<int>(map.w*map.scl/2-160),static_cast<int>(map.h*map.scl/2 - 32),320,64};
    std::string sprite = "gameover";
    screen.draw(sprite, &pos, &rect);
    screen.render();

    // Bad practise, but low on time
    std::this_thread::sleep_for(3s);

    setMap(0);
    getTime();
}

void GameManager::nextLevel() {
    using namespace std::chrono_literals;

    SDL_Rect rect{0,0,160,32};
    SDL_Rect pos{static_cast<int>(map.w*map.scl/2-160),static_cast<int>(map.h*map.scl/2 - 32),320,64};
    std::string sprite = "nextlevel";
    screen.draw(sprite, &pos, &rect);
    screen.render();

    // Bad practise, but low on time
    std::this_thread::sleep_for(3s);

    if (!setMap(map.id+1)) {
        setMap(0);
    }
    getTime();
}

