//
// Created by Soumyadeep Sinha on 2019-03-11.
//

#ifndef PLATFORMER_SUNDAYS_ARE_FUNDAYS_WORLDLAYOVER_H
#define PLATFORMER_SUNDAYS_ARE_FUNDAYS_WORLDLAYOVER_H

#include <vector>
#include <iostream>
using namespace std;
#include "Rectangle.h"
#include "Coordinates.h"
#define worldGrid 20*2

class WorldLayover {

 public:

  WorldLayover(SDL_Renderer *render, int screenW, int screenH){
    this->ren = render;
    this->scW = screenW;
    this->scH = screenH;
    for(int i=0;i<scH;i = i+worldGrid) {
      for (int j = 0; j < scW; j = j + worldGrid) {

        gridLayout.push_back(new Coordinates(j,i));

      }
    }



  }

  Coordinates* getCoordinate(int a);

 private:
  SDL_Renderer *ren;
  int scW;
  int scH;
  vector<Coordinates *> gridLayout;



};


#endif //PLATFORMER_SUNDAYS_ARE_FUNDAYS_WORLDLAYOVER_H
