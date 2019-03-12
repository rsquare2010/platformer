//
// Created by Soumyadeep Sinha on 2019-03-11.
//

#ifndef PLATFORMER_SUNDAYS_ARE_FUNDAYS_CHARACTER_H
#define PLATFORMER_SUNDAYS_ARE_FUNDAYS_CHARACTER_H
#include "SDL.h"
#include "Coordinates.h"
#include "Draw.h"
#include <iostream>

class Character {

 public:
  /**
 * This is the implementation of the Ball class. This class is used to create the ball and place it in the screen at a
 * particular coordinate and moves the ball. The constructor initializes the ball class with the default values.
 *
 * @param SDL_Render*  The Render pointer is passed to render the ball in the window.
 * @param int r This is the radius of the ball.
 * @param int xc This is the x coordinate of the ball.
 * @param int yc This is the y coordinate of the ball.
 */
  Character(SDL_Renderer *rend, int x, int y);


  void draw();

  void updateCoordinates(int xc, int yc);

  Coordinates *getCoordinates();

  void gravity();
  void moveInXDirection();

  int getXvelocity();

  int getYvelocity();

  void stopFalling();

  void startFalling();


 private:
  SDL_Renderer *render;
  Coordinates *coords;
  int xVelocity;
  int yVelocity;

};

#endif //PLATFORMER_SUNDAYS_ARE_FUNDAYS_CHARACTER_H
