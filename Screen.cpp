//
// Created by Baste Angelfoss on 24/03/2020.
//

#include "Screen.h"
#include "Sprite.h"
#include <SDL.h>
#include <iostream>

Screen::Screen() {
}

bool Screen::init(const char *title, int width, int height) {
    if (SDL_Init(SDL_INIT_VIDEO) != 0) {
        return true;
    }

    window = SDL_CreateWindow(title, SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, width, height,
                              SDL_WINDOW_SHOWN | SDL_WINDOW_OPENGL);
    if (window == nullptr) {
        return false;
    }
    renderer = SDL_CreateRenderer(window, -1, 0);
    if (renderer == nullptr) {
        return false;
    }
    SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
    keys = SDL_GetKeyboardState(&numKeys);

    return true;
}

void Screen::handleEvents() {
    SDL_PumpEvents();
    if (keys[SDL_SCANCODE_ESCAPE] != 0){
        gameOver = true;
    }
    if (SDL_HasEvent(SDL_QUIT)){
        gameOver = true;
    }

}

void Screen::render() {
    SDL_RenderPresent(renderer);

}

Screen::~Screen() {
    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    SDL_Quit();
}

void Screen::draw(std::string& spriteSheet, SDL_Rect *coord, SDL_Rect *crop) {

    SDL_RenderCopy(renderer, spritesLoaded[spriteSheet], crop, coord);


}

void Screen::clear() {
    SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
    SDL_RenderClear(renderer);
}

void Screen::loadSprite(std::string dir, std::string name) {
    SDL_Surface* sur = IMG_Load(dir.c_str());
    if (sur == nullptr) {
        std::cout << "no image" << std::endl;
    }

    spritesLoaded[name] = SDL_CreateTextureFromSurface(renderer, sur);

    SDL_FreeSurface(sur);
}

