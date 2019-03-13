#include <iostream>
#include "SDL.h"

#include "Rectangle.h"
#include "ResourceManager.h"
#include <stdio.h>
#include <vector>
#include <fstream>
#include "../include/GridLayover.h"


using namespace std;
//using namespace Json;

#define SCR_WDT  800
#define SCR_HGT  200
const int SCR_CEN_X = SCR_WDT/2;
const int SCR_CEN_Y = SCR_HGT/2;
#define FPS 30
#define grid 20

bool isColorCoded = true;




SDL_Surface* loadSurface( std::string path );
void saveFile(int gridArray[][SCR_WDT/grid]);



/**tou
 * This this the main function fo the game. This is function implements the game loop.
 * @param argc int argument.
 * @param argv character argument.
 * @return 0 when it executes perfectly.
 */
int main(int argc, char **argv) {


  ResourceManager* rm = ResourceManager::getInstance();
  rm->startUp();
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

  int mouseX, mouseY;
  int mouseGrid;
  Rectangle* selection = new Rectangle(renderer,0, 0,grid,grid);
  int gridArray[SCR_HGT/grid][SCR_WDT/grid] = {};
  bool ismousePressed = false;








  GridLayover* gl = new GridLayover(renderer,SCR_WDT,SCR_HGT);

  bool drag = false;
  int value = 0;

  while (run) {



    startTick = SDL_GetTicks();
    SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
    SDL_RenderClear(renderer);
    gl->draw();








    SDL_GetMouseState(&mouseX, &mouseY);

    mouseGrid = ((SCR_WDT/grid)*(mouseY/grid))+(mouseX/grid);



    SDL_Event e;
    while(SDL_PollEvent(&e)){
      switch(e.type){
        case SDL_QUIT:
          saveFile(gridArray);
          run = false;
          break;
        case SDL_MOUSEBUTTONDOWN:
          //cout<<"hello \n";

          if(gridArray[mouseY/grid][mouseX/grid] == 3){
            gridArray[mouseY/grid][mouseX/grid] = -1;
          }
          gridArray[mouseY/grid][mouseX/grid] = gridArray[mouseY/grid][mouseX/grid]+1;
          value = gridArray[mouseY/grid][mouseX/grid];
          drag = true;
        case SDL_MOUSEMOTION:
          if(drag){
            //cout<<"mouse in motion";
            gridArray[mouseY/grid][mouseX/grid] = value;
          }
          break;
        case SDL_MOUSEBUTTONUP:
          //cout<<"mouse up\n";
          drag = false;
          value =0;
          break;




      }
    }








    //cout<<"mouseX: "<<mouseX/50<<"mouseY: "<<mouseY/50<<endl;


    selection->updateColor(255,255,255,255);
    selection->updateRectangle(gl->getCoordinate(mouseGrid)->getX(), gl->getCoordinate(mouseGrid)->getY(),grid,grid);
    selection->draw();



    for(int i=0;i<SCR_HGT/grid;i++) {


      for (int j = 0; j < SCR_WDT/grid; j++) {

        SDL_Rect dstrect;
        SDL_Texture * texture;
        SDL_Surface* image;

        //cout<<gridArray[i][j]<<", ";

        if(gridArray[i][j] != 0){
          int rectGrid = ((SCR_WDT/grid)*(i))+(j);
         // cout<<"the value "<<i<<"and j is "<<j<<"of grid is: "<<rectGrid<<endl;
          Rectangle* a = new Rectangle(renderer,gl->getCoordinate(rectGrid)->getX(),gl->getCoordinate(rectGrid)->getY(),grid,grid);

          if(gridArray[i][j] == 1){

            if(isColorCoded) {
               a->updateColor(255,0,0,255);
            }else {
              image = (SDL_Surface *) rm->getValue("Character");
              texture = SDL_CreateTextureFromSurface(renderer, image);
              dstrect = {gl->getCoordinate(rectGrid)->getX(), gl->getCoordinate(rectGrid)->getY(), grid, grid};
            }
          }
          else if(gridArray[i][j] == 2){

            if(isColorCoded) {
              a->updateColor(255,255,255,255);
            }
            else{
              image = (SDL_Surface*) rm->getValue("Ground");

              texture = SDL_CreateTextureFromSurface(renderer, image);
              dstrect = { gl->getCoordinate(rectGrid)->getX(), gl->getCoordinate(rectGrid)->getY(),grid,grid};


            }



          } else if(gridArray[i][j] == 3){
            if(isColorCoded) {
              a->updateColor(0, 255, 0, 255);
            }
            else{

            }

          }

          if(isColorCoded) {
            a->draw();
          }else{
            SDL_RenderCopy(renderer, texture, NULL, &dstrect);
          }



        }

      }
      //cout<<"\n";
    }

    //cout<<"**********************************************\n";









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


void saveFile(int gridArray[SCR_HGT/grid][SCR_WDT/grid]){

  ofstream myfile ("./media/example.txt");
  if (myfile.is_open())
  {
    for(int i=0;i<SCR_HGT/grid;i++) {

      for (int j = 0; j < SCR_WDT/grid; j++) {
        myfile << gridArray[i][j]<< ", ";
      }

    }
    myfile.close();
  }
  else cout << "Unable to open file";

}





