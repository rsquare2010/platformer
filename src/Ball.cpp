//
// Created by Soumyadeep Sinha on 2019-01-20.
//

#include "Ball.h"
#include "Circle.h"
#include "State.h"

/**
 * This is the implementation of the Ball class. This class is used to create the ball and place it in the screen at a
 * particular coordinate and moves the ball. The constructor initializes the ball class with the default values.
 *
 * @param SDL_Render*  The Render pointer is passed to render the ball in the window.
 * @param int r This is the radius of the ball.
 * @param int xc This is the x coordinate of the ball.
 * @param int yc This is the y coordinate of the ball.
 */
Ball::Ball(SDL_Renderer *rend, int r, int xc, int yc) {
  render = rend;
  radius = r;
  coords = new Coordinates(xc, yc);
  xVelocity = 3;
  yVelocity = 4;

}

/**
 * This method is used to draw the ball on the window. This method doesnot take any argument.
 */
void Ball::draw() {

  //cout<<"drawing ball "<< radius<<" teh x value is"<<x<<" the y value is "<<y<<"\n";
  Circle *arrayCircles[radius];
  for (int i = 0; i < radius; i++) {

    arrayCircles[i] = new Circle(render, i, coords->getX(), coords->getY());
    arrayCircles[i]->updateColor(255, 127, 0, 255);
    arrayCircles[i]->draw();

  }

}

/**
 * moveBall method is used to move the ball in a certain direction with a certain velocity.
 *
 */
void Ball::moveBall() {

  int x = coords->getX();
  int y = coords->getY();

  x = x + xVelocity;
  y = y + yVelocity;

  if (x < 0) {
    xVelocity = -xVelocity;
  } else if (x + radius > SCR_WDT) {
    xVelocity = -xVelocity;
  }

  if (y < BNR_HGT + radius) {
    yVelocity = -yVelocity;
  } else if (y + radius > SCR_HGT) {
//    yVelocity = -yVelocity;
//    resetBall();
    x = 5;
    y = 150;
    State::getInstance().reduceLife();
    //this should happen once and the ball should get reset.
//    yVelocity = 0;
//    xVelocity = 0;
  }

  updateCoordinates(x, y);
}

/**
 * This method takes in the x coordinate and the Y coordinate pass and updates the ball coordinate with
 * the value passed.
 *
 * @param int xc This is the x coordinate to be updated.
 * @param int yc This is the y coordinate to be updated.
 */
void Ball::updateCoordinates(int xc, int yc) {

  coords->updateCoordinates(xc, yc);

}

/**
 * This method returns the coordinate of the ball.
 * @return Coordinate* the coordinate of the ball.
 */
Coordinates *Ball::getCoordinates() {

  return coords;

}

/**
 * This method is used to bounce th ball to the Y direction, opposite the direction of the movement of the ball.
 */
void Ball::bounceInYDirection() {
  yVelocity = -yVelocity;
}

/**
 * This method is used to bounce th ball to the X direction, opposite the direction of the movement of the ball.
 */
void Ball::bounceInXDirection() {
  xVelocity = -xVelocity;
}

/**
 * This method is used to detect and implement the bouncing of the ball from the paddle.
 */
void Ball::bounceFromPaddle() {
  yVelocity = -yVelocity;
  int randomVelocity = (rand()%(3)) + 1;
  if (rand()%2==0) {
    xVelocity = randomVelocity;
  } else {
    xVelocity = -randomVelocity;
  }

}

/**
 * This method is used to get the x velocity of the ball.
 * @return  the X velocity of the ball.
 */
int Ball::getXvelocity() {
  return xVelocity;
}

/**
 * This method is used to get the Y velocity of the ball.
 * @return  the Y velocity of the ball.
 */
int Ball::getYvelocity() {
  return yVelocity;
}

/**
 * This method is used to get the radius of the ball.
 * @return the radius of the ball.
 */
int Ball::getRadius() {
  return radius;
}

/**
 * This method is used to stop the ball from moving.
 */
void Ball::stopBall() {
  xVelocity = 0;
  yVelocity = 0;
}
/**
 * This method is used to move the ball once it is stopped.
 */
void Ball::moveBallAgain() {
  xVelocity = 3;
  yVelocity = 4;
}

