//
// Created by Rahul Ravindran on 2019-03-14.
//

#ifndef PLATFORMER_SUNDAYS_ARE_FUNDAYS_SPRITE_H
#define PLATFORMER_SUNDAYS_ARE_FUNDAYS_SPRITE_H

#include "ResourceManager.h"
class Sprite{
public:

    Sprite(int width, int height, int x, int y, int number){
        this->width = width;
        this->height = height;
        this->xPos = x;
        this->yPos = y;
        this->count = number;
        cout<<"Everything is fine till here";
    }


    ~Sprite(){
    }

    void init(SDL_Renderer* ren){

        SDL_Surface* surface = (SDL_Surface *) ResourceManager::getInstance()->getValue("Sprite");
        if(surface == NULL) {
            cout<<"Sprite was not loaded";
        } else {
            texture = SDL_CreateTextureFromSurface(ren, surface);
        }

    }


    void update(int frame){
        // The part of the image that we want to render




        // Here I am selecting which frame I want to draw
        // from our sprite sheet. Think of this as just
        // using a mouse to draw a rectangle around the
        // sprite that we want to draw.
//        Src.x = currentFrame * width;
//        Src.y = yFrame * 87;

        if(currentFrame > count ) {
            currentFrame = 0;
        }

        Src.x = xPos + (currentFrame * width);
        Src.y = yPos;
        Src.w = width;
        Src.h = height;

        currentFrame++;


//        if(yFrame % 6 == 0){
//            yFrame = 0;
//            currentFrame=++;
//
//        }
//        if(currentFrame > 3) {
//            yFrame = 0;
//            currentFrame =0;
//        }
//        yFrame++;


        // Where we want the rectangle to be rendered at.
        // This is an actual 'quad' that will draw our
        // source image on top of.
//        int xPosition = (xPos + (frame * 30)) % 1280;
//		if (xPosition > 1280){
//			xPos = 0;
//			xPosition = 0;
//		}
        Dest.x = 0;
        Dest.y = 0;
        Dest.w = width;
        Dest.h = height;
    }

    void render(SDL_Renderer* ren){
        SDL_RenderCopy(ren, texture, &Src, &Dest);
    }


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
