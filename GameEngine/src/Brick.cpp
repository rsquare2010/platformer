//
// Created by Soumyadeep Sinha on 2019-01-26.
//

#include "Brick.h"
/**
 * This method is used to set a boolean value which says whether the brick is broken or not.
 * @param broken  this is to set if the brick is broken.
 */
void Brick::setIsBroken(bool broken) {
  isBroken = broken;
}

/**
 * This method is used to get the coordinate of the bricks.
 */
Coordinates *Brick::getCoordinates() {
  return coord;
}

/**
 * This method is used to check if a particular brick is broken.
 * @return boolean value which says if the brick is broken or not.
 */
bool Brick::getIsBroken() {
  return isBroken;
}

/**
 * This method is used to update the color of the brick.
 *
 * @param r the red.
 * @param b the blue.
 * @param g the green.
 */
void Brick::upColor(int r, int b, int g) {
  updateColor(r, b, g, 255);
}