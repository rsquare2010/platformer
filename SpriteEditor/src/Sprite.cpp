//
// Created by Rahul Ravindran on 2019-03-14.
//

#include "sprite.h"

/**
 * This is the constructor.
 * @param width the width.
 * @param height the height.
 * @param x the x coordinate.
 * @param y the y coordinate.
 * @param number the number.
 */
Sprite::Sprite(int width, int height, int x, int y, int number) {
  this->width = width;
  this->height = height;
  this->xPos = x;
  this->yPos = y;
  this->count = number;
  cout << "Everything is fine till here";
}

/**
 * This is the destructor.
 */
Sprite::~Sprite() {
  SDL_DestroyTexture(texture);
}

/**
 * This is to initialize the sprite object.
 * @param ren the renderer.
 */
void Sprite::init(SDL_Renderer *ren) {

  SDL_Surface *surface = (SDL_Surface *) ResourceManager::getInstance()->getValue("Sprite");
  if (surface==NULL) {
    cout << "Sprite was not loaded";
  } else {
    texture = SDL_CreateTextureFromSurface(ren, surface);
  }
  SDL_FreeSurface(surface);
  surface = NULL;
}

/**
 * This is to update the sprite object.
 * @param frame the frame rate.
 */
void Sprite::update(int frame) {
  currentFrame = frame%count;

  Src.x = xPos + (currentFrame*width);
  Src.y = yPos;
  Src.w = width;
  Src.h = height;

  Dest.x = 0;
  Dest.y = 0;
  Dest.w = width;
  Dest.h = height;
}

/**
 * This is to render the sprite object.
 * @param ren the renderer.
 */
void Sprite::render(SDL_Renderer *ren) {
  SDL_RenderCopy(ren, texture, &Src, &Dest);
}