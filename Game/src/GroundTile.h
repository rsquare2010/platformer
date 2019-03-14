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
  GroundTile(){
  }

  void init(SDL_Renderer *render) {
      m_TileSpriteSheet = SDL_LoadBMP("./Tiles.bmp");
      if(m_TileSpriteSheet==NULL){
          SDL_Log("Failed to allocate surface");
      }else{
          // Create a texture from our surface
          // Textures run faster and take advantage of
          //  hardware acceleration
          m_Texture = SDL_CreateTextureFromSurface(render, m_TileSpriteSheet);
      }
      Src.x = 0;
      Src.y = 0;
      Src.w = 40;
      Src.h = 40;
  }

  void add(int x, int y) {
//      Coordinates* coords = ;
    this->coordinates.push_back(new Coordinates( x, y));
  }

  void render(int camX, SDL_Renderer* ren) {

      for (int i = 0; i < coordinates.size(); i++) {
          Dest.x = coordinates[i]->getX() - camX;
          Dest.y = coordinates[i]->getY();
          Dest.w = 40;
          Dest.h = 40;
          SDL_RenderCopy(ren, m_Texture, &Src, &Dest);
      }
  }

  std::vector<Coordinates *> getCoordinates() {
    return coordinates;
  }

 private:
  SDL_Surface *m_TileSpriteSheet;
  SDL_Texture *m_Texture;
  SDL_Rect Dest, Src;
  std::vector<Coordinates *> coordinates;

};

#endif //PLATFORMER_SUNDAYS_ARE_FUNDAYS_GROUNDTILE_H
