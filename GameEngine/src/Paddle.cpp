//
// Created by Soumyadeep Sinha on 2019-01-20.
//

#include "Paddle.h"

/**
 * The paddle constructor takes in the renderer, x coordinate, y coordinate, the paddle width and the height and
 * initialize the paddle class.
 * @param ren the renderer.
 * @param xc the x coordinate.
 * @param yc the y coordinate.
 * @param wc the width of the paddle.
 * @param hc the height of the paddle.
 */

Paddle::Paddle(SDL_Renderer *ren, int xc, int yc, int wc, int hc) {
  render = ren;
  coords = new Coordinates(xc, yc);
  w = wc;
  h = hc;
  rect = new Rectangle(render, coords->getX(), coords->getY(), w, h);

}

/**
 * This method is used to draw the paddle on the screen.
 */
void Paddle::draw() {

  rect = new Rectangle(render, coords->getX(), coords->getY(), w, h);
  updateColor(172, 96, 219, 0);
  rect->draw();

}

/**
 * This method is used to update the coordinate of the paddle.
 * @param xNew the nex x coordinate.
 * @param yNew the new y coordinate.
 */
void Paddle::updateCoordinate(int xNew, int yNew) {

  coords->updateCoordinates(xNew, yNew);
  rect->updateRectangle(coords->getX(), coords->getY(), w, h);
}

/**
 * This method is used to update the color of the paddle.
 * @param r the red.
 * @param b the blue.
 * @param g the green.
 * @param a the alpha.
 */
void Paddle::updateColor(int r, int b, int g, int a) {

  rect->updateColor(r, b, g, a);

}

/**
 * This method is used to get the coordinate of the paddle.
 * @return the coordinate of the paddle.
 */
Coordinates *Paddle::getCoordinates() {

  return coords;

}

/**
 * This method is used update the width and the height of the paddle.
 * @param wc the width of the paddle.
 * @param hc the height of the paddle.
 */
void Paddle::updatePaddle(int wc, int hc) {
  w = wc;
  h = hc;
  //draw();
}


