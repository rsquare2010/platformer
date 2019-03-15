//
// Created by Rahul Ravindran on 2019-03-14.
//

#ifndef PLATFORMER_SUNDAYS_ARE_FUNDAYS_SPRITE_H
#define PLATFORMER_SUNDAYS_ARE_FUNDAYS_SPRITE_H

#include "ResourceManager.h"
class Sprite{
public:

    Sprite(int width, int height, int x, int y, int number);


    ~Sprite();

    void init(SDL_Renderer* ren);


    void update(int frame);

    void render(SDL_Renderer* ren);


private:
    int xPos, yPos;
    int width, height;
    int count;
    unsigned int currentFrame{0};
    unsigned int yFrame{0};
    unsigned int LastFrame{7};
    // An SDL Surface contains pixel data to draw an image
    SDL_Texture* texture;

    SDL_Rect Src;
    SDL_Rect Dest;
};
#endif //PLATFORMER_SUNDAYS_ARE_FUNDAYS_SPRITE_H
