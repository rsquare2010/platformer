//
// Created by Soumyadeep Sinha on 2019-01-19.
//

#ifndef BREAKOUT_RECTANGLE_H
#define BREAKOUT_RECTANGLE_H
#include "SDL.h"

/**
 * This class is used to draw a rectangle on the screen.
 */
class Rectangle {

 public:
  SDL_Rect r;
  /**
   * This method is used to draw a rectangle on the screen.
   */
  void draw(SDL_Renderer *render);
  /**
   * This method is used to color the rectangle.
   * @param r the red.
   * @param b the blue.
   * @param g the green.
   * @param a the alpha.
   */
  void updateColor(int r, int b, int g, int a);
  /**
   * This method is used to update teh rectangle with the desired x y coordinate and the width and the height.
   * @param x the x coordinate.
   * @param y the y coordinate.
   * @param w the width.
   * @param h the height.
   */
  void updateRectangle(int x, int y, int w, int h);

  /**
   * This is  the constructor.
   */
  Rectangle() {};
  /**
   * This is the parameterized constructor.
   * @param render
   * @param x
   * @param y
   * @param w
   * @param h
   */
  Rectangle(int x, int y, int w, int h) {
    r.x = x;
    r.y = y;
    r.w = w;
    r.h = h;
//    ren = render;
//    SDL_SetRenderDrawColor(ren, 49, 224, 145, 255);
  }

  int getX() {
    return r.x;
  }

  int getY() {
    return r.y;
  }

  int getWidth() {
    return r.w;
  }

  int getHeight() {
    return r.h;
  }

  bool overlap(Rectangle* other) {
      if ((other->getX() <= r.x) && ((other->getX() + other->getWidth()) > r.x)) {
        return doesYOverlap(other->getY(), other->getHeight());
      } else if ((other->getX() > r.x) && (other->getX() < (r.x + r.w))) {
        return doesYOverlap(other->getY(), other->getHeight());
      }
      return false;
  }

  Rectangle* intersect(Rectangle* other) {
    int x3 = max(r.x, other->getX());
    int y3 = max(r.y, other->getY());
    int width3 = min((r.x + r.w), (other->getX() + other->getWidth())) - x3;
    int height3 = min((r.y + r.h), (other->getY() + other->getHeight())) - y3;
    return new Rectangle(x3, y3, width3, height3);
  }

 private:
    bool doesYOverlap(int y2, int height2) {
      if ((y2 <= r.y) && ((y2 + height2) > r.y)) {
        return true;
      } else if ((y2 > r.y) && (y2 < (r.y + r.h))) {
        return true;
      }
      return false;
    }

    int min(int num1, int num2) {
      if(num1 < num2) {
        return num1;
      }
      return num2;
    }

    int max(int num1, int num2) {
      if(num1 > num2) {
        return num1;
      }
      return num2;
    }
  SDL_Renderer *ren;

};

#endif //BREAKOUT_RECTANGLE_H
