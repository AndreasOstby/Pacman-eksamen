//
// Created by Baste Angelfoss on 12/04/2020.
//

#include "Wall.h"

Wall::Wall(int x, int y, int scl) {
    spriteSheet = "wall";

    int tileSize = 8;
    std::vector<SDL_Rect> u;
    u.emplace_back(SDL_Rect{tileSize*3,tileSize*2,8,8});
    animations["u"] = u;

    std::vector<SDL_Rect> ur;
    ur.emplace_back(SDL_Rect{0,tileSize*2,8,8});
    animations["ur"] = ur;

    std::vector<SDL_Rect> urd;
    urd.emplace_back(SDL_Rect{0,tileSize,8,8});
    animations["urd"] = urd;

    std::vector<SDL_Rect> urdl;
    urdl.emplace_back(SDL_Rect{tileSize,tileSize,8,8});
    animations["urdl"] = urdl;

    std::vector<SDL_Rect> udl;
    udl.emplace_back(SDL_Rect{tileSize*2,tileSize,8,8});
    animations["udl"] = udl;

    std::vector<SDL_Rect> ud;
    ud.emplace_back(SDL_Rect{tileSize*3,tileSize,8,8});
    animations["ud"] = ud;

    std::vector<SDL_Rect> ul;
    ul.emplace_back(SDL_Rect{tileSize*2,tileSize*2,8,8});
    animations["ul"] = ul;

    std::vector<SDL_Rect> rd;
    rd.emplace_back(SDL_Rect{0,0,8,8});
    animations["rd"] = rd;

    std::vector<SDL_Rect> rl;
    rd.emplace_back(SDL_Rect{tileSize*1,tileSize*3,8,8});
    animations["rl"] = rl;//

    std::vector<SDL_Rect> url;
    url.emplace_back(SDL_Rect{0,tileSize,8,8});
    animations["url"] = url;//

    state = "u";
    setPosition(x, y, scl, scl);

    isSolid = true;
}

void Wall::update(double dt, Screen &screen) {

}

