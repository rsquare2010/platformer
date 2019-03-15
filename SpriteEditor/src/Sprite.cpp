//
// Created by Rahul Ravindran on 2019-03-14.
//

#include "sprite.h"

Sprite::Sprite(int width, int height, int x, int y, int number) {
    this->width = width;
    this->height = height;
    this->xPos = x;
    this->yPos = y;
    this->count = number;
    cout<<"Everything is fine till here";
}

Sprite::~Sprite() {
    SDL_DestroyTexture(texture);
}

void Sprite::init(SDL_Renderer* ren) {

    SDL_Surface* surface = (SDL_Surface *) ResourceManager::getInstance()->getValue("Sprite");
    if(surface == NULL) {
        cout<<"Sprite was not loaded";
    } else {
        texture = SDL_CreateTextureFromSurface(ren, surface);
    }
    SDL_FreeSurface(surface);
    surface = NULL;
}

void Sprite::update(int frame) {
    if(currentFrame > count ) {
        currentFrame = 0;
    }

    Src.x = xPos + (currentFrame * width);
    Src.y = yPos;
    Src.w = width;
    Src.h = height;

    currentFrame++;

    Dest.x = 0;
    Dest.y = 0;
    Dest.w = width;
    Dest.h = height;
}

void Sprite::render(SDL_Renderer* ren){
    SDL_RenderCopy(ren, texture, &Src, &Dest);
}