//
// Created by Soumyadeep Sinha on 2019-03-11.
//

#include "../include/GroundTile.h"

/**
   * This is the destructor.
   */
GroundTile::~GroundTile() {
  SDL_FreeSurface(m_TileSpriteSheet);
  m_TileSpriteSheet = NULL;
  SDL_DestroyTexture(m_Texture);
}

/**
  * This is to initialize the Ground Tile.
  * @param render
  */

void GroundTile::init(SDL_Renderer *render) {
  m_TileSpriteSheet = SDL_LoadBMP("./media/Tiles.bmp");
  if (m_TileSpriteSheet==NULL) {
    SDL_Log("Failed to allocate surface");
  } else {
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

/**
   * This is used to add the Ground tile to the  Ground Array.
   * @param x the x coordinate.
   * @param y the y coordinate.
   */
void GroundTile::add(int x, int y) {
  this->coordinates.push_back(new Coordinates(x, y));
}

/**
  * This is to render the Ground tile.
  * @param camX the camera cx.
  * @param ren the renderer.
  */
void GroundTile::render(int camX, SDL_Renderer *ren) {

  for (int i = 0; i < coordinates.size(); i++) {
    Dest.x = coordinates[i]->getX() - camX;
    Dest.y = coordinates[i]->getY();
    Dest.w = 40;
    Dest.h = 40;
    SDL_RenderCopy(ren, m_Texture, NULL, &Dest);
  }
}

/**
  * This is used to retrieve the coordinate.
  * @return
  */
std::vector<Coordinates *> GroundTile::getCoordinates() {
  return coordinates;
}
