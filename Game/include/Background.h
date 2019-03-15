//
// Created by Rahul Ravindran on 2019-03-07.
//
#include <SDL.h>
#include "ResourceManager.h"
#ifndef LAB5_PLATFORMER_BACKGROUND1_H
#define LAB5_PLATFORMER_BACKGROUND1_H
/**
 * This Class is used to create the background for the game.
 */
class Background {
 public:

  /**
   * This is the contructor for the Background.
   **/
  Background();


  /**
   * This is the destructor for the game.
   */
   ~Background();

   /**
   * This is used to initialize the background.
   * @param x the x coordinate.
   * @param y the y coordinate.
   * @param ren the renderer.
   */
   void init(int x, int y);


  /**
   * This method is used to update the frame.
   */
  void update();

  /**
   * This is used to render the frame.
   * @param x the x coordinate.
   * @param y the y coordinate.
   * @param ren the renderer.
   */
  void render(int x, int y, SDL_Renderer *ren);

private:
    int xPos, yPos;
    int width, height;

  SDL_Texture *texture;
  SDL_Texture *texture2;
  SDL_Texture *texture3;
  SDL_Texture *texture4;

    ResourceManager* resourceManager;
//    SDL_Rect Src;
  SDL_Rect Dest;
};

#endif //LAB5_PLATFORMER_BACKGROUND1_H
