//
// Created by Soumyadeep Sinha on 2019-01-19.
//

#ifndef BREAKOUT_RECTANGLE_H
#define BREAKOUT_RECTANGLE_H
#include "SDL.h"
/**
 * This class is used to draw a rectangle on the screen.
 */
class Rectangle {

 public:
  SDL_Rect r;
  /**
   * This method is used to draw a rectangle on the screen.
   */
  void draw();
  /**
   * This method is used to color the rectangle.
   * @param r the red.
   * @param b the blue.
   * @param g the green.
   * @param a the alpha.
   */
  void updateColor(int r, int b, int g, int a);
  /**
   * This method is used to update teh rectangle with the desired x y coordinate and the width and the height.
   * @param x the x coordinate.
   * @param y the y coordinate.
   * @param w the width.
   * @param h the height.
   */
  void updateRectangle(int x, int y, int w, int h);

  /**
   * This is  the constructor.
   */
  Rectangle() {};
  /**
   * This is the parameterized constructor.
   * @param render
   * @param x
   * @param y
   * @param w
   * @param h
   */
  Rectangle(SDL_Renderer *render, int x, int y, int w, int h) {
    r.x = x;
    r.y = y;
    r.w = w;
    r.h = h;
    ren = render;
    SDL_SetRenderDrawColor(ren, 49, 224, 145, 255);
  }

 private:
  SDL_Renderer *ren;

};

#endif //BREAKOUT_RECTANGLE_H
