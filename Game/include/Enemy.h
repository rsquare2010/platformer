//
// Created by Soumyadeep Sinha on 2019-03-13.
//

#ifndef PLATFORMER_SUNDAYS_ARE_FUNDAYS_ENEMY_H
#define PLATFORMER_SUNDAYS_ARE_FUNDAYS_ENEMY_H
#include "SDL.h"
#include "Rectangle.h"
#include "Physix.h"
#include "GroundTile.h"
#include "Coordinates.h"
#include "ResourceManager.h"

/**
 * This is the Enemy class.
 */
class Enemy {
 public:

  static const int WIDTH = 43;
  static const int HEIGHT = 37;

  /**
  * This is the constructor.
  * @param ren the renderer.
  * @param startPosX the start of X position.
  * @param startPosY the start of Y position.
  */
  Enemy( int startPosX, int startPosY);

  /**
   * This is the destructor.
   */
  ~Enemy();

  /**
 * This method is used to update the frame.
 * @param frame the frame rate.
 */
  void update(int frame);

  /**
   * This method is used to render the Enemy.
   * @param camX the camera X position.
   * @param camY the camera Y position.
   * @param ren the renderer.
   * @param groundTile the ground Tile.
   */
  void render(int camX, int camY, SDL_Renderer *ren, GroundTile *groundTile);

  /**
  * This is used get the X position of the enemy.
  * @return
  */
  int getPosX();

  /**
   * This is to get the Y position of the Enemy.
   * @return
   */
  int getPosY();

  /**
   * This is to render the animation when the enemy is dead.
   */
  void die();

 private:
  SDL_Texture *texture;
  SDL_Rect Dest;
  SDL_Rect Src;
  int mPosX;
  int mPosY;
  int futureX;
  int futureY;
  int XVELOCITY = 1;
  int YVELOCITY = 5;
  Physix physix;
  bool dead = false;
  bool isDeadAnimationComplete = false;
  int deathFrame = 0;
  bool isFacingLeft = false;
  ResourceManager* resourceManager;

};

#endif //PLATFORMER_SUNDAYS_ARE_FUNDAYS_ENEMY_H
