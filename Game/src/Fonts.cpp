//
// Created by Rahul Ravindran on 2019-01-20.
//
#include <stdio.h>
#include <iostream>
#include "../include/Fonts.h"
#include "../include/ResourceManager.h"

/**
 * This method is used to load the media file and handle error if there is an exception.
 */
void Fonts::loadMedia() {


  ResourceManager *rmFont = ResourceManager::getInstance();
  //rmFont->musStartUp();


  if (TTF_Init()==-1) {
    printf("TTF_Init: %s\n", TTF_GetError());
    exit(2);
  }




  //Open the font
  gFont = (TTF_Font *) rmFont->getValue("Font");
  if (gFont==NULL) {
    printf("Failed to load font! SDL_ttf Error: %s\n", TTF_GetError());
  }
}

/**
 * This method is used to render the text on the window.
 * @param renderer the Render pointer passed to render the text on the screen.
 * @param text  the actual text.
 * @param x the x coordinate of the text.
 * @param y the y coordinate of the text.
 */
void Fonts::renderText(SDL_Renderer *renderer, string text, int x, int y) {

  SDL_Color textColor = {255, 255, 255};



  SDL_Surface *solid = TTF_RenderText_Solid(TTF_OpenFont("media/BEBAS.ttf", 20),text.c_str() , textColor);

  solidTexture = SurfaceToTexture(renderer, solid);

  SDL_Rect rect;
  rect.x = x;
  rect.y = y;



  int texW = 0;
  int texH = 0;



  SDL_QueryTexture(solidTexture, NULL, NULL, &texW, &texH);
  rect.w = texW + 10;
  rect.h = texH;



  SDL_RenderCopy(renderer, solidTexture, NULL, &rect);



}

/**
 * This method is used to create a texture from the surface.
 * @param renderer the renderer.
 * @param surf the surface.
 * @return the texture.
 */
SDL_Texture *Fonts::SurfaceToTexture(SDL_Renderer *renderer, SDL_Surface *surf) {
  SDL_Texture *text;

  text = SDL_CreateTextureFromSurface(renderer, surf);

  SDL_FreeSurface(surf);

  return text;
}