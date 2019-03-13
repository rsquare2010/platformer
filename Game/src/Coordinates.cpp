//
// Created by Soumyadeep Sinha on 2019-01-20.
//

#include "Coordinates.h"

/**
 * This class is used to create teh coordinates. The constructor takes in the x coordinate and the Y coordinate.
 * @param xc the X coordinate.
 * @param yc the y coordinate.
 */
Coordinates::Coordinates(int xc, int yc) {
  x = xc;
  y = yc;
}

/**
 * This method is used to return an object of the coordinate class.
 * @return the object of coordinate class.
 */
Coordinates *Coordinates::returnCoordinate() {
  return this;
}

/**
 * This method is used to get the x coordinate.
 * @return x coordinate.
 */
int Coordinates::getX() {
  return x;
}

/**
 * This method is used to get the y coordinate.
 * @return y coordinate.
 */
int Coordinates::getY() {
  return y;
}

/**
 * This is used to update the coordinates.
 * @param xNew the new x coordinate.
 * @param yNew the new y coordinate.
 */
void Coordinates::updateCoordinates(int xNew, int yNew) {

  x = xNew;
  y = yNew;

}
