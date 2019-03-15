//
// Created by Rahul Ravindran on 2019-03-15.
//
#include "Character.h"



Character::Character(int startPosX, int startPosY ) {
    this->mPosX = startPosX;
    this->mPosY = startPosY;
    rmObj = ResourceManager::getInstance();
}

Character::~Character() {
    SDL_DestroyTexture(texture);
}

void Character::update(int frame){

    if(isIdle) {
        texture = (SDL_Texture *) rmObj->getValue("Idle");

        int currentFrame = frame%12;
        Src.x = currentFrame*19;
        Src.y = 0;
        Src.w = 19;
        Src.h = 31;
    } else {
        texture = (SDL_Texture *) rmObj->getValue("Run");
        int currentFrame = frame%7;
        Src.x = currentFrame*21;
        Src.y = 0;
        Src.w = 22;
        Src.h = 40;
    }
}

void Character::render(int camX, int camY, SDL_Renderer* ren, GroundTile* groundTile, std::vector<Enemy *> enemyArray) {

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
    if(isFacingLeft) {
        SDL_RenderCopyEx(ren, texture, &Src, &Dest, 0.0, NULL, SDL_FLIP_HORIZONTAL);
    } else {
        SDL_RenderCopy(ren, texture, &Src, &Dest);
    }
}

int Character::getPosX() {
    return futureX;
}

int Character::getPosY() {
    return mPosY;
}

void Character::handleEvent(SDL_Event& e) {

    const Uint8 * keystates =  SDL_GetKeyboardState( NULL );
    if( keystates[ SDL_SCANCODE_UP ] && keystates[ SDL_SCANCODE_RIGHT ])
    {
        isFacingLeft = false;
        jumpAndMoveToRight();
    }
    else if( keystates[ SDL_SCANCODE_UP ] && keystates[ SDL_SCANCODE_LEFT ])
    {
        isFacingLeft = true;
        jumpAndMoveToLeft();
    }

    else if(keystates[ SDL_SCANCODE_RIGHT ]){
        isFacingLeft = false;
        moveRight();

    } else if(keystates[ SDL_SCANCODE_LEFT ]) {
        isFacingLeft = true;
        moveLeft();
    } else if(keystates[ SDL_SCANCODE_UP ]){
        jump();
    } else {
        isIdle = true;
    }
}

void Character::moveLeft() {
    isIdle = false;
    futureX = mPosX - horizontalvelocity;
}

void Character::moveRight() {

    isIdle = false;

    futureX = mPosX + horizontalvelocity;

}

void Character::jump() {
    isIdle = false;
    if(isOnGround) {
        isOnGround = false;
        isJumping = true;

        horizontalvelocity = 0;
        jumpVelocity = 20;
        jumpStartTime = SDL_GetTicks();
    }

}

void Character::jumpAndMoveToRight() {
    isIdle = false;
    if(isOnGround) {
        isOnGround = false;
        isJumping = true;
        horizontalvelocity = 7;
        jumpVelocity = 20;
        jumpStartTime = SDL_GetTicks();
    }
}

void Character::jumpAndMoveToLeft() {
    isIdle = false;
    if(isOnGround) {
        isOnGround = false;
        isJumping = true;
        horizontalvelocity = -7;
        jumpVelocity = 20;
        jumpStartTime = SDL_GetTicks();
    }
}