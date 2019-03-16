//
// Created by Rahul Ravindran on 2019-01-20.
//

#ifndef PLATFORMER_SUNDAYS_ARE_FUNDAYS_FONTS_H
#define PLATFORMER_SUNDAYS_ARE_FUNDAYS_FONTS_H
#include <SDL_ttf.h>
#include <stdio.h>
#include <iostream>
using namespace std;
/**
 * This class is used to wrie text on screen.
 */
class Fonts {

 public:

  /**
   * This method is used to load the media file and handle error if there is an exception.
   */
  void loadMedia();
  /**
   * This method is used to render the text on the window.
   * @param renderer the Render pointer passed to render the text on the screen.
   * @param text  the actual text.
   * @param x the x coordinate of the text.
   * @param y the y coordinate of the text.
   */
  void renderText(SDL_Renderer *renderer, string text, int x, int y);


  /**
   * This method is used to create a texture from the surface.
   * @param renderer the renderer.
   * @param surf the surface.
   * @return the texture.
   */
  SDL_Texture *SurfaceToTexture(SDL_Renderer *renderer, SDL_Surface *surf);

  SDL_Rect *renderRect();

  TTF_Font *gFont;
  SDL_Texture *solidTexture;
};

#endif
