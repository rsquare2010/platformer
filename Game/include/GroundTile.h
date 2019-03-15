//
// Created by Soumyadeep Sinha on 2019-03-11.
//

#ifndef PLATFORMER_SUNDAYS_ARE_FUNDAYS_GROUNDTILE_H
#define PLATFORMER_SUNDAYS_ARE_FUNDAYS_GROUNDTILE_H
#include "SDL.h"
#include "Coordinates.h"
#include "ResourceManager.h"
#include <iostream>
#include <vector>


/**
 * This class represents every ground Tile.
 */
class GroundTile {

 public:


  /**
   * This is the destructor.
   */

  ~GroundTile();

  /**
   * This is to initialize the Ground Tile.
   */
  void init();



  /**
   * This is used to add the Ground tile to the  Ground Array.
   * @param x the x coordinate.
   * @param y the y coordinate.
   */
  void add(int x, int y);

  /**
   * This is to render the Ground tile.
   * @param camX the camera cx.
   * @param ren the renderer.
   */
  void render(int camX, SDL_Renderer* ren);

  /**
   * This is used to retrieve the coordinate.
   * @return
   */
  std::vector<Coordinates *> getCoordinates();






 private:
  SDL_Texture *m_Texture;
  SDL_Rect Dest, Src;
  std::vector<Coordinates *> coordinates;
  ResourceManager* resourceManager;
};

#endif //PLATFORMER_SUNDAYS_ARE_FUNDAYS_GROUNDTILE_H
