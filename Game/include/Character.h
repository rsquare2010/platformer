//
// Created by Rahul Ravindran on 2019-03-15.
//
#include "Rectangle.h"
#include "Physix.h"
#include "GroundTile.h"
#include "Enemy.h"
#include "ResourceManager.h"
#ifndef PLATFORMER_SUNDAYS_ARE_FUNDAYS_CHAR_H
#define PLATFORMER_SUNDAYS_ARE_FUNDAYS_CHAR_H
using namespace std;

class Character {
public:
    static const int WIDTH = 21;
    static const int HEIGHT = 33;


    Character(int startPosX, int startPosY );

    ~Character();

    void update(int frame);

    void render(int camX, int camY, SDL_Renderer* ren, GroundTile* groundTile, std::vector<Enemy *> enemyArray);

    int getPosX();

    int getPosY();

    void handleEvent(SDL_Event& e);

    void moveLeft();

    void moveRight();

    void jump();

    void jumpAndMoveToRight();

    void jumpAndMoveToLeft();

private:
    SDL_Texture *texture;
    SDL_Renderer *ren;
    SDL_Rect Dest;
    SDL_Rect Src;
    int mPosX = 10;
    int mPosY = 447;

    int futureX = 10;
    int futureY = 447;

    int gravity = 3;
    int jumpVelocity = 0;

    int jumpStartTime;
    int horizontalvelocity = 6;
    int verticalVelocity = 0;
    bool isOnGround = false;
    bool isJumping = false;
    bool isIdle = true;
    Physix physix;
    bool isFacingLeft = false;
    ResourceManager *rmObj;
};
#endif //PLATFORMER_SUNDAYS_ARE_FUNDAYS_CHAR_H
