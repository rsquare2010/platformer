//
// Created by Soumyadeep Sinha on 2019-03-11.
//

#include "World.h"
#include "Draw.h"
#include "WorldLayover.h"



void World::printWorld() {

  for(int i =0;i<this->width * this->height;i++){
    cout<<this->worldArray[i]<<", ";
  }

}


void World::loadArtifacts() {

  int scaleFactor = 2;
  SDL_Rect dstrect;
  WorldLayover *wl = new WorldLayover(renderer, TILE_SCR_WDT*scaleFactor, TILE_SCR_HGT*scaleFactor);

  for (int i = 0; i < TILE_SCR_HGT/grid; i++) {

    for (int j = 0; j < TILE_SCR_WDT/grid; j++) {

      int rectGrid = ((TILE_SCR_WDT/grid)*(i)) + (j);

      int x = wl->getCoordinate(rectGrid)->getX();
      int y = wl->getCoordinate(rectGrid)->getY();

      dstrect = {x, y, 20*scaleFactor, 20*scaleFactor};

      if (worldArray[rectGrid]==1) {

      } else if (worldArray[rectGrid]==3) {
        this->groundArray.push_back(new GroundTile(renderer, wl->getCoordinate(rectGrid)->getX(), wl->getCoordinate(rectGrid)->getY()));

      }

    }

  }
}


void World::drawWorld() {


}

vector<GroundTile *> World::returnGround() {

  return this->groundArray;

}
