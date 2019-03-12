////
//// Created by Soumyadeep Sinha on 2019-01-27.
////
//
//#include "Collision.h"
//#include "Ball.h"
//#include "Wall.h"
//#include "Brick.h"
//#include "State.h"
//
///**
// * This is used to set up the screen height and with to detect the collision.
// * @param screenW the screen width.
// * @param screenH the screen height.
// */
//void Collision::setup(int screenW, int screenH) {
//  screenWidth = screenW;
//  screenHeight = screenH;
//}
//
///**
// * This method takes in the ball as a parameter and detects the collision with teh screen.
// * @param b  the ball.
// * @return returns true if there is a collision of the ball with the screen.
// */
//bool Collision::detectCollisionWithScreen(Ball *b) {
//
//  int x = b->getCoordinates()->getX() + b->getXvelocity();
//  int y = b->getCoordinates()->getY() + b->getYvelocity();
//  int ballRadius = b->getRadius();
//
//  if (x < 0) {
//    b->bounceInXDirection();
//
//  } else if (x + ballRadius > screenWidth) {
//    b->bounceInXDirection();
//  }
//
//  if (y < BNR_HGT + ballRadius) {
//    b->bounceInYDirection();
//  } else if (y + ballRadius >= screenHeight) {
//    return true;
//  }
//  return false;
//}
//
///**
// * This method is used to detect the collision of the ball with the bricks.
// * @param b the ball.
// * @param wall the wall.
// */
//void Collision::detectCollisionWithWallY(Ball *b, Wall *wall) {
//
//  //cout<<"checking wall Y\n";
//  Coordinates *coorBall = b->getCoordinates();
//
//  vector < Brick* > test = wall->returnWall();
//  int ballRadius = b->getRadius();
//
//  for (int i = 0; i < test.size(); i++) {
//
//    if (checkCollision(coorBall, ballRadius, ballRadius, test[i]->getCoordinates(), 20, 50)
//        && !(test[i]->getIsBroken())) {
//      wallCollision = true;
//
//      if (sideCollision) {
//        b->bounceInXDirection();
//      } else {
//        b->bounceInYDirection();
//      }
//
//      test[i]->setIsBroken(true);
//      State::getInstance().incrementScoreBy10();
//    }
//
//  }
//
//}
//
///**
// * This is used to detect the collision of any object with another object.
// * @param obj1  Coordinates of Object 1.
// * @param obj1Height object1 height.
// * @param obj1Width  object1 width.
// * @param obj2 Coordinates of object 2.
// * @param obj2Height object2 height.
// * @param obj2Width object2 width.
// * @return true if there is a collision else returns false.
// */
//
//bool sideCollision;
//bool checkCollision(Coordinates *obj1,
//                               int obj1Height,
//                               int obj1Width,
//                               Coordinates *obj2,
//                               int obj2Height,
//                               int obj2Width) {
//
//  sideCollision = false;
//  if (obj1->getY() + obj1Height < obj2->getY()) {
//
//    return false;
//  } else if (obj1->getY() > obj2->getY() + obj2Height) {
//
//    return false;
//  } else if (obj1->getX() + obj1Width < obj2->getX()) {
//    return false;
//  } else if (obj1->getX() > obj2->getX() + obj2Width) {
//    return false;
//  }
//
//  if (obj1->getX() + obj1Width - obj2->getX() < obj2->getX() + obj2Width - obj1->getX()
//      && obj1->getX() + obj1Width - obj2->getX() < obj1->getY() + obj1Height - obj2->getY()
//      && obj1->getX() + obj1Width - obj2->getX() < obj2->getY() + obj2Height - obj1->getY()) {
//    sideCollision = true;
//  }
//
//  if (obj2->getX() + obj2Width - obj1->getX() < obj1->getX() + obj1Width - obj2->getX()
//      && obj2->getX() + obj2Width - obj1->getX() < obj1->getY() + obj1Height - obj2->getY()
//      && obj2->getX() + obj2Width - obj1->getX() < obj2->getY() + obj2Height - obj1->getY()) {
//    sideCollision = true;
//  }
//
//  return true;
//}
//
///**
// * This is to check if there is a collision with the wall.
// * @return true if there is a collision else false.
// */
//bool Collision::getWallCollision() {
//  return wallCollision;
//}
//
///**
// * This method is used to reset the collision with the wall.
// */
//void Collision::resetWallCollision() {
//  wallCollision = false;
//}