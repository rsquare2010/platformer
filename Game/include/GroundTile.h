//
// Created by Soumyadeep Sinha on 2019-03-11.
//

#ifndef PLATFORMER_SUNDAYS_ARE_FUNDAYS_GROUNDTILE_H
#define PLATFORMER_SUNDAYS_ARE_FUNDAYS_GROUNDTILE_H
#include "SDL.h"
#include "Coordinates.h"
#include "Draw.h"
#include <iostream>
#include <vector>
class GroundTile {

 public:

  ~GroundTile();

  void init(SDL_Renderer *render);
  void add(int x, int y);
  void render(int camX, SDL_Renderer* ren);
  std::vector<Coordinates *> getCoordinates();

 private:
  SDL_Surface *m_TileSpriteSheet;
  SDL_Texture *m_Texture;
  SDL_Rect Dest, Src;
  std::vector<Coordinates *> coordinates;

};

#endif //PLATFORMER_SUNDAYS_ARE_FUNDAYS_GROUNDTILE_H
