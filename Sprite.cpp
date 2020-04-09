//
// Created by Baste Angelfoss on 30/03/2020.
//

#include "Sprite.h"

#include <utility>

Sprite::Sprite(char *dir, SDL_Renderer *renderer, std::map<std::string, std::vector<SDL_Rect>> anim): animations(std::move(anim)) {
    setSprite(dir, renderer);
    //animations = std::move(anim);
}

void Sprite::render(SDL_Renderer *renderer, SDL_Rect *position) {
    //std::cout << "x: " << animations[state][index].x << std::endl;
    SDL_Rect rect{0,0,16,16};
    SDL_RenderCopy(renderer, image, &animations[state][index] , position);

}

Sprite::~Sprite() {


}

void Sprite::setSprite(char *dir, SDL_Renderer *renderer) {
    SDL_Surface* sur = IMG_Load(dir);
    if (sur == nullptr) {
        std::cout << "no image" << std::endl;

    }
    image = SDL_CreateTextureFromSurface(renderer, sur);

    SDL_FreeSurface(sur);

}

void Sprite::update() {
    index++;
    index %= animations[state].size();
}

void Sprite::setState(std::string newState) {
    state = std::move(newState);
}

Sprite::Sprite() {

}
