//
// Created by Soumyadeep Sinha on 2019-01-19.
//

#include "../include/Rectangle.h"
#include <iostream>
using namespace std;

/**
 * This method is used to draw a rectangle on the screen.
 */
void Rectangle::draw(SDL_Renderer *render) {
  this->ren = render;
  SDL_RenderFillRect(this->ren, &r);
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
 * This method is used to update the rectangle with the desired x y coordinate and the width and the height.
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

/**
 * This is a parameterized constructor.
 * @param x the x coordinate.
 * @param y the y coordinate.
 * @param w the width.
 * @param h the height.
 */
Rectangle::Rectangle(int x, int y, int w, int h) {
  r.x = x;
  r.y = y;
  r.w = w;
  r.h = h;
}

/**
 * This is to get the x coordinate of the Rectangle.
 * @return the x.
 */
int Rectangle::getX() {
  return r.x;
}

/**
 * This is used to get the Y coordinate of the Rectangle.
 * @return the y.
 */
int Rectangle::getY() {
  return r.y;
}

/**
 * This metho dis used to get the width of the Rectangle.
 * @return the width.
 */
int Rectangle::getWidth() {
  return r.w;
}

/**
 * This method is used to get the height of the rectangle.
 * @return the height.
 */
int Rectangle::getHeight() {
  return r.h;
}

/**
 * This method is used to check if the rectangle overlaps.
 * @param other the other Rectangle.
 * @return true if the Rectangle overlaps.
 */
bool Rectangle::overlap(Rectangle* other) {
  if ((other->getX() <= r.x) && ((other->getX() + other->getWidth()) > r.x)) {
    return doesYOverlap(other->getY(), other->getHeight());
  } else if ((other->getX() > r.x) && (other->getX() < (r.x + r.w))) {
    return doesYOverlap(other->getY(), other->getHeight());
  }
  return false;
}


/**
 * This method is used  to check if the Rectangle intersects.
 * @param other the other rectangle.
 * @return a new rectangle.
 */
Rectangle* Rectangle::intersect(Rectangle* other) {
  int x3 = max(r.x, other->getX());
  int y3 = max(r.y, other->getY());
  int width3 = min((r.x + r.w), (other->getX() + other->getWidth())) - x3;
  int height3 = min((r.y + r.h), (other->getY() + other->getHeight())) - y3;
  return new Rectangle(x3, y3, width3, height3);
}


/**
 * This method is used  to check if the Y coordinate overlaps.
 * @param y2 the y coordinate.
 * @param height2 the height of the other rectangle.
 * @return true if it overlaps.
 */
bool Rectangle::doesYOverlap(int y2, int height2) {
  if ((y2 <= r.y) && ((y2 + height2) > r.y)) {
    return true;
  } else if ((y2 > r.y) && (y2 < (r.y + r.h))) {
    return true;
  }
  return false;
}


/**
 * This method is used to return the min of two numbers.
 * @param num1 number 1.
 * @param num2 number 2.
 * @return the min of two numbers.
 */
int Rectangle::min(int num1, int num2) {
  if(num1 < num2) {
    return num1;
  }
  return num2;
}

/**
 * This method is used to return the max of two numbers.
 * @param num1 number 1.
 * @param num2 number 2.
 * @return the max of two numbers.
 */
int Rectangle::max(int num1, int num2) {
  if(num1 > num2) {
    return num1;
  }
  return num2;
}