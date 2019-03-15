//
// Created by Soumyadeep Sinha on 2019-01-20.
//

#ifndef BREAKOUT_BREAKOUTSQUAD_COORDINATES_H
#define BREAKOUT_BREAKOUTSQUAD_COORDINATES_H

/**
 * This is the definition of the coordinate class.
 */
class Coordinates {

 private:
  int x;
  int y;
 public:
  /**
   * This class is used to create teh coordinates. The constructor takes in the x coordinate and the Y coordinate.
   * @param xc the X coordinate.
   * @param yc the y coordinate.
   */
  Coordinates(int xc, int yc);
  /**
   * This method is used to return an object of the coordinate class.
   * @return the object of coordinate class.
   */
  Coordinates *returnCoordinate();
  /**
   * This is used to update the coordinates.
   * @param xNew the new x coordinate.
   * @param yNew the new y coordinate.
   */
  void updateCoordinates(int xNew, int yNew);
  /**
   * This method is used to get the x coordinate.
   * @return x coordinate.
   */
  int getX();
  /**
   * This method is used to get the y coordinate.
   * @return y coordinate.
   */
  int getY();

};

#endif //BREAKOUT_BREAKOUTSQUAD_COORDINATES_H
