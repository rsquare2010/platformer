//
// Created by Soumyadeep Sinha on 2019-01-19.
//

#include "Wall.h"

int Wall::objCounter = 0;

/**
 * This constructor is used to set the wall to its default setting.
 * @param ren the renderer.
 * @param num the number of bricks in the wall.
 * @param xc the x coordinate of the wall.
 * @param yc the y coordinate of the wall.
 */
Wall::Wall(SDL_Renderer *ren, int num, int xc, int yc) {

  this->wallId = objCounter++;
  this->render = ren;
  this->number = num;
  this->level = 1;
  coords = new Coordinates(xc, yc);
  int width = 50;
  int height = 20;

  for (int i = 0; i < number; i++) {

    arrayRect.push_back(new Brick(render, coords->getX() + (i*width), coords->getY()));

  }

}

/**
 * This method is used to draw the wall on the screen.
 */
void Wall::draw() {

  int width = 50;
  int height = 20;
  Rectangle *arrayShow[number];

  for (int i = 0; i < number; i++) {
    arrayShow[i] = new Rectangle(render, coords->getX() + (i*width), coords->getY(), width, height);

    if (wallId%2==0) {

      if (i%2==0) {
        if (this->level==1)
          arrayShow[i]->updateColor(49, 116, 224, 0);
        if (this->level==2)
          arrayShow[i]->updateColor(255, 0, 0, 0);
        if (this->level==3)
          arrayShow[i]->updateColor(255, 255, 255, 0);

      }

    } else {

      if (i%2!=0) {
        if (this->level==1)
          arrayShow[i]->updateColor(49, 116, 224, 0);
        if (this->level==2)
          arrayShow[i]->updateColor(255, 0, 0, 0);
        if (this->level==3)
          arrayShow[i]->updateColor(255, 255, 255, 0);
      }

    }

    if (!arrayRect[i]->getIsBroken()) {
      arrayRect[i]->draw();
      arrayShow[i]->draw();
    }

  }

}
/**
 * This method is used to get the coordinates of the wall.
 * @return the coordinates of the wall.
 */
Coordinates *Wall::getCoordinates() {

  return coords;

}

/**
 * This method is used to return the wall.
 * @return the wall.
 */
vector<Brick *> Wall::returnWall() {

  return arrayRect;

}

/**
 * This method is used to reset the wall.
 */
void Wall::resetWall() {

  for (int i = 0; i < arrayRect.size(); i++) {
    arrayRect[i]->setIsBroken(false);
  }
}

/**
 * This method is used to update the level of the wall.
 * @param le the level.
 */
void Wall::updateLevel(int le) {
  this->level = le;
}
