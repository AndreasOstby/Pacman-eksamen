//
// Created by Baste Angelfoss on 30/03/2020.
//

#ifndef PACMAN_EKSAMEN_ENTITY_H
#define PACMAN_EKSAMEN_ENTITY_H

#include "Sprite.h"
#include "Screen.h"

class Entity {

protected:
    SDL_Rect position{
        0,0,0,0
    };

    std::map<std::string, std::vector<SDL_Rect>> animations;
    std::string state = "default";
    std::string spriteSheet;
    int frame = 0;

public:
    Entity();
    bool isColliding(Entity &entity);
    virtual void action(Entity &entity);
    virtual void update(long dt, Screen &screen);
    Sprite sprite;
    void render(Screen &screen);
    virtual ~Entity(){}
};


#endif //PACMAN_EKSAMEN_ENTITY_H
