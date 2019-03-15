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
  void draw(SDL_Renderer *render);
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
  Rectangle(int x, int y, int w, int h);

  int getX();

  int getY();

  int getWidth();

  int getHeight();

  bool overlap(Rectangle* other);

  Rectangle* intersect(Rectangle* other);

 private:
    bool doesYOverlap(int y2, int height2);
    int min(int num1, int num2);
    int max(int num1, int num2);
    SDL_Renderer *ren;

};

#endif //BREAKOUT_RECTANGLE_H
