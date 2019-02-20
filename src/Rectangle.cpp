//
// Created by Soumyadeep Sinha on 2019-01-19.
//

#include "Rectangle.h"
#include <iostream>
using namespace std;

/**
 * This method is used to draw a rectangle on the screen.
 */
void Rectangle::draw() {

  SDL_RenderFillRect(ren, &r);
}

/**
 * This method is used to color the rectangle.
 * @param r the red.
 * @param b the blue.
 * @param g the green.
 * @param a the alpha.
 */
void Rectangle::updateColor(int r, int b, int g, int a) {
  SDL_SetRenderDrawColor(ren, r, b, g, a);
}

/**
 * This method is used to update teh rectangle with the desired x y coordinate and the width and the height.
 * @param x the x coordinate.
 * @param y the y coordinate.
 * @param w the width.
 * @param h the height.
 */
void Rectangle::updateRectangle(int x, int y, int w, int h) {
  r.x = x;
  r.y = y;
  r.w = w;
  r.h = h;
}