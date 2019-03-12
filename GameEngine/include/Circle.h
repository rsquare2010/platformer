//
// Created by Soumyadeep Sinha on 2019-01-20.
//

#ifndef BREAKOUT_CIRCLE_H
#define BREAKOUT_CIRCLE_H

#include "SDL.h"
#define PI  3.14159
/**
 * This class is used to create and render a circle on screen.
 */
class Circle {

 private:
  int radius;
  int h; // The X access of the center of the circle.
  int k; // The Y access of the center of the circle.
  int new_x;
  int new_y;
  int old_x;
  int old_y;
  SDL_Renderer *ren;
  float step;

 public:
/**
 * The constructor creates an object of circle and sets it to default value.
 * @param render
 * @param rad
 * @param x
 * @param y
 */
  Circle(SDL_Renderer *render, int rad, int x, int y) {

    ren = render;
    radius = rad;
    h = x;
    k = y;
    new_x = 0;
    new_y = 0;
    old_x = 0;
    old_y = 0;
    step = (PI*2)/100;

  }

  /**
   * This method is used to draw a circle.
   */
  void draw();
  /**
   * This method is used to update the color of the circle.
   * @param r the red.
   * @param g the green.
   * @param b the blue.
   * @param a the alpha.
   */
  void updateColor(int r, int g, int b, int a);
};

#endif //BREAKOUT_CIRCLE_H
