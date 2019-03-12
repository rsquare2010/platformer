#include <iostream>
#include "SDL.h"
#include "Rectangle.h"
#include "ResourceManager.h"
#include <stdio.h>
#include <vector>
#include <ctype.h>
#include "World.h"
#include "WorldLayover.h"
#include "Character.h"
#include "GroundTile.h"


using namespace std;
using namespace Json;
#define TILE_SCR_WDT  1200
#define TILE_SCR_HGT  200
#define grid 20

#define SCR_WDT  800
#define SCR_HGT  500
const int SCR_CEN_X = SCR_WDT/2;
const int SCR_CEN_Y = SCR_HGT/2;
#define FPS 30
void detectCollisionWithWallY1(Character *b, World* wall);
bool checkCollision1(Coordinates *obj1,
                    int obj1Height,
                    int obj1Width,
                    Coordinates *obj2,
                    int obj2Height,
                    int obj2Width);
bool sideCollision;

/**
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

  renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);

  // Check that the window was successfully created
  if (window==NULL) {
    // In the case that the window could not be made...
    printf("Could not create window: %s\n", SDL_GetError());
    return 1;
  }


  Uint32 startTick;






  World* world = new World(renderer);
  world->loadArtifacts();
  //world->printWorld();

  Character* mario = new Character(renderer, 100,100);

 // GroundTile* gt = new GroundTile(renderer, 100,450);



  vector<GroundTile* > groundA = world->returnGround();
  //exit(0);



  while (run) {
    SDL_Event e;
    startTick = SDL_GetTicks();
    SDL_SetRenderDrawColor(renderer, 255, 255,255, 255);
    SDL_RenderClear(renderer);

    while(SDL_PollEvent(&e)){
      switch(e.type){
        case SDL_QUIT:

          run = false;
          break;
        case SDL_KEYDOWN:

          switch (e.key.keysym.sym) {

            case (SDLK_RIGHT)://cout << "Going right\n";
              mario->moveInXDirection();

              break;
            case (SDLK_LEFT)://cout << "Going left\n";

              break;

            case SDLK_q:run = false;
              break;
          }


      }
    }






    //world->drawWorld();



    detectCollisionWithWallY1(mario, world);
    mario->gravity();


    mario->draw();

    for (int i = 0; i < groundA.size(); i++) {

      groundA[i]->draw();
    }

    //frame capping.
    if ((1000/FPS) > (SDL_GetTicks() - startTick)) {

      SDL_Delay((1000/FPS - (SDL_GetTicks() - startTick)));
    }

    SDL_RenderPresent(renderer);


  }
  // Close and destroy the window

  SDL_DestroyWindow(window);
  SDL_Quit();


  return 0;

}

void detectCollisionWithWallY1(Character *b, World* wall) {

  //cout<<"checking wall Y\n";
  Coordinates *coorBall = b->getCoordinates();

  vector < GroundTile* > test = wall->returnGround();


  bool didCollide = false;

  for (int i = 0; i < test.size(); i++) {

    if (checkCollision1(coorBall, 40, 5, test[i]->getCoordinates(), 40, 40)) {

      didCollide = true;
      break;

    }


  }

  if(didCollide){
    //cout<<"i am colliding***********************************************\n";
    b->stopFalling();
  } else{
    //cout<<"i am not colliding\n";
    b->startFalling();
  }


}

bool checkCollision1(Coordinates *obj1,
                               int obj1Height,
                               int obj1Width,
                               Coordinates *obj2,
                               int obj2Height,
                               int obj2Width) {

  sideCollision = false;
  if (obj1->getY() + obj1Height < obj2->getY()) {

    return false;
  } else if (obj1->getY() > obj2->getY() + obj2Height) {

    return false;
  } else if (obj1->getX() + obj1Width < obj2->getX()) {
    return false;
  } else if (obj1->getX() > obj2->getX() + obj2Width) {
    return false;
  }

  if (obj1->getX() + obj1Width - obj2->getX() < obj2->getX() + obj2Width - obj1->getX()
      && obj1->getX() + obj1Width - obj2->getX() < obj1->getY() + obj1Height - obj2->getY()
      && obj1->getX() + obj1Width - obj2->getX() < obj2->getY() + obj2Height - obj1->getY()) {
    sideCollision = true;
  }

  if (obj2->getX() + obj2Width - obj1->getX() < obj1->getX() + obj1Width - obj2->getX()
      && obj2->getX() + obj2Width - obj1->getX() < obj1->getY() + obj1Height - obj2->getY()
      && obj2->getX() + obj2Width - obj1->getX() < obj2->getY() + obj2Height - obj1->getY()) {
    sideCollision = true;
  }

  return true;
}


