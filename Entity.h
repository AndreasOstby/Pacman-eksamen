//
// Created by Baste Angelfoss on 30/03/2020.
//

#ifndef PACMAN_EKSAMEN_ENTITY_H
#define PACMAN_EKSAMEN_ENTITY_H

#include "Sprite.h"
#include "Screen.h"
#include "Rect.h"
class Character;


class Entity {

protected:
    Rect position{
        0,0,10,10
    };

    Rect offset{
    0,0,0,0
    };
    std::map<std::string, std::vector<SDL_Rect>> animations;

    float frame = 0;

public:
    bool isDead = false;
    bool isSolid = false;
    int cooldown = 0;
    std::string spriteSheet;
    std::string state = "default";

    Entity();
    bool isCollision(Entity& entity, Rect extraOffset);
    virtual void onCollision(Character &character);
    virtual void update(double dt);
    virtual void kill();
    void render(Screen &screen);
    virtual ~Entity(){}
    Rect& getPosition();
    void setPosition(double x, double y, int w, int h);


};
#include "Character.h"

#endif //PACMAN_EKSAMEN_ENTITY_H
