//
// Created by Rahul Ravindran on 2019-03-14.
//

#ifndef PLATFORMER_SUNDAYS_ARE_FUNDAYS_SPRITE_H
#define PLATFORMER_SUNDAYS_ARE_FUNDAYS_SPRITE_H

#include "ResourceManager.h"
/**
 * This is a Sprite class object.
 */
class Sprite {
 public:

  /**
   * This is the constructor.
   * @param width the width.
   * @param height the height.
   * @param x the x coordinate.
   * @param y the y coordinate.
   * @param number the number.
   */
  Sprite(int width, int height, int x, int y, int number);

  /**
   * This is the destructor.
   */
  ~Sprite();

  /**
   * This is to initialize the sprite object.
   * @param ren the renderer.
   */
  void init(SDL_Renderer *ren);

  /**
   * This is to update the sprite object.
   * @param frame the frame rate.
   */
  void update(int frame);
  /**
   * This is to render the sprite object.
   * @param ren the renderer.
   */

  void render(SDL_Renderer *ren);

 private:
  int xPos, yPos;
  int width, height;
  int count;
  unsigned int currentFrame{0};
  unsigned int yFrame{0};
  unsigned int LastFrame{7};
  // An SDL Surface contains pixel data to draw an image
  SDL_Texture *texture;

  SDL_Rect Src;
  SDL_Rect Dest;
};
#endif //PLATFORMER_SUNDAYS_ARE_FUNDAYS_SPRITE_H
