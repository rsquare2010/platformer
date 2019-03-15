//
// Created by Rahul Ravindran on 2019-03-15.
//
#include "Rectangle.h"
#ifndef PLATFORMER_SUNDAYS_ARE_FUNDAYS_PHYSIX_H
#define PLATFORMER_SUNDAYS_ARE_FUNDAYS_PHYSIX_H

class Physix {
public:
    static int didCollide(Rectangle *rect1, Rectangle *rect2) {
        if(rect1->overlap(rect2)) {
            Rectangle* intersection = rect1->intersect(rect2);
            if (intersection->getWidth() +2  > intersection->getHeight()) {
                return 1; //top collision
            } else {
                return 2; //side collision
            }
        } else {
            return 0; //no collision
        }

    }
};

#endif //PLATFORMER_SUNDAYS_ARE_FUNDAYS_PHYSIX_H
