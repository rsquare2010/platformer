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
   * @param render the renderer.
   * @param x the x.
   * @param y the y.
   * @param w the width.
   * @param h the height.
   */
  Rectangle(int x, int y, int w, int h);

  /**
 * This is to get the x coordinate of the Rectangle.
 * @return the x.
 */
  int getX();

  /**
 * This is used to get the Y coordinate of the Rectangle.
 * @return the y.
 */
  int getY();

  /**
 * This metho dis used to get the width of the Rectangle.
 * @return the width.
 */
  int getWidth();

  /**
 * This method is used to get the height of the rectangle.
 * @return the height.
 */
  int getHeight();

  /**
 * This method is used to check if the rectangle overlaps.
 * @param other the other Rectangle.
 * @return true if the Rectangle overlaps.
 */
  bool overlap(Rectangle *other);

  /**
 * This method is used  to check if the Rectangle intersects.
 * @param other the other rectangle.
 * @return a new rectangle.
 */
  Rectangle *intersect(Rectangle *other);

 private:
  bool doesYOverlap(int y2, int height2);
  /**
* This method is used to return the min of two numbers.
* @param num1 number 1.
* @param num2 number 2.
* @return the min of two numbers.
*/
  int min(int num1, int num2);
  /**
* This method is used to return the max of two numbers.
* @param num1 number 1.
* @param num2 number 2.
* @return the max of two numbers.
*/
  int max(int num1, int num2);
  SDL_Renderer *ren;

};

#endif //BREAKOUT_RECTANGLE_H
