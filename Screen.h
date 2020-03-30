//
// Created by Baste Angelfoss on 24/03/2020.
//

#ifndef PACMAN_EKSAMEN_SCREEN_H
#define PACMAN_EKSAMEN_SCREEN_H

#include <SDL.h>

class Screen {
public:
    Screen ();
    ~Screen();
    bool init (const char* title, int width, int height);
    void handleEvents();
    void render();
    SDL_Window *window;
    SDL_Renderer *renderer;
    void draw(SDL_Texture *texture, SDL_Rect *coord);
    bool gameOver = false;
    int x = 0;
    int y = 0;
    const Uint8 *keys;
    int numKeys;
};


#endif //PACMAN_EKSAMEN_SCREEN_H
