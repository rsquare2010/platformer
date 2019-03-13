//
// Created by Rahul Ravindran on 2019-03-07.
//

#ifndef LAB5_PLATFORMER_BACKGROUND1_H
#define LAB5_PLATFORMER_BACKGROUND1_H
class Background1{
public:

    Background1(){
    }


    ~Background1(){
        // TODO: Make sure spritesheet and texture are destroyed
        // but is this the right place?
        SDL_FreeSurface(spriteSheet);
        SDL_FreeSurface(spriteSheet2);
        SDL_FreeSurface(spriteSheet3);
        SDL_FreeSurface(spriteSheet4);
        SDL_FreeSurface(spriteSheet5);
        spriteSheet=NULL;
        spriteSheet2=NULL;
        spriteSheet3=NULL;
        spriteSheet4=NULL;
        spriteSheet5=NULL;
        SDL_DestroyTexture(texture);
        SDL_DestroyTexture(texture2);
        SDL_DestroyTexture(texture3);
        SDL_DestroyTexture(texture4);
        SDL_DestroyTexture(texture5);
    }

    // TODO: YUCK! Fix this common resource consumption error.
    void init(int x, int y, SDL_Renderer* ren){
        xPos = x;
        yPos = y;

        spriteSheet = SDL_LoadBMP("./1.bmp");
        spriteSheet2 = SDL_LoadBMP("./2.bmp");
        spriteSheet3 = SDL_LoadBMP("./3.bmp");
        spriteSheet4 = SDL_LoadBMP("./4.bmp");
        spriteSheet5 = SDL_LoadBMP("./5.bmp");
        if(spriteSheet==NULL || spriteSheet3 == NULL || spriteSheet4 == NULL){
            SDL_Log("Failed to allocate surface");
        }
        if(spriteSheet2==NULL || spriteSheet5 == NULL){
            SDL_Log("Failed to allocate surface");
        }else{
            SDL_Log("Allocated a bunch of memory to create identical game character");
//            width = spriteSheet->1280;
//            height = spriteSheet->720;
            // Create a texture from our surface
            // Textures run faster and take advantage of hardware acceleration
            texture = SDL_CreateTextureFromSurface(ren, spriteSheet);
            texture2 = SDL_CreateTextureFromSurface(ren, spriteSheet2);
            texture3 = SDL_CreateTextureFromSurface(ren, spriteSheet3);
            texture4 = SDL_CreateTextureFromSurface(ren, spriteSheet4);
            texture5 = SDL_CreateTextureFromSurface(ren, spriteSheet5);
        }
    }


    void update(){
        Dest.x = 0;
        Dest.y = 0;
        Dest.w = 1280;
        Dest.h = 720;
    }

    void render(int x, int y, SDL_Renderer* ren){
        Dest.x = -x * 0.1;
        SDL_RenderCopy(ren, texture, NULL, &Dest);
        SDL_RenderCopy(ren, texture2, NULL, &Dest);
        Dest.x = -x * 0.6;
        SDL_RenderCopy(ren, texture3, NULL, &Dest);
//        Dest.x = -x * 0.8;
//        SDL_RenderCopy(ren, texture4, NULL, &Dest);
        Dest.x = -x;
        SDL_RenderCopy(ren, texture5, NULL, &Dest);
//        Dest.x = -x + 1280;
        Dest.x = (-x * 0.1) + 1280;
        SDL_RenderCopy(ren, texture, NULL, &Dest);
//        Dest.x = (-x * 0.4) + 1280;
        SDL_RenderCopy(ren, texture2, NULL, &Dest);
        Dest.x = (-x * 0.6) + 1280;
        SDL_RenderCopy(ren, texture3, NULL, &Dest);
//        Dest.x = (-x * 0.8) + 1280;
//        SDL_RenderCopy(ren, texture4, NULL, &Dest);
        Dest.x = -x + 1280;
        SDL_RenderCopy(ren, texture5, NULL, &Dest);
    }


private:
    int xPos, yPos;
    int width, height;
    int scrollingOffset = 0;
//    unsigned int currentFrame{0};
//    unsigned int LastFrame{7};
    // An SDL Surface contains pixel data to draw an image
    SDL_Surface *spriteSheet;
    SDL_Surface *spriteSheet2;
    SDL_Surface *spriteSheet3;
    SDL_Surface *spriteSheet4;
    SDL_Surface *spriteSheet5;


    SDL_Texture *texture;
    SDL_Texture *texture2;
    SDL_Texture *texture3;
    SDL_Texture *texture4;
    SDL_Texture *texture5;

//    SDL_Rect Src;
    SDL_Rect Dest;
};

#endif //LAB5_PLATFORMER_BACKGROUND1_H
