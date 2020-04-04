//
// Created by Baste Angelfoss on 30/03/2020.
//

#ifndef PACMAN_EKSAMEN_SPRITE_H
#define PACMAN_EKSAMEN_SPRITE_H

#include <iostream>
#include <SDL.h>
#include <SDL_image.h>
#include <map>
#include "Screen.h"



class Sprite {

private:
    SDL_Surface *image;
    std::map<std::string, std::vector<SDL_Rect>> animations;
    int index = 0;
    std::string state = "default";

public:
    explicit Sprite(char *dir, std::map<std::string, std::vector<SDL_Rect>> &anim);
    void render(SDL_Renderer *renderer, SDL_Rect *position);

    ~Sprite();
    void setSprite(char* dir);
    void update();
    void setState(std::string newState);

};


#endif //PACMAN_EKSAMEN_SPRITE_H
