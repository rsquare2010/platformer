//
// Created by Rahul Ravindran on 2019-03-07.
//

#ifndef LAB5_PLATFORMER_CHARACTER_H
#define LAB5_PLATFORMER_CHARACTER_H
class Character {
public:

    static const int WIDTH = 21;
    static const int HEIGHT = 33;

    Character() {
    }


    ~Character() {
        SDL_FreeSurface(spriteSheet);
        spriteSheet=NULL;
        SDL_DestroyTexture(texture);
    }

    void init(SDL_Texture* charTexture) {
//        spriteSheet = SDL_LoadBMP("./run.bmp");
//        if(spriteSheet==NULL) {
//            SDL_Log("Failed to allocate surface");
//        } else {
//            SDL_Log("Allocated a bunch of memory to create identical game character");
//            // Create a texture from our surface
//            // Textures run faster and take advantage of hardware acceleration
        if(charTexture != NULL) {
            std::cout<<"CharTexture is not null";
        }
            texture = charTexture;//SDL_CreateTextureFromSurface(ren, surface);
//        }
    }


    void handleEvent(SDL_Event& e) {
        //If a key was pressed
        if( e.type == SDL_KEYDOWN)
        {
            //Adjust the velocity
            switch( e.key.keysym.sym )
            {
                case SDLK_LEFT: mPosX -= XVELOCITY; break;
                case SDLK_RIGHT: mPosX += XVELOCITY; break;
                case SDLK_UP: mPosY -= 20; break;
            }
        }
            //If a key was released
//        else if( e.type == SDL_KEYUP && e.key.repeat == 0 )
//        {
//            //Adjust the velocity
//            switch( e.key.keysym.sym )
//            {
//                case SDLK_UP: mVelY += DOT_VEL; break;
//                case SDLK_DOWN: mVelY -= DOT_VEL; break;
//                case SDLK_LEFT: mVelX += DOT_VEL; break;
//                case SDLK_RIGHT: mVelX -= DOT_VEL; break;
//            }
//        }
    }

    void move() {
        if ( mPosX + WIDTH > 2560 )
        {
            //Move back
            mPosX -= XVELOCITY;
        }
        if ( mPosX < 0) {
            mPosX +=XVELOCITY;
        }


//        mPosY += YVELOCITY; //gravity
    }

    void startFalling() {
        mPosY += YVELOCITY;
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
    int mPosX = 10;
    int mPosY = 100;
    static const int XVELOCITY = 5;
    static const int YVELOCITY = 2;
};
#endif //LAB5_PLATFORMER_CHARACTER_H
