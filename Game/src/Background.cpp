//
// Created by Rahul Ravindran on 2019-03-14.
//
#include "Background.h"

Background::Background() {
}

Background::~Background() {
    SDL_DestroyTexture(texture);
    SDL_DestroyTexture(texture2);
    SDL_DestroyTexture(texture3);
    SDL_DestroyTexture(texture4);
}

void Background::init(int x, int y) {
    xPos = x;
    yPos = y;

    resourceManager = ResourceManager::getInstance();
    texture = (SDL_Texture *) resourceManager->getValue("Background1");
    texture2 = (SDL_Texture *) resourceManager->getValue("Background2");
    texture3 = (SDL_Texture *) resourceManager->getValue("Background3");
    texture4 = (SDL_Texture *) resourceManager->getValue("Background4");
}

void Background::update() {
    Dest.x = 0;
    Dest.y = 0;
    Dest.w = 1280;
    Dest.h = 720;
}

void Background::render(int x, int y, SDL_Renderer* ren) {
    Dest.x = -x * 0.1;
    SDL_RenderCopy(ren, texture, NULL, &Dest);
    SDL_RenderCopy(ren, texture2, NULL, &Dest);
    Dest.x = -x * 0.6;
    SDL_RenderCopy(ren, texture3, NULL, &Dest);
    Dest.x = -x;
    SDL_RenderCopy(ren, texture4, NULL, &Dest);
//        Dest.x = -x + 1280;
    Dest.x = (-x * 0.1) + 1280;
    SDL_RenderCopy(ren, texture, NULL, &Dest);
//        Dest.x = (-x * 0.4) + 1280;
    SDL_RenderCopy(ren, texture2, NULL, &Dest);
    Dest.x = (-x * 0.6) + 1280;
    SDL_RenderCopy(ren, texture3, NULL, &Dest);
    Dest.x = -x + 1280;
    SDL_RenderCopy(ren, texture4, NULL, &Dest);
}
