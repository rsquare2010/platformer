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
#include "Character.h"
#include <vector>

using namespace std;
class World {

 public:
  /**
 * This is the constructor of the world.
 * @param renderer
 */
  World(SDL_Renderer *renderer);

  /**
 * This is used to print the world..
 */
  void printWorld();

  /**
 * This is used to read from the output of the tile editor and  load the contents of the game.
 * @param groundTile takes in ground tile.
 */
  void loadArtifacts(GroundTile *groundTile);

  /**
 * This method is used to return the enemy array.
 * @return the array of enemies.
 */
  vector<Enemy *> returnEnemies();

  /**
 * This method is used to return the character.
 * @return the character.
 */
  Character *returnCharacter();

 private:
  SDL_Renderer *renderer;
  vector<int> worldArray;
  int x, y;
  int rectGrid;

  vector<Enemy *> enemyArray;
  Character *character;

};

#endif //PLATFORMER_SUNDAYS_ARE_FUNDAYS_WORLD_H
