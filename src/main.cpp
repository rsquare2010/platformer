#include <iostream>
#include "SDL.h"
#include "Wall.h"
#include "Ball.h"
#include "Fonts.h"
#include "Mixer.h"
#include "Paddle.h"
#include "Rectangle.h"
#include "State.h"
#include "Collision.h"
#include "ResourceManager.h"
#include <stdio.h>
#include <SDL_ttf.h>
#include <SDL_mixer.h>
#include <vector>
#include "json/json.h"
#include "../include/GridLayover.h"

using namespace std;
using namespace Json;

#define SCR_WDT  800
#define SCR_HGT  500
const int SCR_CEN_X = SCR_WDT/2;
const int SCR_CEN_Y = SCR_HGT/2;
#define FPS 30

void mousePress(SDL_MouseButtonEvent& b);

/**tou
 * This this the main function fo the game. This is function implements the game loop.
 * @param argc int argument.
 * @param argv character argument.
 * @return 0 when it executes perfectly.
 */
int main(int argc, char **argv) {



  SDL_Window *window;
  SDL_Renderer *renderer;
  bool run = true;


  // Create an application window with the following settings:
  window = SDL_CreateWindow(
      "BREAKOUT",                  // window title
      SDL_WINDOWPOS_UNDEFINED,           // initial x position
      SDL_WINDOWPOS_UNDEFINED,           // initial y position
      SCR_WDT,                               // width, in pixels
      SCR_HGT,                               // height, in pixels
      SDL_WINDOW_OPENGL                  // flags - see below
  );
  if (SDL_Init(SDL_INIT_EVERYTHING)!=0) {
    cout << " there is some error initializing everything\n";
    return -1;
  }


  // Create an application window with the following settings:
  window = SDL_CreateWindow(
      "BREAKOUT",                  // window title
      SDL_WINDOWPOS_UNDEFINED,           // initial x position
      SDL_WINDOWPOS_UNDEFINED,           // initial y position
      SCR_WDT,                               // width, in pixels
      SCR_HGT,                               // height, in pixels
      SDL_WINDOW_OPENGL                  // flags - see below
  );

  renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);

  // Check that the window was successfully created
  if (window==NULL) {
    // In the case that the window could not be made...
    printf("Could not create window: %s\n", SDL_GetError());
    return 1;
  }


// Clear the window and make it all red


  Uint32 startTick;
  SDL_Event occur;

  int mouseX, mouseY;
  int mouseGrid;
  Rectangle* selection = new Rectangle(renderer,0, 0,50,50);
  int grid[500/50][800/50] = {};
  bool ismousePressed = false;






  GridLayover* gl = new GridLayover(renderer,SCR_WDT,SCR_HGT);
  vector<Coordinates *> placements;

  while (run) {



    startTick = SDL_GetTicks();
    SDL_PollEvent(&occur);
    SDL_SetRenderDrawColor(renderer, 0, 0, 0, 0);
    SDL_RenderClear(renderer);
    gl->draw();






    if (occur.type==SDL_QUIT) {
      run = false;
    }

    if (occur.type==SDL_KEYDOWN) {
      switch (occur.key.keysym.sym) {

        case SDLK_a:
        case (SDLK_RIGHT):

          break;
        case SDLK_d:
        case (SDLK_LEFT):

          break;
        case SDLK_p:

          break;

        case SDLK_r:

          break;

        case SDLK_m:

          break;

        case SDLK_q:run = false;
          break;



      }
    }




    SDL_GetMouseState(&mouseX, &mouseY);

    mouseGrid = ((SCR_WDT/50)*(mouseY/50))+(mouseX/50);

    //cout<<"mouseX: "<<mouseX/50<<"mouseY: "<<mouseY/50<<endl;


    selection->updateColor(255,255,255,255);
    selection->updateRectangle(gl->getCoordinate(mouseGrid)->getX(), gl->getCoordinate(mouseGrid)->getY(),50,50);
    selection->draw();




      if(occur.type == SDL_MOUSEBUTTONDOWN) {
        cout<<"mouse is pressed!!"<<endl;
        grid[mouseY/50][mouseX/50] = 1;

        ismousePressed = true;



      }
//
      if(occur.type == SDL_MOUSEBUTTONUP ) {
        cout<<"mouse up!!"<<endl;
        ismousePressed = false;
      }







//
//      if(ismousePressed && occur.type == SDL_MOUSEMOTION ) {
//        cout<<"mouse in motion!!"<<endl;
//        grid[mouseY/50][mouseX/50] = 1;
//
//
//      }






    for(int i=0;i<SCR_HGT/50;i++) {


      for (int j = 0; j < SCR_WDT/50; j++) {

        cout<<grid[i][j]<<", ";

        if(grid[i][j] == 1){
          int rectGrid = ((SCR_WDT/50)*(i))+(j);
         // cout<<"the value "<<i<<"and j is "<<j<<"of grid is: "<<rectGrid<<endl;
          Rectangle* a = new Rectangle(renderer,gl->getCoordinate(rectGrid)->getX(),gl->getCoordinate(rectGrid)->getY(),50,50);
          a->updateColor(255,0,0,255);
          a->draw();

        }

      }
      cout<<"\n";
    }

    cout<<"**********************************************\n";




    for(Coordinates* c: placements){
      Rectangle* placement = new Rectangle(renderer,c->getX(), c->getY(),50,50);
      placement->updateColor(255,0,0,255);
      placement->draw();

    }


























    //frame capping.
    if ((1000/FPS) > (SDL_GetTicks() - startTick)) {

      SDL_Delay((1000/FPS - (SDL_GetTicks() - startTick)));
    }

    SDL_RenderPresent(renderer);





    // Render the changes above




  }
  // Close and destroy the window

  SDL_DestroyWindow(window);
  SDL_Quit();


  return 0;

}



