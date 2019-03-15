//
// Created by Rahul Ravindran on 2019-03-14.
//

#ifndef PLATFORMER_SUNDAYS_ARE_FUNDAYS_SDLGRAPHICSPROGRAM_H
#define PLATFORMER_SUNDAYS_ARE_FUNDAYS_SDLGRAPHICSPROGRAM_H


#if defined(LINUX) || defined(MINGW)
#include <SDL2/SDL.h>
#else // This works for Mac
#include <SDL.h>
#endif

#include <iostream>
#include <string>
#include <sstream>
#include <fstream>
#include <stdlib.h>
#include <time.h>
#include "ResourceManager.h"
#include "sprite.h"

// This class sets up a full graphics program
class SDLGraphicsProgram{
public:

    // Constructor
    SDLGraphicsProgram(int w, int h);
    // Desctructor
    ~SDLGraphicsProgram();
    // Per frame update
    void update();
    // Renders shapes to the screen
    void render();
    // loop that runs forever
    void loop();
    // Get Pointer to Window
    SDL_Window* getSDLWindow();
    // Get Pointer to Renderer
    SDL_Renderer* getSDLRenderer();

private:
    // Screen dimension constants
    int screenHeight;
    int screenWidth;
    // The window we'll be rendering to
    SDL_Window* gWindow ;
    // SDL Renderer
    SDL_Renderer* gRenderer = NULL;
    Sprite* sprite;
};


#endif //PLATFORMER_SUNDAYS_ARE_FUNDAYS_SDLGRAPHICSPROGRAM_H
