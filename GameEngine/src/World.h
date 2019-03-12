//
// Created by Soumyadeep Sinha on 2019-03-11.
//

#ifndef PLATFORMER_SUNDAYS_ARE_FUNDAYS_WORLD_H
#define PLATFORMER_SUNDAYS_ARE_FUNDAYS_WORLD_H

#include "SDL.h"
#include <iostream>
#include <fstream>
#include "GroundTile.h"
#include <vector>
#define TILE_SCR_WDT  1200
#define TILE_SCR_HGT  200
#define grid 20


using namespace std;
class World {


 public:
  World(SDL_Renderer *renderer){

    this->renderer = renderer;
    this->width = TILE_SCR_WDT/grid;
    this->height = TILE_SCR_HGT/grid;


    string line;
    ifstream myfile ("../media/example.txt");
    if (myfile.is_open())
    {
      getline (myfile,line);

      myfile.close();
    }

    else cout << "Unable to open file";


    int worldIndex = 0;
    for(int i =0;i<line.length();i++){

      if(isdigit(line.at(i))){
        this->worldArray[worldIndex] = line.at(i) - '0';
        worldIndex++;
      }

    }

  }


  void printWorld();

  void drawWorld();
  void loadArtifacts();
  vector<GroundTile *> returnGround();


 private:
  SDL_Renderer *renderer;
  int width;
  int height;
  int worldArray[(TILE_SCR_WDT/grid)*(TILE_SCR_HGT/grid)] = {};
  vector<GroundTile *> groundArray;


};

#endif //PLATFORMER_SUNDAYS_ARE_FUNDAYS_WORLD_H
