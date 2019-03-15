//
// Created by Soumyadeep Sinha on 2019-02-17.
//

#ifndef PLATFORMER_SUNDAYS_ARE_FUNDAYS_GRIDLAYOVER_H
#define PLATFORMER_SUNDAYS_ARE_FUNDAYS_GRIDLAYOVER_H
#include <vector>
#include <iostream>
using namespace std;
#include "Rectangle.h"
#include "Coordinates.h"
#define grid 20

/**
 * This class is used to track all the coordinates the entire Tile Map.
 */
class GridLayover {

 public:
/**
 * This is th econstructor
 * @param render the renderer is passed.
 * @param screenW the screen width .
 * @param screenH the screen height.
 */
  GridLayover(SDL_Renderer *render, int screenW, int screenH){
    this->ren = render;
    this->scW = screenW;
    this->scH = screenH;
    for(int i=0;i<scH;i = i+grid) {
      for (int j = 0; j < scW; j = j + grid) {

        gridLayout.push_back(new Coordinates(j,i));

      }
    }



  }

  /**
   * This method is used to draw the Grids.
   */
  void draw();
  Coordinates* getCoordinate(int a);

 private:
  SDL_Renderer *ren;
  int scW;
  int scH;
  vector<Coordinates *> gridLayout;



};

#endif //PLATFORMER_SUNDAYS_ARE_FUNDAYS_GRIDLAYOVER_H
