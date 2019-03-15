//
// Created by Rahul Ravindran on 2019-03-15.
//
#include "Rectangle.h"
#include "Physix.h"
#ifndef PLATFORMER_SUNDAYS_ARE_FUNDAYS_CHAR_H
#define PLATFORMER_SUNDAYS_ARE_FUNDAYS_CHAR_H
using namespace std;

class Char {
public:
    static const int WIDTH = 21;
    static const int HEIGHT = 33;

    Char(SDL_Renderer* ren, int startPosX, int startPosY) {
        this->mPosX = startPosX;
        this->mPosY = startPosY;


        spriteSheet = SDL_LoadBMP("./Run.bmp");
        if (spriteSheet == NULL) {
            SDL_Log("Failed to allocate surface");
        } else {
            SDL_Log("Allocated a bunch of memory to create identical game character");
            // Create a texture from our surface
            // Textures run faster and take advantage of hardware acceleration
            texture = SDL_CreateTextureFromSurface(ren, spriteSheet);
        }
    }
    ~Char() {
        SDL_FreeSurface(spriteSheet);
        spriteSheet=NULL;
        SDL_DestroyTexture(texture);
    }

    void update(int frame){
        int currentFrame = frame%7;
        Src.x = currentFrame*21;
        Src.y = 0;
        Src.w = 22;
        Src.h = 40;
    }


    void render(int camX, int camY, SDL_Renderer* ren, GroundTile* groundTile, vector<Enemy* > enemyArray) {


        std::vector<Coordinates *> coordinates = groundTile->getCoordinates();

        if(isJumping) {
            int currentTime = SDL_GetTicks();
            if( currentTime < jumpStartTime + 500) {
                float time = ((currentTime -jumpStartTime)/1000);
                futureX = mPosX + horizontalvelocity;
                futureY = mPosY - jumpVelocity;
                jumpVelocity -= gravity;
            }

        } else{
            futureY = mPosY + 1;
        }



        if(futureX+WIDTH > 2560) {
            futureX = 2560 - WIDTH;
        }
        if (futureX < 0) {
            futureX = 0;
        }

        int collision;
        Rectangle* character = new Rectangle(futureX, futureY, WIDTH, HEIGHT);

        for (int i=0; i< enemyArray.size(); i++) {
            Rectangle* enemy = new Rectangle(enemyArray[i]->getPosX(), enemyArray[i]->getPosY(), 43, 37);
            collision = physix.didCollide(character, enemy);

            if(collision == 2) {
                //loseLife
            }
            if(collision == 1) {
                enemyArray[i]->die();
            }
        }



        for(int i = 0; i < coordinates.size(); i++) {
            Rectangle* tile = new Rectangle(coordinates[i]->getX(), coordinates[i]->getY(), 40,40);
            collision = physix.didCollide(character, tile);

            if(collision == 2) {
                    futureX = mPosX;
                    futureY = mPosY;
                    isJumping = false;
                    jumpVelocity = 0;
                    horizontalvelocity = 6;
            }
            if(collision == 1) {
                futureY = mPosY;
                isOnGround = true;
                isJumping = false;
                jumpVelocity = 0;
                horizontalvelocity = 6;
            }

        }
        mPosX = futureX;
        mPosY = futureY;
        Dest.x = mPosX - camX;
        Dest.y = mPosY;
        Dest.w = WIDTH;
        Dest.h = HEIGHT;
        SDL_RenderCopy(ren, texture, &Src, &Dest);
    }

    int getPosX() {
        return futureX;
    }

    int getPosY() {
        return mPosY;
    }

    void handleEvent(SDL_Event& e) {
        //If a key was pressed
//        if( e.type == SDL_KEYDOWN)
//        {
//            //Adjust the velocity
//            switch( e.key.keysym.sym )
//            {
//                case SDLK_LEFT:
//                    moveLeft();break;
//                case SDLK_RIGHT:
//                        moveRight();
//                     break;
//
//
//                //case SDLK_UP:  jump(); break;
//            }
//        }

        const Uint8 * keystates =  SDL_GetKeyboardState( NULL );
        if( keystates[ SDL_SCANCODE_UP ] && keystates[ SDL_SCANCODE_RIGHT ])
        {
            jumpAndMoveToRight();
        }
        else if( keystates[ SDL_SCANCODE_UP ] && keystates[ SDL_SCANCODE_LEFT ])
        {
            jumpAndMoveToLeft();
        }

        else if(keystates[ SDL_SCANCODE_RIGHT ]){

            moveRight();

        } else if(keystates[ SDL_SCANCODE_LEFT ]) {
            moveLeft();
        } else if(keystates[ SDL_SCANCODE_UP ]){
            jump();
        }
    }

    void moveLeft() {
        futureX = mPosX - horizontalvelocity;
    }

    void moveRight() {

        futureX = mPosX + horizontalvelocity;

    }

    void jump() {
        if(isOnGround) {
            isOnGround = false;
            isJumping = true;



            //physix.didCollide();
            //update x;
            //update y;
            horizontalvelocity = 0;
            jumpVelocity = 20;
            jumpStartTime = SDL_GetTicks();
        }

    }

    void jumpAndMoveToRight() {
        if(isOnGround) {
            isOnGround = false;
            isJumping = true;
            horizontalvelocity = 7;
            jumpVelocity = 20;
            jumpStartTime = SDL_GetTicks();
        }
    }

    void jumpAndMoveToLeft() {
        if(isOnGround) {
            isOnGround = false;
            isJumping = true;
            horizontalvelocity = -7;
            jumpVelocity = 20;
            jumpStartTime = SDL_GetTicks();
        }
    }

private:
    SDL_Surface *spriteSheet;
    SDL_Texture *texture;
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
    bool isOnGround = false;
    bool isJumping = false;
    Physix physix;



};
#endif //PLATFORMER_SUNDAYS_ARE_FUNDAYS_CHAR_H
