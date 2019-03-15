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
class Enemy {
 public:

  static const int WIDTH = 43;
  static const int HEIGHT = 37;

  Enemy(SDL_Renderer* ren, int startPosX, int startPosY );
  ~Enemy();
  void update(int frame);
  void render(int camX, int camY, SDL_Renderer* ren, GroundTile* groundTile);
  int getPosX();
  int getPosY();
  void die();

 private:
  SDL_Surface *spriteSheet;
  SDL_Texture *texture;
  SDL_Renderer* ren;
  SDL_Rect Dest;
  SDL_Rect Src;
  int mPosX ;
  int mPosY ;
  int futureX;
  int futureY;
  int XVELOCITY = 1;
  int YVELOCITY = 5;
  Physix physix;
  bool dead = false;
  bool isDeadAnimationComplete = false;
  int deathFrame = 0;
  bool isFacingLeft = false;

};

#endif //PLATFORMER_SUNDAYS_ARE_FUNDAYS_ENEMY_H
