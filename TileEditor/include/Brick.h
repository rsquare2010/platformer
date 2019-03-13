//
// Created by Soumyadeep Sinha on 2019-01-26.
//

#ifndef BREAKOUT_BREAKOUTSQUAD_BRICK_H
#define BREAKOUT_BREAKOUTSQUAD_BRICK_H

#include "Coordinates.h"
#include "Rectangle.h"
/**
 * This is the definition of the brick class. This class is used tpo render a bricks on screen and provides functions to
 * manipulate the bricks.
 */
class Brick : public Rectangle {

 private:
  bool isBroken;
  Coordinates* coord;
 public:

  /**
   * This constructor is used to create and set the brick to its default values.
   * @param ren the renderer.
   * @param x the x coordinate.
   * @param y the y coordinate.
   */
  Brick(SDL_Renderer *ren,int x, int y): Rectangle(ren, x, y, 50, 20){

    isBroken = false;
    coord = new Coordinates(x,y);
  }

  /**
   * This method is used to set a boolean value which says whether the brick is broken or not.
   * @param broken  this is to set if the brick is broken.
   */
  void setIsBroken(bool broken);

  /**
   * This method is used to check if a particular brick is broken.
   * @return boolean value which says if the brick is broken or not.
   */
  bool getIsBroken();
  /**
   * This method is used to get the coordinate of the bricks.
   */
  Coordinates* getCoordinates();
  /**
   * This method is used to update the color of the brick.
   *
   * @param r the red.
   * @param b the blue.
   * @param g the green.
   */
  void upColor(int r,int b,int g);


};

#endif //BREAKOUT_BREAKOUTSQUAD_BRICK_H
