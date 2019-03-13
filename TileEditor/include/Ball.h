//
// Created by Soumyadeep Sinha on 2019-01-20.
//

#ifndef BREAKOUT_BALL_H
#define BREAKOUT_BALL_H
#include "SDL.h"
#include "Coordinates.h"
#include <iostream>
#define SCR_WDT  1800
#define SCR_HGT  200
#define BNR_HGT  65

using namespace std;
/**
 * This is the definition of the ball class. This class is used tpo render a ball on screen and provides functions to
 * manipulate the ball to make movements or color.
 */

class Ball {

 public:
  /**
 * This is the implementation of the Ball class. This class is used to create the ball and place it in the screen at a
 * particular coordinate and moves the ball. The constructor initializes the ball class with the default values.
 *
 * @param SDL_Render*  The Render pointer is passed to render the ball in the window.
 * @param int r This is the radius of the ball.
 * @param int xc This is the x coordinate of the ball.
 * @param int yc This is the y coordinate of the ball.
 */
  Ball(SDL_Renderer *rend, int radius, int x, int y);

  /**
   * This method is used to draw the ball on the window. This method doesnot take any argument.
   */
  void draw();
  /**
   * moveBall method is used to move the ball in a certain direction with a certain velocity.
   *
   */
  void updateCoordinates(int xc, int yc);
  /**
   * This method takes in the x coordinate and the Y coordinate pass and updates the ball coordinate with
   * the value passed.
   *
   * @param int xc This is the x coordinate to be updated.
   * @param int yc This is the y coordinate to be updated.
   */
  Coordinates *getCoordinates();
  /**
   * This method returns the coordinate of the ball.
   * @return Coordinate* the coordinate of the ball.
   */
  void moveBall();
  /**
   * This method is used to bounce th ball to the Y direction, opposite the direction of the movement of the ball.
   */
  void bounceInYDirection();
  /**
   * This method is used to bounce th ball to the X direction, opposite the direction of the movement of the ball.
   */
  void bounceInXDirection();
  /**
   * This method is used to detect and implement the bouncing of the ball from the paddle.
   */
  void bounceFromPaddle();
  /**
   * This method is used to get the x velocity of the ball.
   * @return  the X velocity of the ball.
   */
  int getXvelocity();
  /**
   * This method is used to get the Y velocity of the ball.
   * @return  the Y velocity of the ball.
   */
  int getYvelocity();
  /**
   * This method is used to get the radius of the ball.
   * @return the radius of the ball.
   */
  int getRadius();
  /**
   * This method is used to stop the ball from moving.
   */
  void stopBall();
  /**
   * This method is used to move the ball once it is stopped.
   */
  void moveBallAgain();

 private:
  SDL_Renderer *render;
  int radius;
  Coordinates *coords;
  int xVelocity;
  int yVelocity;

};

#endif //BREAKOUT_BALL_H
