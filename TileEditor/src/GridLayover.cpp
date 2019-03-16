//
// Created by Soumyadeep Sinha on 2019-02-17.
//

#include "../include/GridLayover.h"

/**
 * This method is used to draw the Tile Map.
 */
void GridLayover::draw() {

  int hightTracker = 0;
  for (int i = 0; i < scH; i = i + grid) {

    for (int j = 0; j < scW; j = j + grid) {

      hightTracker++;
      Rectangle *a = new Rectangle(this->ren, j, i, grid - 1, grid - 1);
      a->updateColor(159, 193, 249, 255);
      a->draw();

    }
  }

}

/**
 * This method returns a particular coordinate .
 * @param a  the coordinate of a particular grid in the Tile Map.
 * @return the coordinate of a particular grid in the Tile Map.
 */
Coordinates *GridLayover::getCoordinate(int a) {

  return gridLayout[a];

}


