//
// Created by Baste Angelfoss on 24/03/2020.
//

#ifndef PACMAN_EKSAMEN_SCREEN_H
#define PACMAN_EKSAMEN_SCREEN_H

#include <SDL.h>
#include <map>
#include <iostream>

class Screen {
public:
    Screen ();
    ~Screen();
    std::map<std::string, SDL_Texture*> spritesLoaded;
    void loadSprite(std::string dir, std::string name);
    bool init (const char* title, int width, int height);
    void handleEvents();
    void render();
    SDL_Window *window;
    SDL_Renderer *renderer;
    void draw(std::string& spriteSheet, SDL_Rect *coord, SDL_Rect *crop);
    bool gameOver = false;
    int x = 0;
    int y = 0;
    const Uint8 *keys;
    int numKeys;
    void clear();
};


#endif //PACMAN_EKSAMEN_SCREEN_H
