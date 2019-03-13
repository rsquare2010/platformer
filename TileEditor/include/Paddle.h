//
// Created by Soumyadeep Sinha on 2019-01-20.
//

#ifndef BREAKOUT_BREAKOUTSQUAD_PADDLE_H
#define BREAKOUT_BREAKOUTSQUAD_PADDLE_H

#include "Rectangle.h"
#include "Coordinates.h"
#include "SDL.h"

/**
 * This class is used to create the paddle in the game.
 */

class Paddle {

 public:

/**
 * The paddle constructor takes in the renderer, x coordinate, y coordinate, the paddle width and the height and
 * initialize the paddle class.
 * @param ren the renderer.
 * @param xc the x coordinate.
 * @param yc the y coordinate.
 * @param wc the width of the paddle.
 * @param hc the height of the paddle.
 */
  Paddle(SDL_Renderer *ren, int xc, int yc, int wc, int hc);
  /**
   * This method is used to draw the paddle on the screen.
   */
  void draw();
  /**
   * This method is used to update the coordinate of the paddle.
   * @param xNew the nex x coordinate.
   * @param yNew the new y coordinate.
   */
  void updateCoordinate(int x, int y);
  /**
   * This method is used to update the color of the paddle.
   * @param r the red.
   * @param b the blue.
   * @param g the green.
   * @param a the alpha.
   */
  void updateColor(int r, int b, int g, int a);
  /**
   * This method is used to get the coordinate of the paddle.
   * @return the coordinate of the paddle.
   */
  void updatePaddle(int w, int h);
  /**
   * This method is used update the width and the height of the paddle.
   * @param wc the width of the paddle.
   * @param hc the height of the paddle.
   */
  Coordinates *getCoordinates();

 private:
  SDL_Renderer *render;
  Rectangle *rect;
  Coordinates *coords;
  int w;
  int h;

};

#endif //BREAKOUT_BREAKOUTSQUAD_PADDLE_H
