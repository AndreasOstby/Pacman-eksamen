//
// Created by Andreas Østby on 17/04/2020.
//

#ifndef PACMAN_EKSAMEN_CLYDE_H
#define PACMAN_EKSAMEN_CLYDE_H


#include "Ghost.h"

class Clyde : public Ghost {
public:
    explicit Clyde(Map &newMap);
    void aiChase() override;

};



#endif //PACMAN_EKSAMEN_CLYDE_H
