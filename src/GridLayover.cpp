//
// Created by Soumyadeep Sinha on 2019-02-17.
//

#include "../include/GridLayover.h"

void GridLayover::draw(){


int hightTracker = 0;
for(int i=0;i<scH;i = i+50) {


  for (int j = 0; j < scW; j = j + 50) {

    hightTracker++;
    Rectangle *a = new Rectangle(this->ren, j, i, 49, 49);
    a->draw();

  }
}








}

Coordinates* GridLayover::getCoordinate(int a){

  return gridLayout[a];

}


