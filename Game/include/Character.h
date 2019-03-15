//
// Created by Rahul Ravindran on 2019-03-15.
//
#include "Rectangle.h"
#include "Physix.h"
#include "GroundTile.h"
#include "Enemy.h"
#ifndef PLATFORMER_SUNDAYS_ARE_FUNDAYS_CHAR_H
#define PLATFORMER_SUNDAYS_ARE_FUNDAYS_CHAR_H
using namespace std;

/**
 * This is the character of the game.
 */
class Character {

 public:
  static const int WIDTH = 21;
  static const int HEIGHT = 33;

 public:
  static const int WIDTH = 21;
  static const int HEIGHT = 33;

  /**
    * This is the constructor.
    * @param ren the renderer.
    * @param startPosX the x position.
    * @param startPosY the y position.
    */
  Character(SDL_Renderer *ren, int startPosX, int startPosY);

  /**
 * This is the destructor of the game.
 */
  ~Character();

  /**
* This method is used to update the frame.
* @param frame the frame rate.
*/
  void update(int frame);
  /**
   * This method is used to render the character.
   * @param camX the camera x.
   * @param camY the camera y.
   * @param ren the renderer.
   * @param groundTile the ground tiles.
   * @param enemyArray the enemy array.
   */
  void render(int camX, int camY, SDL_Renderer *ren, GroundTile *groundTile, std::vector<Enemy *> enemyArray);

  /**
* This is used to get the character x position.
* @return the x position.
*/
  int getPosX();
  /**
 * This is used to get the character y position.
 * @return the y position.
 */

  int getPosY();

/**
 * This is used to handle the movements of the character.
 * @param e the event.
 */
  void handleEvent(SDL_Event &e);

  /**
 * This is used to move left.
 */

  void moveLeft();
  /**
 * This method is used to move right.
 */

  void moveRight();

  /**
 * This method is used to jump.
 */

  void jump();

  /**
 * This method is used to jump right.
 */
  void jumpAndMoveToRight();
  /**
 * This method is used to jump left.
 */

  void jumpAndMoveToLeft();

 private:
  SDL_Surface *spriteSheet;
  SDL_Surface *idleSprite;
  SDL_Texture *texture;
  SDL_Renderer *ren;
  SDL_Rect Dest;
  SDL_Rect Src;
  int mPosX = 10;
  int mPosY = 447;

  int futureX = 10;
  int futureY = 447;

  int gravity = 3;
  int jumpVelocity = 0;

  int jumpStartTime;
  int horizontalvelocity = 6;
  bool isOnGround = false;
  bool isJumping = false;
  bool isIdle = true;
  Physix physix;
  bool isFacingLeft = false;

};
#endif //PLATFORMER_SUNDAYS_ARE_FUNDAYS_CHAR_H
