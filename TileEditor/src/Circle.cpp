//
// Created by Soumyadeep Sinha on 2019-01-20.
//

#include "Circle.h"
#include <math.h>

/**
 * This method is used to draw a circle.
 */
void Circle::draw() {
  for (float theta = 0; theta < (PI*2); theta += step) {
    new_x = h + (radius*cos(theta));
    new_y = k - (radius*sin(theta));

    if (theta!=0) {
      SDL_RenderDrawLine(ren, old_x, old_y, new_x, new_y);
    }

    old_x = new_x;
    old_y = new_y;

  }
}

/**
 * This method is used to update the color of the circle.
 * @param r the red.
 * @param g the green.
 * @param b the blue.
 * @param a the alpha.
 */
void Circle::updateColor(int r, int g, int b, int a) {

  SDL_SetRenderDrawColor(ren, r, g, b, a);

}
