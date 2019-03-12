//
// Created by Soumyadeep Sinha on 2019-03-11.
//

#include "GroundTile.h"

void GroundTile::draw() {
  int scaleFactor = 2;
  SDL_Surface* character = SDL_LoadBMP("../media/Tiles.bmp");
  SDL_Rect dstrect =  {coords->getX(),coords->getY(),20*scaleFactor,20*scaleFactor};
  Draw::sketch(render, SDL_CreateTextureFromSurface(this->render, character), dstrect );
}

Coordinates *GroundTile::getCoordinates() {

  return coords;

}
