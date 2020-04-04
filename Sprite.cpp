//
// Created by Baste Angelfoss on 30/03/2020.
//

#include "Sprite.h"

#include <utility>

Sprite::Sprite(char *dir, std::map<std::string, std::vector<SDL_Rect>> anim): animations(std::move(anim)) {
    setSprite(dir);
    //animations = std::move(anim);
}

void Sprite::render(SDL_Renderer *renderer, SDL_Rect *position) {
    SDL_Texture *drawable = SDL_CreateTextureFromSurface(renderer, image);
    SDL_RenderCopy(renderer, drawable, &animations[state][index] , position);

}

Sprite::~Sprite() {
    SDL_FreeSurface(image);

}

void Sprite::setSprite(char *dir) {
    image = IMG_Load(dir);
    if (image == nullptr) {
    }

}

void Sprite::update() {
    index++;
    index %= animations[state].size();
}

void Sprite::setState(std::string newState) {
    state = std::move(newState);
}
