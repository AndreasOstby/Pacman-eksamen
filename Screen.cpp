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
        return true;
    }
    renderer = SDL_CreateRenderer(window, -1, 0);
    if (renderer == nullptr) {
        return true;
    }
    SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
    keys = SDL_GetKeyboardState(&numKeys);

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
    Sprite sprite("../resources/entitySheet.png");
    sprite.render(renderer);
    SDL_RenderPresent(renderer);
    SDL_RenderClear(renderer);
}

Screen::~Screen() {
    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    SDL_Quit();
}

void Screen::draw(SDL_Texture *texture, SDL_Rect *coord ) {

    SDL_RenderCopy(renderer, texture, nullptr, coord);


}

