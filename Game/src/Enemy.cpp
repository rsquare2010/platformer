//
// Created by Soumyadeep Sinha on 2019-03-13.
//

#include "../include/Enemy.h"

Enemy::Enemy(SDL_Renderer* ren, int startPosX, int startPosY ) {
    this->mPosX = startPosX;
    this->mPosY = startPosY;
    spriteSheet = SDL_LoadBMP("./media/enemy.bmp");
    if(spriteSheet==NULL) {
        SDL_Log("Failed to allocate surface");
    } else {
        // Create a texture from our surface
        // Textures run faster and take advantage of hardware acceleration
        texture = SDL_CreateTextureFromSurface(ren, spriteSheet);
    }
    this->ren = ren;
}

Enemy::~Enemy() {
    SDL_FreeSurface(spriteSheet);
    spriteSheet=NULL;
    SDL_DestroyTexture(texture);
}

void Enemy::update(int frame){
    int currentFrame = frame%17;
    Src.x = currentFrame*43;
    Src.y = 0;
    Src.w = WIDTH;
    Src.h = HEIGHT;
    if(dead) {
        deathFrame++;
        if(deathFrame <= 15) {
            Src.x = deathFrame*33;
            Src.y = 0;
            Src.w = 33;
            Src.h = 32;
        } else {
            isDeadAnimationComplete = true;
            Src.x = 0;
            Src.y = 0;
            Src.w = 0;
            Src.h = 0;
        }
    }
}

void Enemy::render(int camX, int camY, SDL_Renderer* ren, GroundTile* groundTile) {
    if (isDeadAnimationComplete) {
        return;
    }
    if(dead) {
        Dest.x = mPosX - camX;
        Dest.y = mPosY;
        Dest.w = 33;
        Dest.h = 32;

    }

    std::vector<Coordinates *> coordinates = groundTile->getCoordinates();

    futureX = mPosX + XVELOCITY;
    futureY = mPosY + YVELOCITY;

    if ( futureX < 0) {
        isFacingLeft = false;
        XVELOCITY = -XVELOCITY;
        futureX += XVELOCITY;
    }
    if ( futureX + WIDTH > 2560 )
    {
        isFacingLeft = true;
        XVELOCITY = -XVELOCITY;
        futureX += XVELOCITY;
    }
    int collision;
    Rectangle* enemy = new Rectangle(futureX, futureY, WIDTH, HEIGHT);
    for(int i = 0; i < coordinates.size(); i++) {
        Rectangle* tile = new Rectangle(coordinates[i]->getX(), coordinates[i]->getY(), 40,40);
        collision = physix.didCollide(enemy, tile);

        if(collision == 2) {
            isFacingLeft = !isFacingLeft;
            XVELOCITY = -XVELOCITY;
        }
        if(collision == 1) {
            futureY = mPosY;
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

int Enemy::getPosX() {
    return mPosX;
}

int Enemy::getPosY() {
    return mPosY;
}

void Enemy::die() {
    if(!dead) {
        spriteSheet = SDL_LoadBMP("./media/death.bmp");
        if(spriteSheet==NULL) {
            SDL_Log("Failed to allocate surface");
        } else {
            // Create a texture from our surface
            // Textures run faster and take advantage of hardware acceleration
            texture = SDL_CreateTextureFromSurface(ren, spriteSheet);
        }
        dead = true;
        XVELOCITY = 0;
    }
}