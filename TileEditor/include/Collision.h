//
// Created by Soumyadeep Sinha on 2019-01-27.
//

#ifndef BREAKOUT_BREAKOUTSQUAD_COLLISION_H
#define BREAKOUT_BREAKOUTSQUAD_COLLISION_H
#include "Ball.h"
#include "Wall.h"

/**
 * This class is used to detect collision.
 */
class Collision {
 public:
  /**
   * This method is used to get the instance of the collision.
   * @return the collision object.
   */
  static Collision &getInstance() {
    static Collision *instance = new Collision();
    return *instance;
  }

  /**
   * This is used to set up the screen height and with to detect the collision.
   * @param screenW the screen width.
   * @param screenH the screen height.
   */
  void setup(int screenW, int screenH);
  /**
   * This method takes in the ball as a parameter and detects the collision with teh screen.
   * @param b  the ball.
   * @return returns true if there is a collision of the ball with the screen.
   */
  bool detectCollisionWithScreen(Ball *b);
  /**
   * This method is used to detect the collision of the ball with the bricks.
   * @param b the ball.
   * @param wall the wall.
   */
  void detectCollisionWithWallY(Ball *b, Wall *wall);
  /**
   * This is used to detect the collision of any object with another object.
   * @param obj1  Coordinates of Object 1.
   * @param obj1Height object1 height.
   * @param obj1Width  object1 width.
   * @param obj2 Coordinates of object 2.
   * @param obj2Height object2 height.
   * @param obj2Width object2 width.
   * @return true if there is a collision else returns false.
   */
  bool checkCollision(Coordinates *obj1,
                      int obj1Height,
                      int obj1Width,
                      Coordinates *obj2,
                      int obj2Height,
                      int obj2Width);

  /**
   * This is to check if there is a collision with the wall.
   * @return true if there is a collision else false.
   */
  bool getWallCollision();
  /**
   * This method is used to reset the collision with the wall.
   */
  void resetWallCollision();
 private:
  Collision() {};
  bool wallCollision = false;
  bool sideCollision;
  int screenWidth;
  int screenHeight;

};

#endif //BREAKOUT_BREAKOUTSQUAD_COLLISION_H
