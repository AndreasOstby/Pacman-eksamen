//
// Created by Baste Angelfoss on 30/03/2020.
//

#ifndef PACMAN_EKSAMEN_ENTITY_H
#define PACMAN_EKSAMEN_ENTITY_H

#include "Sprite.h"
#include "Screen.h"


class Character;
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
    bool isColliding(Character character);
    virtual void action(Character character);
    virtual void update(long dt);
    Sprite sprite;
    void render(Screen &screen);
    virtual ~Entity(){}
};


#endif //PACMAN_EKSAMEN_ENTITY_H
