//
// Created by Baste Angelfoss on 24/03/2020.
//

#include "Screen.h"
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

}

void Screen::handleEvents() {
    const Uint8 *keys;
    int numKeys;
    keys = SDL_GetKeyboardState(&numKeys);
    SDL_PumpEvents();
    if (keys[SDL_SCANCODE_ESCAPE] != 0){
        gameOver = true;
    }
    if (SDL_HasEvent(SDL_QUIT)){
        gameOver = true;
    }
    if (keys[SDL_SCANCODE_D] != 0){
        x++;
    }
    if (keys[SDL_SCANCODE_A] != 0){
        x--;
    }
    if (keys[SDL_SCANCODE_S] != 0){
        y++;
    }
    if (keys[SDL_SCANCODE_W] != 0){
        y--;
    }
}

void Screen::render() {
    draw();
    SDL_RenderPresent(renderer);
    SDL_RenderClear(renderer);
}

Screen::~Screen() {
    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    SDL_Quit();
}

void Screen::draw() {
    SDL_Surface *surface = SDL_LoadBMP("../resources/mario.bmp");
    if (surface == nullptr) {
    }
    SDL_Texture *texture = SDL_CreateTextureFromSurface(renderer, surface);
    SDL_Rect coord;
    coord.x = x;
    coord.y = y;
    coord.w = 40;
    coord.h = 50;
    SDL_FreeSurface(surface);
    SDL_RenderCopy(renderer, texture, nullptr, &coord);

}

