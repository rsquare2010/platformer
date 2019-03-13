//
// Created by Soumyadeep Sinha on 2019-03-13.
//

#ifndef PLATFORMER_SUNDAYS_ARE_FUNDAYS_ENEMY_H
#define PLATFORMER_SUNDAYS_ARE_FUNDAYS_ENEMY_H
#include "SDL.h"
class Enemy {
 public:

  static const int WIDTH = 21;
  static const int HEIGHT = 33;

  Enemy(SDL_Renderer* ren, int startPosX, int startPosY ) {
    this->mPosX = startPosX;
    this->mPosY = startPosY;
    spriteSheet = SDL_LoadBMP("./run.bmp");
    if(spriteSheet==NULL) {
      SDL_Log("Failed to allocate surface");
    } else {
      SDL_Log("Allocated a bunch of memory to create identical game character");
      // Create a texture from our surface
      // Textures run faster and take advantage of hardware acceleration
      texture = SDL_CreateTextureFromSurface(ren, spriteSheet);
    }
  }


  ~Enemy() {
    SDL_FreeSurface(spriteSheet);
    spriteSheet=NULL;
    SDL_DestroyTexture(texture);
  }

  void init() {

  }





  void handleEvent(SDL_Event& e) {



//    const Uint8 * keystates =  SDL_GetKeyboardState( NULL );
//    if( keystates[ SDL_SCANCODE_UP ] && keystates[ SDL_SCANCODE_RIGHT ])
//    {
//      jump();
//      moveRight();
//    }
//    else if( keystates[ SDL_SCANCODE_UP ] && keystates[ SDL_SCANCODE_LEFT ])
//    {
//      jump();
//      moveLeft();
//    }
//
//    else if(keystates[ SDL_SCANCODE_RIGHT ]){
//      moveRight();
//    } else if(keystates[ SDL_SCANCODE_LEFT ]) {
//      moveLeft();
//    } else if(keystates[ SDL_SCANCODE_UP ]){
//      jump();
//    }




  }

  void moveRight() {


    mPosX +=XVELOCITY;


  }


  void moveLeft() {

    mPosX -= XVELOCITY;


  }

  void move(){
    if ( mPosX < 0) {
      mPosX +=XVELOCITY;
    }
    if ( mPosX + WIDTH > 2560 )
    {
      //Move back
      mPosX -= XVELOCITY;
    }

    moveRight();



  }

  void startFalling() {
    mPosY += YVELOCITY;
  }


  void stopMovingInXDir(){
    XVELOCITY = -XVELOCITY;
  }

  void startMovingInXDir(){
    XVELOCITY = 25;
  }


  void jump(){
    mPosY -= 33;
  }


  void update(int frame){
    int currentFrame = frame;
    if(currentFrame>7){
      currentFrame=0;
    }
    Src.x = currentFrame*21;
    Src.y = 0;
    Src.w = 21;
    Src.h = 33;

    move();
  }


  void render(int camX, int camY, SDL_Renderer* ren) {
    Dest.x = mPosX - camX;
    Dest.y = mPosY;
    Dest.w = WIDTH;
    Dest.h = HEIGHT;

    SDL_RenderCopy(ren, texture, &Src, &Dest);
  }

  int getPosX() {
    return mPosX;
  }

  int getPosY() {
    return mPosY;
  }
 private:
  SDL_Surface *spriteSheet;
  SDL_Texture *texture;
  SDL_Rect Dest;
  SDL_Rect Src;
  int mPosX ;
  int mPosY ;
  int XVELOCITY = 25;
  int YVELOCITY = 20;

};

#endif //PLATFORMER_SUNDAYS_ARE_FUNDAYS_ENEMY_H
