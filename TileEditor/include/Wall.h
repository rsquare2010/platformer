//
// Created by Soumyadeep Sinha on 2019-01-19.
//

#ifndef BREAKOUT_WALL_H
#define BREAKOUT_WALL_H

#include <iostream>
#include "Brick.h"
#include "Coordinates.h"
#include <vector>
using namespace std;

/**
 * This class is used to generate walls.
 */
class Wall {

 private:
  static int objCounter;
  int wallId;
  vector<Brick *> arrayRect;
  SDL_Renderer *render;
  int number;
//  int x;
//  int y;
  Coordinates *coords;
  int level;

 public:
  /**
   * This constructor is used to set the wall to its default setting.
   * @param ren the renderer.
   * @param num the number of bricks in the wall.
   * @param xc the x coordinate of the wall.
   * @param yc the y coordinate of the wall.
   */
  Wall(SDL_Renderer *ren, int num, int xc, int yc);
  /**
   * This method is used to draw the wall on the screen.
   */
  void draw();
  /**
   * This method is used to get the coordinates of the wall.
   * @return the coordinates of the wall.
   */
  Coordinates *getCoordinates();
  /**
   * This method is used to return the wall.
   * @return the wall.
   */
  vector<Brick *> returnWall();
  /**
   * This method is used to reset the wall.
   */
  void resetWall();
  /**
   * This method is used to update the level of the wall.
   * @param le the level.
   */
  void updateLevel(int le);

};

#endif //BREAKOUT_WALL_H
