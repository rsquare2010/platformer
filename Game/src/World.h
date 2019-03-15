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
  World(SDL_Renderer *renderer){

    this->renderer = renderer;


    string line;
    ifstream myfile ("../TileEditor/media/example.txt");
    if (myfile.is_open())
    {
      getline (myfile,line);

      myfile.close();
    }

    else cout << "Unable to open file";


    //int worldIndex = 0;
    for(int i =0;i<line.length();i++){

      if(isdigit(line.at(i))){
        //this->worldArray[worldIndex] = line.at(i) - '0';
        this->worldArray.push_back(line.at(i) - '0');
        //worldIndex++;
      }

    }

  }


  void printWorld();

//  void drawWorld();
  void loadArtifacts(GroundTile* groundTile) {

      int scaleFactor = 2;
      SDL_Rect dstrect;

      int numberOfGridHeight = 15;
      int numberOfGridWidth = 64;



      for (int i = 0; i < numberOfGridHeight; i++) {

          for (int j = 0; j < numberOfGridWidth; j++) {

              rectGrid = (numberOfGridWidth * (i)) + (j);

              x = j * 40;
              y = i * 40;

              dstrect = {x, y, 40, 40};

              if (worldArray[rectGrid] == 2) {

                enemyArray.push_back(new Enemy(renderer, x, y));

              }
              if(worldArray[rectGrid] == 1){
                character = new Character(renderer,x,y);
              }
              else if (worldArray[rectGrid] == 3) {
                    groundTile->add(x, y);

              }

          }
      }
  }


  vector<Enemy *> returnEnemies() {

    return this->enemyArray;

  }

  Character*  returnCharacter(){
    return  this->character;
  }


 private:
  SDL_Renderer *renderer;
  //int worldArray[600] = {};

  vector<int> worldArray;
  int x, y;
  int rectGrid;

  vector<Enemy *> enemyArray;
  Character* character;


};

#endif //PLATFORMER_SUNDAYS_ARE_FUNDAYS_WORLD_H
