//
// Created by Rahul Ravindran on 2019-03-07.
//

#ifndef LAB5_PLATFORMER_CHARACTER_H
#define LAB5_PLATFORMER_CHARACTER_H
#include "SDL.h"

class Character {
public:

    static const int WIDTH = 22;
    static const int HEIGHT = 40;

    Character(SDL_Renderer* ren, int startPosX, int startPosY ) {
    this->mPosX = startPosX;
    this->mPosY = startPosY;
    spriteSheet = SDL_LoadBMP("./Run.bmp");
    if(spriteSheet==NULL) {
      SDL_Log("Failed to allocate surface");
    } else {
      SDL_Log("Allocated a bunch of memory to create identical game character");
      // Create a texture from our surface
      // Textures run faster and take advantage of hardware acceleration
      texture = SDL_CreateTextureFromSurface(ren, spriteSheet);
    }
  }


    ~Character() {
        SDL_FreeSurface(spriteSheet);
        spriteSheet=NULL;
        SDL_DestroyTexture(texture);
    }

    void init(SDL_Renderer* ren) {

    }


    void handleEvent(SDL_Event& e) {
        //If a key was pressed
//        if( e.type == SDL_KEYDOWN)
//        {
//            //Adjust the velocity
//            switch( e.key.keysym.sym )
//            {
//                case SDLK_LEFT: moveLeft(); break;
//                case SDLK_RIGHT:
//                    moveRight();
//                    break;
//
//
//                //case SDLK_UP:  jump(); break;
//            }
//        }


        const Uint8 * keystates =  SDL_GetKeyboardState( NULL );
        if( keystates[ SDL_SCANCODE_UP ] && keystates[ SDL_SCANCODE_RIGHT ])
        {
           jump();
           moveRight();
        }
        else if( keystates[ SDL_SCANCODE_UP ] && keystates[ SDL_SCANCODE_LEFT ])
        {
            jump();
            moveLeft();
        }

        else if(keystates[ SDL_SCANCODE_RIGHT ]){
            moveRight();
        } else if(keystates[ SDL_SCANCODE_LEFT ]) {
            moveLeft();
        } else if(keystates[ SDL_SCANCODE_UP ]){
            jump();
        }




    }

    void moveRight() {

      if ( mPosX >= 0 && mPosX <2560 && mPosY < 640) {


        mPosX +=XVELOCITY;
      }


    }


  void moveLeft() {

    if ( mPosX >= 0 && mPosX <2560 && mPosY < 640)
    {
      //Move back
      mPosX -= XVELOCITY;
    }


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

    }

    void startFalling() {
        mPosY += YVELOCITY;
    }


  void stopMovingInXDir(){
      XVELOCITY = 0;
  }

  void startMovingInXDir(){
      XVELOCITY = 40;
  }


  void jump(){
      if(this->canJumpFlag){



        mPosY -= JUMP_VELOCITY;

      }

    }


    void cantJump(){
      canJumpFlag = false;
    }

    void canJump(){
      canJumpFlag = true;
    }


    void update(int frame){
        int currentFrame = frame;
        if(currentFrame>7){
            currentFrame=0;
        }
        Src.x = currentFrame*21;
        Src.y = 0;
        Src.w = 22;
        Src.h = 40;

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
    int mPosX = 10;
    int mPosY = 100;
    int XVELOCITY = 40;
    int YVELOCITY = 40;
    bool canJumpFlag = true;
    bool currentlyJumping = false;
    int JUMP_VELOCITY = 40*2;
};
#endif //LAB5_PLATFORMER_CHARACTER_H
