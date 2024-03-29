//
// Created by Rahul Ravindran on 2019-03-15.
//
#include "Rectangle.h"
#include "Physix.h"
#include "GroundTile.h"
#include "Enemy.h"
#include "ResourceManager.h"
#include <vector>
#ifndef PLATFORMER_SUNDAYS_ARE_FUNDAYS_CHAR_H
#define PLATFORMER_SUNDAYS_ARE_FUNDAYS_CHAR_H
using namespace std;

/**
 * This is the character of the game.
 */
class Character {

public:
    static const int WIDTH = 21;
    static const int HEIGHT = 33;


    /**
      * This is the constructor.
      * @param startPosX the x position.
      * @param startPosY the y position.
      */
    Character(int startPosX, int startPosY);

    /**
   * This is the destructor of the game.
   */
    ~Character();

    /**
  * This method is used to update the frame.
  * @param frame the frame rate.
  */
    void update(int frame);

    /**
     * This method is used to render the character.
     * @param camX the camera x.
     * @param camY the camera y.
     * @param ren the renderer.
     * @param groundTile the ground tiles.
     * @param enemyArray the enemy array.
     */
    void render(int camX, int camY, SDL_Renderer *ren);

    /**
  * This is used to get the character x position.
  * @return the x position.
  */
    int getPosX();

    /**
   * This is used to get the character y position.
   * @return the y position.
   */
    int getPosY();

/**
 * This is used to handle the movements of the character.
 * @param e the event.
 */
    void handleEvent(SDL_Event &e);

    /**
   * This is used to move left.
   */
    void moveLeft();

    /**
   * This method is used to move right.
   */
    void moveRight();

    /**
   * This method is used to jump.
   */
    void jump();

    /**
   * This method is used to jump right.
   */
    void jumpAndMoveToRight();

    /**
   * This method is used to jump left.
   */
    void jumpAndMoveToLeft();

    int getRemainingLives();

    bool getWinStatus();

    void setGroundTile(GroundTile *gt) {
      this->groundTile = gt;
    }

    void setEnemyArray(vector<Enemy *> enAr) {
      this->enemyArray = enAr;
    }

    int getScreenHeight() {
      return screenHeight;
    }

    void setScreenHeight(int s) {
      this->screenHeight = s;
    }

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
    int lives;
    bool hasWon = false;
    bool hasLost = false;
    GroundTile *groundTile;
    vector<Enemy *> enemyArray;
    int screenHeight;

};
#endif //PLATFORMER_SUNDAYS_ARE_FUNDAYS_CHAR_H
