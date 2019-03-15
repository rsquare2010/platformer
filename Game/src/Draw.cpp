//
// Created by Soumyadeep Sinha on 2019-03-11.
//

#include "../include/Draw.h"

void Draw::sketch(SDL_Renderer *renderer, SDL_Texture *tex, SDL_Rect dest) {


  SDL_RenderCopy(renderer, tex, NULL, &dest);

}
