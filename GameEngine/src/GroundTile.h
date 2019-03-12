//
// Created by Soumyadeep Sinha on 2019-03-11.
//

#ifndef PLATFORMER_SUNDAYS_ARE_FUNDAYS_GROUNDTILE_H
#define PLATFORMER_SUNDAYS_ARE_FUNDAYS_GROUNDTILE_H
#include "SDL.h"
#include "Coordinates.h"
#include "Draw.h"
#include <iostream>
class GroundTile {

 public:
  GroundTile(SDL_Renderer *render, int x, int y){

    this->render = render;
    this->coords = new Coordinates(x, y);

  }
  void draw();
  Coordinates* getCoordinates();

 private:
  SDL_Renderer *render;
  Coordinates *coords;

};

#endif //PLATFORMER_SUNDAYS_ARE_FUNDAYS_GROUNDTILE_H
