//
// Created by Soumyadeep Sinha on 2019-03-11.
//

#include "Character.h"

Character::Character(SDL_Renderer *rend, int xc, int yc) {
  render = rend;
  coords = new Coordinates(xc, yc);
  xVelocity = 0;
  yVelocity = 3;

}

void Character::draw() {
  int scaleFactor = 2;
  SDL_Surface* character = SDL_LoadBMP("../media/char.bmp");
  SDL_Rect dstrect =  {coords->getX(),coords->getY(),20*scaleFactor,20*scaleFactor};
  Draw::sketch(render, SDL_CreateTextureFromSurface(this->render, character), dstrect );

}

void Character::gravity(){

  int x = coords->getX();
  int y = coords->getY();

  x = x + xVelocity;
  y = y + yVelocity;

  updateCoordinates(x, y);
}

void Character::moveInXDirection() {
  int x = coords->getX();
  int y = coords->getY();
  x = x + 5;
  updateCoordinates(x, y);



}

void Character::stopFalling() {
  yVelocity = 0;

}
void Character::startFalling() {
  yVelocity = 5;
}

void Character::updateCoordinates(int xc, int yc) {

  coords->updateCoordinates(xc, yc);

}

Coordinates *Character::getCoordinates() {

  return coords;

}

int Character::getXvelocity() {
  return xVelocity;
}


int Character::getYvelocity() {
  return yVelocity;
}