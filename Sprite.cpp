//
// Created by Baste Angelfoss on 30/03/2020.
//

#include "Sprite.h"

Sprite::Sprite(char *dir) {
    image = IMG_Load(dir);
    if (image == nullptr) {
    }
    position.x = 0;
    position.y = 0;
    position.w = 40;
    position.h = 50;
}

void Sprite::render(SDL_Renderer *renderer) {
    SDL_Texture *drawable = SDL_CreateTextureFromSurface(renderer, image);
    SDL_RenderCopy(renderer, drawable, nullptr, &position);




}

Sprite::~Sprite() {
    SDL_FreeSurface(image);

}
