//
// Created by Rahul Ravindran on 2019-03-07.
//
#include <SDL.h>
#ifndef LAB5_PLATFORMER_BACKGROUND1_H
#define LAB5_PLATFORMER_BACKGROUND1_H

class Background{
public:

    Background();
    ~Background();

    void init(int x, int y, SDL_Renderer* ren);
    void update();
    void render(int x, int y, SDL_Renderer* ren);


private:
    int xPos, yPos;
    int width, height;
    int scrollingOffset = 0;
//    unsigned int currentFrame{0};
//    unsigned int LastFrame{7};
    // An SDL Surface contains pixel data to draw an image
    SDL_Surface *spriteSheet;
    SDL_Surface *spriteSheet2;
    SDL_Surface *spriteSheet3;
    SDL_Surface *spriteSheet4;
    SDL_Surface *spriteSheet5;


    SDL_Texture *texture;
    SDL_Texture *texture2;
    SDL_Texture *texture3;
    SDL_Texture *texture4;
    SDL_Texture *texture5;

//    SDL_Rect Src;
    SDL_Rect Dest;
};

#endif //LAB5_PLATFORMER_BACKGROUND1_H
