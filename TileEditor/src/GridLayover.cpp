//
// Created by Soumyadeep Sinha on 2019-02-17.
//

#include "../include/GridLayover.h"

void GridLayover::draw(){


int hightTracker = 0;
for(int i=0;i<scH;i = i+grid) {


  for (int j = 0; j < scW; j = j + grid) {

    hightTracker++;
    Rectangle *a = new Rectangle(this->ren, j, i, grid-1, grid-1);
    a->updateColor(159, 193, 249,255);
    a->draw();

  }
}








}

Coordinates* GridLayover::getCoordinate(int a){

  return gridLayout[a];

}


