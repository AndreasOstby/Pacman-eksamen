//
// Created by Baste Angelfoss on 30/03/2020.
//

#ifndef PACMAN_EKSAMEN_NPCCONTROLLER_H
#define PACMAN_EKSAMEN_NPCCONTROLLER_H
#include "Controller.h"


class NpcController: public Controller {

public:
    NpcController();
    void setCharacter(std::shared_ptr<Character> c) override;



    void move(const Uint8 *keys) override;
};


#endif //PACMAN_EKSAMEN_NPCCONTROLLER_H
