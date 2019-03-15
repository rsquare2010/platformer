//
// Created by Rahul Ravindran on 2019-03-14.
//

#ifndef PLATFORMER_SUNDAYS_ARE_FUNDAYS_SDLGRAPHICSPROGRAM_H
#define PLATFORMER_SUNDAYS_ARE_FUNDAYS_SDLGRAPHICSPROGRAM_H


#if defined(LINUX) || defined(MINGW)
#include <SDL2/SDL.h>
#else
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


/**
 * This class sets up a full graphics program.
 */
class SDLGraphicsProgram{
public:


    /**
     * This is a constructor.
     * @param w the width.
     * @param h the height.
     */
    SDLGraphicsProgram(int w, int h);
    /**
     * This is the destructor.
     */
    ~SDLGraphicsProgram();
    // Per frame update

    /**
     * This updates the frame.
     */
    void update();

    /**
     *  Renders shapes to the screen.
     */
    void render();

    /**
     * loop that runs forever
     */
    void loop();


    /**
     * Get Pointer to Window
     * @return Get Pointer to Window
     */
    SDL_Window* getSDLWindow();



    /**
     * Get Pointer to Renderer
     * @return Get Pointer to Renderer
     */
    SDL_Renderer* getSDLRenderer();

private:
    // Screen dimension constants
    int screenHeight;
    int screenWidth;
    // The window we'll be rendering to
    SDL_Window* gWindow ;
    // SDL Renderer
    int animationStartTick = 0;
    SDL_Renderer* gRenderer = NULL;
    Sprite* sprite;
};


#endif //PLATFORMER_SUNDAYS_ARE_FUNDAYS_SDLGRAPHICSPROGRAM_H
