//
// Created by Soumyadeep Sinha on 2019-03-11.
//

#ifndef PLATFORMER_SUNDAYS_ARE_FUNDAYS_WORLD_H
#define PLATFORMER_SUNDAYS_ARE_FUNDAYS_WORLD_H

#include "SDL.h"
#include <iostream>
#include <fstream>
#include "GroundTile.h"
#include "Enemy.h"
#include "Char.h"
//#include "Charactersss.h"
#include <vector>


using namespace std;
class World {


 public:
  World(SDL_Renderer *renderer);

  void printWorld();

  void loadArtifacts(GroundTile* groundTile);

  vector<Enemy *> returnEnemies();

  Character*  returnCharacter();

 private:
  SDL_Renderer *renderer;
  //int worldArray[600] = {};

  vector<int> worldArray;
  int x, y;
  int rectGrid;

  vector<Enemy *> enemyArray;
  Char* character;


};

#endif //PLATFORMER_SUNDAYS_ARE_FUNDAYS_WORLD_H
