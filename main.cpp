#include <iostream>
#include <SDL.h>
#include "Screen.h"

int main() {
    Screen screen;
    screen.init("Game Window", 600, 600);
    while(!screen.gameOver){
        screen.handleEvents();
        screen.render();
    }

}