//
// Created by Soumyadeep Sinha on 2019-03-11.
//

#include "../include/World.h"



World::World(SDL_Renderer *renderer){

  this->renderer = renderer;
  string line;
  ifstream myfile ("../TileEditor/media/example.txt");
  if (myfile.is_open()) {
      getline (myfile,line);
      myfile.close();
  }
  else cout << "Unable to open file";

  //int worldIndex = 0;
  for(int i =0;i<line.length();i++) {

    if(isdigit(line.at(i))){
      //this->worldArray[worldIndex] = line.at(i) - '0';
      this->worldArray.push_back(line.at(i) - '0');
      //worldIndex++;
    }
  }
}


void World::loadArtifacts(GroundTile* groundTile) {

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

        enemyArray.push_back(new Enemy(x, y));

      }
      if(worldArray[rectGrid] == 1){
        character = new Character(x,y);
      }
      else if (worldArray[rectGrid] == 3) {
        groundTile->add(x, y);
      }
    }
  }


}

void World::printWorld() {

  for(int i =0;i < 400;i++){
    cout<<this->worldArray[i]<<", ";
  }

}

vector<Enemy *> World::returnEnemies() {

  return this->enemyArray;

}

Character*  World::returnCharacter(){
  return  this->character;
}
