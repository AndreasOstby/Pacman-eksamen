#include <iostream>
#include <SDL.h>
#include "Screen.h"
#include "GameManager.h"

int main() {
    GameManager game;
    game.setup();
    game.run();

}